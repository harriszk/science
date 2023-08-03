// @file mouse_event.cc
// Created on 08/02/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/mouse_event.h"

MouseEvent::MouseEvent(Modifier modifier, EventType type) 
    : Event(type, EventCategory::Mouse),
      modifier_(modifier) {

}

Modifier MouseEvent::get_modifier() {
  return modifier_;
}