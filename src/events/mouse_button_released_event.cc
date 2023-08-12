// @file mouse_button_released_event.cc
// Created on 08/02/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/mouse_button_released_event.h"

#include "utility.h"

MouseButtonReleasedEvent::MouseButtonReleasedEvent(MouseButton button, Modifier modifier)
    : MouseButtonEvent(button, modifier, EventType::MouseButtonReleased) {

}

std::string MouseButtonReleasedEvent::ToString() const {
  std::string output = std::string("MouseButtonReleasedEvent: ") + MouseButtonToString(button_) + 
  ", Modifier = " + ModifierToString(modifier_);;
  
  return output;
}