// @file mouse_moved_event.h
// Created on 08/01/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _MOUSE_MOVED_EVENT_H_
#define _MOUSE_MOVED_EVENT_H_

#include "mouse_event.h"

class MouseMovedEvent : public MouseEvent {
  public:
    // Default constructor.
    MouseMovedEvent(float x, float y);

    // Get the x
    // 
    // @return float 
    float get_x();

    // Get the y
    // 
    // @return float 
    float get_y();

    // 
    // 
    // @return std::string 
    std::string ToString() const override;
  private:
    // 
    float x_;

    // 
    float y_;
};

#endif