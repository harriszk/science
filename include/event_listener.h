// @file event_listener.h
// Created on 08/11/2023
// 
// Abstract base class for event listeners. It defines an interface for classes
// that need to respond to application events. Any class that wants to listen
// for and react to events must implement this interface by providing an
// implementation for the OnEvent method.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _EVENT_LISTENER_H_
#define _EVENT_LISTENER_H_

#include "events/event.h"

class EventListener {
  public:
    // Virtual method to handle events.
    // 
    // @param[in] event The event to be handled.
    virtual void OnEvent(const Event& event) = 0;
};

#endif