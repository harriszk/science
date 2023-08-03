// @file key_released_event.cc
// Created on 08/02/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/key_released_event.h"

#include "utility.h"

KeyReleasedEvent::KeyReleasedEvent(KeyCode key_code, Modifier mod) 
    : KeyboardEvent(key_code, mod, EventType::KeyReleased) {

}

std::string KeyReleasedEvent::ToString() const {
  std::string output = std::string("KeyReleasedEvent: ") +
    "Key code = " + std::to_string(static_cast<int>(key_code_)) +
    " (" + KeyCodeToString(key_code_) + "), " +
    "Modifier = " + std::to_string(static_cast<int>(modifier_));
  
  return output;
}