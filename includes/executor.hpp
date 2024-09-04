#ifndef __TERREATECORE_EXECUTOR_HPP__
#define __TERREATECORE_EXECUTOR_HPP__

#include "defines.hpp"
#include "object.hpp"

namespace TerreateCore::Utils {
using namespace TerreateCore::Defines;

class TaskHandle : public Core::TerreateObjectBase {
private:
  SharedFuture<void> mFuture;
  Uint mExecutionIndex = 0u;

public:
  TaskHandle() {}
  TaskHandle(SharedFuture<void> const &future) : mFuture(future) {}
  ~TaskHandle() override {}

  Uint const &GetExecutionIndex() const { return mExecutionIndex; }

  void SetExecutionIndex(Uint const &index) { mExecutionIndex = index; }

  void Wait() const;
};

class Task : public Core::TerreateObjectBase {
private:
  PackagedTask<void()> mTarget;
  Vec<TaskHandle *> mDependencies;
  TaskHandle *mHandle = nullptr;

private:
  Task(Task const &other) = delete;
  Task &operator=(Task const &other) = delete;

public:
  Task() {}
  Task(Function<void()> const &target) : mTarget(target) {
    mHandle = new TaskHandle(mTarget.get_future().share());
  }
  Task(Task &&other) noexcept
      : mTarget(std::move(other.mTarget)),
        mDependencies(std::move(other.mDependencies)), mHandle(other.mHandle) {
    other.mHandle = nullptr;
  }
  ~Task() override;

  TaskHandle *GetHandle() { return mHandle; }
  TaskHandle const *GetHandle() const { return mHandle; }

  void AddDependency(TaskHandle *dependency);
  void AddDependencies(Vec<TaskHandle *> const &dependencies);
  void Invoke();

  Task &operator=(Task &&other) noexcept;
};

class Executor : public Core::TerreateObjectBase {
private:
  Queue<Task> mTaskQueue;
  Mutex mQueueMutex;

  Vec<Thread> mWorkers;
  ConditionVariable mCV;

  Atomic<Uint> mNumJobs = 0u;
  Atomic<Bool> mComplete = false;
  Atomic<Bool> mStop = false;

private:
  void Worker();

public:
  explicit Executor(
      Uint const &numWorkers = std::thread::hardware_concurrency());
  ~Executor() override;

  void Schedule(Task &&task);

  void WaitForAll() const { mComplete.wait(false); }
};
} // namespace TerreateCore::Utils

#endif // __TERREATECORE_EXECUTOR_HPP__
