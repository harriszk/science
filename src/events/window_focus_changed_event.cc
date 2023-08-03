// @file window_focus_changed_event.cc
// Created on 08/03/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/window_focus_changed_event.h"

WindowFocusChangedEvent::WindowFocusChangedEvent(WindowFocusChangeType focus_type)
    : WindowEvent(EventType::WindowFocusChanged),
      focus_type_(focus_type) {

}

WindowFocusChangeType WindowFocusChangedEvent::get_focus_type() {
  return focus_type_;
}


std::string WindowFocusChangedEvent::ToString() const {
  std::string output = std::string("WindowFocusChangedEvent: ");

  return output;
}