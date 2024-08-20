#include "../includes/executor.hpp"
#include "../includes/exceptions.hpp"

namespace TerreateCore::Executor {
using namespace TerreateCore::Defines;

namespace Utils {
Str CreateJobTimeLine(Vec<JobStamp> const &jobStamps,
                      SteadyTimePoint const &start,
                      SteadyTimePoint const &end) {
  Uint duration = DurationCast<MilliSec>(end - start).count() / 10;
  Str result(duration, ' ');

  for (auto const &data : jobStamps) {
    auto begin = result.begin();
    Uint jobStart = DurationCast<MilliSec>(data.start - start).count() / 10;
    Uint jobEnd = DurationCast<MilliSec>(data.end - start).count() / 10;
    std::fill(begin + jobStart, begin + jobEnd, data.id);
  }
  return result;
}
} // namespace Utils

void TaskHandle::Wait() const {
  if (mFuture.valid()) {
    mFuture.wait();
  }
}

TaskHandle &TaskHandle::operator=(TaskHandle const &other) {
  mFuture = other.mFuture;
  mExecutionPriority = other.mExecutionPriority;
  return *this;
}

TaskHandle &TaskHandle::operator=(TaskHandle &&other) noexcept {
  mFuture = std::move(other.mFuture);
  mExecutionPriority = other.mExecutionPriority;
  return *this;
}

Task::Task(Function<void()> &&task, Uint const &priority) {
  mTask = PackagedTask<void()>(std::move(task));
  mHandle = TaskHandle(mTask.get_future().share(), priority);
}

Task::Task(PackagedTask<void()> &&task, Uint const &priority) {
  mTask = std::move(task);
  mHandle = TaskHandle(mTask.get_future().share(), priority);
}

void Task::AddDependency(TaskHandle *dependency) {
  if (dependency->GetPriority() > mHandle.GetPriority()) {
    throw Exceptions::ExecutorError(
        "Dependency priority must be less than task priority.");
  }

  mDependencies.push_back(dependency);
  mHandle.SetPriority(
      std::max(mHandle.GetPriority(), dependency->GetPriority() + 1));
}

void Task::Invoke() {
  for (auto const &dependency : mDependencies) {
    dependency->Wait();
  }

  mTask();
}

Task &Task::operator=(Function<void()> &&task) {
  mTask = PackagedTask<void()>(std::move(task));
  mHandle.SetFuture(mTask.get_future().share());
  return *this;
}

Task &Task::operator=(PackagedTask<void()> &&task) {
  mTask = std::move(task);
  mHandle.SetFuture(mTask.get_future().share());
  return *this;
}

Task &Task::operator=(Task &&other) noexcept {
  mHandle = std::move(other.mHandle);
  mDependencies = std::move(other.mDependencies);
  mTask = std::move(other.mTask);
  return *this;
}

void Executor::Worker() {
  while (true) {
    Task task;
    {
      UniqueLock<Mutex> lock(mQueueMutex);
      mCV.wait(lock, [this] { return !mTaskQueue.empty() || mStop; });

      if (mStop && mTaskQueue.empty()) {
        return;
      }

      task = std::move(mTaskQueue.front());
      mTaskQueue.pop();
    }
    task.Invoke();

    if (mNumJobs.fetch_sub(1) == 1) {
      mComplete.store(true);
      mComplete.notify_all();
    }
  }
}

Executor::Executor(Uint const &numWorkers) {
  if (numWorkers == 0) {
    throw Exceptions::ExecutorError(
        "Number of workers must be greater than 0.");
  }

  for (Uint i = 0; i < numWorkers; ++i) {
    mWorkers.emplace_back(&Executor::Worker, this);
  }
}

Executor::~Executor() {
  {
    std::lock_guard<std::mutex> lock(mQueueMutex);
    mStop.store(true);
  }
  mCV.notify_all();

  for (auto &worker : mWorkers) {
    if (worker.joinable()) {
      worker.join();
    }
  }
}

Task &Executor::Schedule(Function<void()> &&task) {
  {
    std::lock_guard<std::mutex> lock(mQueueMutex);
    mTaskQueue.push(Task(std::move(task)));
    mNumJobs.fetch_add(1);
    mComplete.store(false);
  }
  mCV.notify_one();

  return mTaskQueue.back();
}

Task &Executor::Schedule(Uint const &splitCount, Function<void(Uint)> &&task) {
  Vec<TaskHandle *> handles;
  {
    std::lock_guard<std::mutex> lock(mQueueMutex);
    for (Uint i = 0; i < splitCount; ++i) {
      Task t = Task([task, i, splitCount] { task(i); });
      mTaskQueue.push(std::move(t));
      mNumJobs.fetch_add(1);
      handles.push_back(mTaskQueue.back().GetHandle());
    }

    Task dummy = Task([] {});
    for (auto const &handle : handles) {
      dummy.AddDependency(handle);
    }
    mTaskQueue.push(std::move(dummy));

    mNumJobs.fetch_add(1);
    mComplete.store(false);
  }
  mCV.notify_one();

  return mTaskQueue.back();
}

} // namespace TerreateCore::Executor
