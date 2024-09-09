#ifndef __TERREATECORE_EXECUTOR_HPP__
#define __TERREATECORE_EXECUTOR_HPP__

#include "defines.hpp"
#include "object.hpp"

namespace TerreateCore::Utils {
using namespace TerreateCore::Defines;

typedef Function<void()> Runnable;

class Executor : public Core::TerreateObjectBase {
private:
  Vec<Handle> mHandles;
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

  Vec<ExceptionPtr> GetExceptions() const;

  Handle Schedule(Runnable const &target);
  Handle Schedule(Runnable const &target, Vec<Handle> const &dependencies);

  void WaitForAll() const { mComplete.wait(false); }
};
} // namespace TerreateCore::Utils

#endif // __TERREATECORE_EXECUTOR_HPP__
