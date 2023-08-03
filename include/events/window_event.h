// @file window_event.h
// Created on 08/01/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _WINDOW_EVENT_H_
#define _WINDOW_EVENT_H_

#include "event.h"

class WindowEvent : public Event {
  public:
    // 
    bool IsFullScreen();

  protected:
    // 
    bool is_full_screen_;
};

#endif