#ifndef __TC_EVENT_HPP__
#define __TC_EVENT_HPP__

#include "defines.hpp"
#include "object.hpp"

namespace TerreateCore::Event {
using namespace TerreateCore::Core;
using namespace TerreateCore::Defines;

using EventCallback = Function<void(Str const &)>;

class EventSystem : public Object {
private:
  Queue<Str> mEventQueue;
  Mutex mQueueMutex;
  Map<Str, Vec<EventCallback>> mCallbacks;
  Map<Str, Queue<EventCallback>> mTriggers;

public:
  /*
   * @brief: Eventsystem is a event driven system that allows for
   * callbacks to be registered to events and for events
   * to be published to the system.
   */
  EventSystem() {}
  virtual ~EventSystem() override = default;

  /*
   * @brief: Register a callback to an event
   * @param: event: the event to register to
   * @param: callback: the callback to register
   */
  void Register(Str const &event, EventCallback const &callback);
  /*
   * @brief: Register a trigger to an event. A trigger is a callback
   * that is only called once and then removed from the event.
   * @param: event: the event to register to
   * @param: callback: the callback to register
   */
  void AddTrigger(Str const &event, EventCallback const &callback);

  /*
   * @brief: Process all events in the queue. This function is thread safe.
   */
  void ProcessEvents();
  /*
   * @brief: Publish an event to the system. This function is thread safe.
   * @param: event: the event to publish
   */
  void PublishEvent(Str const &event);
};
} // namespace TerreateCore::Event

#endif // __TC_EVENT_HPP__
