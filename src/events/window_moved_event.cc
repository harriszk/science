// @file window_moved_event.cc
// Created on 08/03/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/window_moved_event.h"

WindowMovedEvent::WindowMovedEvent(float x, float y) 
    : WindowEvent(EventType::WindowMoved),
      x_(x),
      y_(y) {

}

float WindowMovedEvent::get_x() const {
  return x_;
}

float WindowMovedEvent::get_y() const {
  return y_;
}

std::string WindowMovedEvent::ToString() const {
  std::string output = std::string("WindowMovedEvent: ") + "(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";

  return output;
}