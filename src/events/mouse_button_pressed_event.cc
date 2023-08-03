// @file mouse_button_pressed_event.cc
// Created on 08/02/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/mouse_button_pressed_event.h"

#include "utility.h"

MouseButtonPressedEvent::MouseButtonPressedEvent(MouseButton button)
    : MouseButtonEvent(button, EventType::MouseButtonPressedEvent) {

}

std::string MouseButtonPressedEvent::ToString() const {
  std::string output = std::string("MouseButtonPressedEvent: ") + MouseButtonToString(button_);
  
  return output;
}