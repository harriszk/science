// @file event.h
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _EVENT_H_
#define _EVENT_H_

#include <string>

enum class EventType {
  None = 0,
  KeyPressedEvent,
  KeyReleasedEvent,
  MouseMovedEvent,
  MouseScrolledEvent,
  MouseButtonPressedEvent,
  MouseButtonReleasedEvent,
  WindowResizedEvent,
  WindowClosedEvent,
  WindowMovedEvent,
  WindowMinimizedEvent,
  WindowFocusChangedEvent
};

enum class EventCategory {
  None = 0,
  KeyboardEvent,
  MouseEvent,
  GUIEvent,
  WindowEvent
};

class Event {
  public:
    // 
    // 
    // @return true 
    // @return false 
    bool IsHandled() {
      return handled_;
    }

    // Set the handled
    // 
    void set_handled() {
      handled_ = true;
    }

    // Get the event type
    // 
    // @return EventType 
    //virtual EventType get_event_type() = 0;

    // Get the event category
    // 
    // @return EventCategory 
    //virtual EventCategory get_event_category() = 0;

    // 
    // 
    // @return std::string 
    virtual std::string ToString() const = 0;
  protected:
    // Default constructor
    Event(EventType type, EventCategory category)
        : type_(type), category_(category) {

    }

    // 
    EventType type_;

    // 
    EventCategory category_{};

    // 
    bool handled_ = false;
};

#endif