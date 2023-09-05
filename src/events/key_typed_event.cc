// @file key_typed_event.cc
// Created on 09/04/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/key_typed_event.h"

KeyTypedEvent::KeyTypedEvent(KeyCode key_code)
    : KeyboardEvent(key_code, Modifier::None, EventType::KeyTyped) {

}

std::string KeyTypedEvent::ToString() const {
  std::string output = std::string("KeyTypedEvent: ") +
    "Key code = " + std::to_string(static_cast<int>(key_code_));
  
  return output;
}