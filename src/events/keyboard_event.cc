// @file keyboard_event.cc
// Created on 08/02/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/keyboard_event.h"

KeyboardEvent::KeyboardEvent(KeyCode key_code, Modifier modifier, EventType type)
    : Event(type, EventCategory::Keyboard),
      key_code_(key_code),
      modifier_(modifier) {

}

KeyCode KeyboardEvent::get_key_code() {
  return key_code_;
}

Modifier KeyboardEvent::get_modifier() {
  return modifier_;
}