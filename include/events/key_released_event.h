// @file key_released_event.h
// Created on 08/01/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _KEY_RELEASED_EVENT_H_
#define _KEY_RELEASED_EVENT_H_

#include "keyboard_event.h"

class KeyReleasedEvent : public KeyboardEvent {
  public:
    // Default constructor.
    KeyReleasedEvent(KeyCode key_code);

    // 
    // 
    // @return std::string 
    std::string ToString() const override;
};

#endif