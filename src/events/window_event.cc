// @file window_event.cc
// Created on 08/03/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/window_event.h"

WindowEvent::WindowEvent(EventType type) 
    : Event(type, EventCategory::Window),
      is_full_screen_(false) {

}

bool WindowEvent::IsFullScreen() {
  return is_full_screen_;
}