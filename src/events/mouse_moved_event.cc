// @file mouse_moved_event.cc
// Created on 08/02/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/mouse_moved_event.h"

MouseMovedEvent::MouseMovedEvent(float x, float y)
    : MouseEvent(Modifier::None, EventType::MouseMovedEvent), 
      x_(x), 
      y_(y) {

}

float MouseMovedEvent::get_x() {
  return x_;
}

float MouseMovedEvent::get_y() {
  return y_;
}

std::string MouseMovedEvent::ToString() const {
  std::string output = std::string("MouseMovedEvent: ") + "(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
  
  return output;
}