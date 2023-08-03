// @file mouse_scrolled_event.h
// Created on 08/01/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _MOUSE_SCROLLED_EVENT_H_
#define _MOUSE_SCROLLED_EVENT_H_

#include "mouse_event.h"

class MouseScrolledEvent : public MouseEvent {
  public:
    // Default constructor.
    MouseScrolledEvent(float dy);

    // Get the dy
    // 
    // @return float 
    float get_dy();

    // 
    // 
    // @return std::string 
    std::string ToString() const override;
  private:
    // 
    float dy_;
};

#endif