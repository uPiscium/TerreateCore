#ifndef __TERREATECORE_EXECUTOR_HPP__
#define __TERREATECORE_EXECUTOR_HPP__

#include "defines.hpp"
#include "object.hpp"

namespace TerreateCore::Executor {
using namespace TerreateCore::Defines;

namespace Utils {
struct JobStamp {
  Uint id;
  SteadyTimePoint start;
  SteadyTimePoint end;
};

Str CreateJobTimeLine(Vec<JobStamp> const &jobStamps,
                      SteadyTimePoint const &start, SteadyTimePoint const &end);
} // namespace Utils

class TaskHandle : public Core::TerreateObjectBase {
private:
  Future mFuture;
  Uint mExecutionPriority = 0u;

public:
  TaskHandle() {}
  TaskHandle(Future &&future, Uint const &executionPriority = 0u)
      : mFuture(std::move(future)), mExecutionPriority(executionPriority) {}
  TaskHandle(TaskHandle const &other)
      : mFuture(other.mFuture), mExecutionPriority(other.mExecutionPriority) {}
  TaskHandle(TaskHandle &&other) noexcept
      : mFuture(std::move(other.mFuture)),
        mExecutionPriority(other.mExecutionPriority) {}
  ~TaskHandle() override = default;

  Uint const &GetPriority() const { return mExecutionPriority; }

  void SetFuture(Future &&future) { mFuture = std::move(future); }
  void SetPriority(Uint const &priority) { mExecutionPriority = priority; }

  void Wait() const;

  TaskHandle &operator=(TaskHandle const &other);
  TaskHandle &operator=(TaskHandle &&other) noexcept;
};

class Task final : public Core::TerreateObjectBase {
private:
  TaskHandle mHandle;
  Vec<TaskHandle *> mDependencies;
  PackagedTask<void()> mTask;

public:
  Task() = default;
  Task(Function<void()> &&task, Uint const &priority = 0u);
  Task(PackagedTask<void()> &&task, Uint const &priority = 0u);
  Task(Task &&other) noexcept
      : mHandle(std::move(other.mHandle)),
        mDependencies(std::move(other.mDependencies)),
        mTask(std::move(other.mTask)) {}
  ~Task() override = default;

  TaskHandle *GetHandle() { return &mHandle; }
  TaskHandle const *GetHandle() const { return &mHandle; }

  void SetHandle(TaskHandle &&handle) { mHandle = std::move(handle); }

  void AddDependency(TaskHandle *dependency);
  void Invoke();

  Task &operator=(Function<void()> &&task);
  Task &operator=(PackagedTask<void()> &&task);
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

  Task &Schedule(Function<void()> &&task);
  Task &Schedule(Uint const &splitCount, Function<void(Uint)> &&task);
  void WaitForAll() const { mComplete.wait(false); }
};
} // namespace TerreateCore::Executor

#endif // __TERREATECORE_EXECUTOR_HPP__
