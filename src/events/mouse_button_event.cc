// @file mouse_button_event.cc
// Created on 08/02/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "events/mouse_button_event.h"

MouseButtonEvent::MouseButtonEvent(MouseButton button, EventType type)
    : MouseEvent(Modifier::None, type),
      button_(button) {

}

MouseButton MouseButtonEvent::get_button() {
  return button_;
}