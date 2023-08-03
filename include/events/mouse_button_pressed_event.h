// @file mouse_button_pressed_event.h
// Created on 08/01/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _MOUSE_BUTTON_PRESSED_EVENT_H_
#define _MOUSE_BUTTON_PRESSED_EVENT_H_

#include "mouse_button_event.h"

class MouseButtonPressedEvent : public MouseButtonEvent {
  public:
    // Default constructor.
    MouseButtonPressedEvent(MouseButton button);

    // 
    // 
    // @return std::string 
    std::string ToString() const override;
};

#endif