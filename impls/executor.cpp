#include "../includes/executor.hpp"
#include "../includes/exceptions.hpp"

#include <iostream>

namespace TerreateCore::Utils {
using namespace TerreateCore::Defines;

void TaskHandle::Wait() const {
  if (mFuture.valid()) {
    mFuture.wait();
  }
}

Task::~Task() {
  if (mHandle != nullptr) {
    delete mHandle;
    mHandle = nullptr;
  }
}

void Task::AddDependency(TaskHandle *dependency) {
  Uint index = mHandle->GetExecutionIndex();
  Uint depIndex = dependency->GetExecutionIndex();

  if (depIndex > index) {
    throw Exceptions::ExecutorError(
        "Dependency index must be less than or equal to the current task.");
  }

  mHandle->SetExecutionIndex(std::max(index, depIndex + 1));
  mDependencies.push_back(dependency);
}

void Task::AddDependencies(Vec<TaskHandle *> const &dependencies) {
  for (auto const &dependency : dependencies) {
    this->AddDependency(dependency);
  }
}

void Task::Invoke() {
  for (auto const &dependency : mDependencies) {
    if (dependency != nullptr) {
      dependency->Wait();
    }
  }
  mTarget();
}

Task &Task::operator=(Task &&other) noexcept {
  if (this != &other) {
    mTarget = std::move(other.mTarget);
    mDependencies = std::move(other.mDependencies);
    mHandle = other.mHandle;
    other.mHandle = nullptr;
  }
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
    LockGuard<Mutex> lock(mQueueMutex);
    mStop.store(true);
  }
  mCV.notify_all();

  for (auto &worker : mWorkers) {
    if (worker.joinable()) {
      worker.join();
    }
  }
}

void Executor::Schedule(Task &&task) {
  {
    LockGuard<Mutex> lock(mQueueMutex);
    mTaskQueue.push(std::move(task));
    mNumJobs.fetch_add(1);
    mComplete.store(false);
  }
  mCV.notify_one();
}

} // namespace TerreateCore::Utils
