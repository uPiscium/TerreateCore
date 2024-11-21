#ifndef __TERREATECORE_EVENT_HPP__
#define __TERREATECORE_EVENT_HPP__

#include "defines.hpp"
#include "object.hpp"

namespace TerreateCore::Utils {
using namespace TerreateCore::Defines;

template <typename... EventArgs>
class Event final : public Core::TerreateObjectBase {
public:
  using Callback = Function<void(EventArgs...)>;

private:
  Mutex mEventMutex;
  Vec<Callback> mCallbacks;
  Vec<Callback> mTriggers;

public:
  Event() = default;
  ~Event() override = default;

  /*
   * @brief: Subscribe to the event
   * @param: subscriber: Callback function to be called when the event is
   */
  void Subscribe(Callback subscriber) {
    LockGuard<Mutex> lock(mEventMutex);
    mCallbacks.push_back(subscriber);
  }
  /*
   * @brief: Unsubscribe from the event
   * @param: callback: Callback function to be removed from the event
   */
  void Unsubscribe(Callback callback) {
    UniqueLock<Mutex> lock(mEventMutex);
    mCallbacks.erase(
        std::remove(mCallbacks.begin(), mCallbacks.end(), callback),
        mCallbacks.end());
  }

  /*
   * @brief: Publish the event
   * @param: args: Arguments to be passed to the callback functions
   */
  void Publish(EventArgs... args) {
    UniqueLock<Mutex> lock(mEventMutex);
    for (auto &callback : mCallbacks) {
      callback(std::forward<EventArgs>(args)...);
    }
    for (auto &callback : mTriggers) {
      callback(std::forward<EventArgs>(args)...);
    }
  }

  Event &operator+=(Callback callback) {
    this->Subscribe(callback);
    return *this;
  }
  Event &operator-=(Callback callback) {
    this->Unsubscribe(callback);
    return *this;
  }
};
} // namespace TerreateCore::Utils

#endif // __TERREATECORE_EVENT_HPP__
