// @file mouse_button_event.h
// Created on 08/01/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _MOUSE_BUTTON_EVENT_H_
#define _MOUSE_BUTTON_EVENT_H_

#include "mouse_event.h"

enum MouseButton {
  MOUSE_LEFT = 1,
  MOUSE_RIGHT = 2
};

class MouseButtonEvent : public MouseEvent {
  public:
    // Get the button
    // 
    // @return MouseButton 
    MouseButton get_button();

  protected:
    // Default constructor
    MouseButtonEvent(MouseButton button, EventType type);

    // 
    MouseButton button_;
};

#endif