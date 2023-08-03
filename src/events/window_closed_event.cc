// @file window_closed_event.cc
// Created on 08/03/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/window_closed_event.h"

WindowClosedEvent::WindowClosedEvent() : WindowEvent(EventType::WindowClosed) {

}

std::string WindowClosedEvent::ToString() const {
  std::string output = std::string("WindowClosedEvent:");

  return output;
}