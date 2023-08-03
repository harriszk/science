// @file window_closed_event.h
// Created on 08/03/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _WINDOW_CLOSED_EVENT_H_
#define _WINDOW_CLOSED_EVENT_H_

#include "window_event.h"

class WindowClosedEvent : public WindowEvent {
  public:
    // Default constructor.
    WindowClosedEvent();

    // 
    // 
    // @return std::string 
    std::string ToString() const override;
};

#endif