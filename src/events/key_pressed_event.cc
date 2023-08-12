// @file key_pressed_event.cc
// Created on 08/02/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/key_pressed_event.h"

#include "utility.h"

KeyPressedEvent::KeyPressedEvent(KeyCode key_code, Modifier mod, bool is_repeat)
    : KeyboardEvent(key_code, mod, EventType::KeyPressed),
      is_repeat_(is_repeat) {
}

bool KeyPressedEvent::IsRepeat() {
  return is_repeat_;
}

std::string KeyPressedEvent::ToString() const {
  std::string output = std::string("KeyPressedEvent: ") +
    "Key code = " + std::to_string(static_cast<int>(key_code_)) +
    " (" + KeyCodeToString(key_code_) + "), " +
    "Is Repeat = " + std::to_string(static_cast<bool>(is_repeat_)) + ", " +
    "Modifier = " + ModifierToString(modifier_);
  
  return output;
}