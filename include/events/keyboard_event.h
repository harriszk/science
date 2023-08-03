// @file keyboard_event.h
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _KEYBOARD_EVENT_H_
#define _KEYBOARD_EVENT_H_

#include "event.h"
#include "key_code.h"
#include "modifier.h"

class KeyboardEvent : public Event {
  public:
    // Get the key code
    // 
    // @return KeyCode 
    KeyCode get_key_code();

    // Get the modifier
    // 
    // @return Modifier 
    Modifier get_modifier();
  
  protected:
    // Default constructor.
    KeyboardEvent(KeyCode key_code, Modifier modifier, EventType type);

    // 
    KeyCode key_code_;

    // 
    Modifier modifier_;
};

#endif