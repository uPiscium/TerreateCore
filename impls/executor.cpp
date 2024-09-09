#include "../includes/executor.hpp"
#include "../includes/exceptions.hpp"

namespace TerreateCore::Utils {
using namespace TerreateCore::Defines;

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

    task();

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

Vec<ExceptionPtr> Executor::GetExceptions() const {
  Vec<ExceptionPtr> exceptions;
  for (auto &handle : mHandles) {
    if (handle.valid()) {
      try {
        handle.get();
      } catch (std::exception const &e) {
        exceptions.push_back(std::current_exception());
      }
    }
  }
  return exceptions;
}

Handle Executor::Schedule(Runnable const &target) {
  Task wrapper([target]() {
    try {
      target();
    } catch (std::exception const &e) {
      Str msg = "Task failed with an exception '" + Str(e.what()) + "'.";
      throw Exceptions::ExecutorError(msg);
    }
  });
  Handle future = wrapper.get_future().share();
  mHandles.push_back(future);

  {
    LockGuard<Mutex> lock(mQueueMutex);
    mTaskQueue.push(std::move(wrapper));
    mNumJobs.fetch_add(1);
    mComplete.store(false);
  }
  mCV.notify_one();

  return future;
}

Handle Executor::Schedule(Runnable const &target,
                          Vec<Handle> const &dependencies) {
  auto wrapper = ([target, dependencies]() {
    for (auto const &dependency : dependencies) {
      if (dependency.valid()) {
        dependency.wait();
      }
    }
    target();
  });
  return this->Schedule(wrapper);
}
} // namespace TerreateCore::Utils
