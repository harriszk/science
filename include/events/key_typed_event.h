// @file key_typed_event.h
// Created on 09/04/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _KEY_TYPED_EVENT_H_
#define _KEY_TYPED_EVENT_H_

#include "keyboard_event.h"

class KeyTypedEvent : public KeyboardEvent {
  public:
    // Default constructor.
    KeyTypedEvent(KeyCode key_code);

    // 
    // 
    // @return std::string 
    std::string ToString() const override;
};

#endif