// @file window_resized_event.cc
// Created on 08/03/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/window_resized_event.h"

WindowResizedEvent::WindowResizedEvent(int width, int height)
    : WindowEvent(EventType::WindowResized),
      width_(width),
      height_(height) {

}

int WindowResizedEvent::get_width() const {
  return width_;
}

int WindowResizedEvent::get_height() const {
  return height_;
}

std::string WindowResizedEvent::ToString() const {
  std::string output = std::string("WindowResizedEvent: ") + "(" + std::to_string(width_) + ", " + std::to_string(height_) + ")";

  return output;
}