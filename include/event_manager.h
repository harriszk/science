// @file event_manager.h
// Created on 08/10/2023
// 
// This class manages event subscription and dispatching. It is responsible for
// subscribing listeners to specific event types, unsubscribing listeners, and
// dispatching events to registered listeners.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _EVENT_MANAGER_H_
#define _EVENT_MANAGER_H_

#include <vector>
#include <typeindex>
#include <unordered_map>

#include "event_listener.h"
#include "events/event.h"

class EventManager {
  public:
    // Copy constructor (disabled).
    EventManager(const EventManager& manager) = delete;

    // Get a pointer to the EventManager instance.
    // 
    // @return EventManager* 
    static EventManager* Get();

    // Subscribe an event listener to a specific event type.
    // 
    // @param[in] observer The event listener.
    // @param[in] type The type of event.
    // @return true if the subscription is successful.
    // @return false otherwise.
    bool Subscribe(EventListener* observer, EventType type);

    // Unsubscribe an event listener from a specific event type.
    // 
    // @param[in] observer The event listener.
    // @param[in] type The type of event.
    // @return true if the unsubscription is successful.
    // @return false otherwise.
    bool Unsubscribe(EventListener* observer, EventType type);

    // Unsubscribe all event listeners from all event types.
    // 
    // @return true if all listeners are successfully unsubscribed.
    // @return false otherwise.
    bool UnsubscribeAll();

    // Dispatch an event to all registered listeners of the corresponding event
    // type.
    // 
    // @param[in] event The event to be dispatched.
    void Dispatch(const Event& event);
  private:
    // Default constructor.
    EventManager();

    // Destructor.
    ~EventManager();

    // Pointer to the singleton instance of EventManager.
    static EventManager* instance_;

    // Mapping of event types to registered event listeners.
    std::unordered_map<EventType, std::vector<EventListener*>> listeners_;
};

#endif