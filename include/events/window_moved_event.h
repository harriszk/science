// @file window_moved_event.h
// Created on 08/03/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _WINDOW_MOVED_EVENT_H_
#define _WINDOW_MOVED_EVENT_H_

#include "window_event.h"

class WindowMovedEvent : public WindowEvent {
  public:
    // Default constructor.
    // 
    // @param[in] x 
    // @param[in] y 
    WindowMovedEvent(float x, float y);

    // Get the x
    // 
    // @return float 
    float get_x() const;

    // Get the y
    // 
    // @return float 
    float get_y() const;

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