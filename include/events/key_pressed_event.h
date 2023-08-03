// @file key_pressed_event.h
// Created on 08/01/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _KEY_PRESSED_EVENT_H_
#define _KEY_PRESSED_EVENT_H_

#include "keyboard_event.h"

class KeyPressedEvent : public KeyboardEvent {
  public:
    // Default constructor.
    KeyPressedEvent(KeyCode key_code, Modifier mod, bool is_repeat);

    // 
    // 
    // @return true 
    // @return false 
    bool IsRepeat();

    // 
    // 
    // @return std::string 
    std::string ToString() const override;
  private:
    // 
    bool is_repeat_;
};

#endif