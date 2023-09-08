// @file frame_buffer_changed_event.cc
// Created on 09/08/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/frame_buffer_changed_event.h"

FrameBufferChangedEvent::FrameBufferChangedEvent(float width, float height)
    : WindowEvent(EventType::FrameBufferChanged),
      width_(width), 
      height_(height) {

}

float FrameBufferChangedEvent::get_width() const {
  return width_;
}

float FrameBufferChangedEvent::get_height() const {
  return height_;
}

std::string FrameBufferChangedEvent::ToString() const {
  std::string output = std::string("FrameBufferChangedEvent: ") + "(" + std::to_string(width_) + ", " + std::to_string(height_) + ")";

  return output;
}