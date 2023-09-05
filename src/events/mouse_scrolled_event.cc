// @file mouse_scrolled_event.cc
// Created on 08/02/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/mouse_scrolled_event.h"

MouseScrolledEvent::MouseScrolledEvent(float dy)
    : MouseEvent(Modifier::None, EventType::MouseScrolled),
      dy_(dy) {

}

float MouseScrolledEvent::get_dy() const {
  return dy_;
}

std::string MouseScrolledEvent::ToString() const {
  std::string output = std::string("MouseScrolledEvent: ") + std::to_string(dy_);
  
  return output;
}