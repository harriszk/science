// @file mouse_button_released_event.h
// Created on 08/01/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _MOUSE_BUTTON_RELEASED_EVENT_H_
#define _MOUSE_BUTTON_RELEASED_EVENT_H_

#include "mouse_button_event.h"

class MouseButtonReleasedEvent : public MouseButtonEvent {
  public:
    // Default constructor.
    MouseButtonReleasedEvent(MouseButton button, Modifier modifier);

    // 
    // 
    // @return std::string 
    std::string ToString() const override;
};

#endif