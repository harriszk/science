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

    // Set the monitor width
    // 
    // @param[in] width 
    void set_monitor_width(int width) {
      monitor_width_ = width;
    }

    // Set the monitor height
    // 
    // @param[in] height 
    void set_monitor_height(int height) {
      monitor_height_ = height;
    }

    // Get the monitor width
    // 
    // @return int 
    int get_monitor_width() const {
      return monitor_width_;
    }

    // Get the monitor height
    // 
    // @return int 
    int get_monitor_height() const {
      return monitor_height_;
    }
  protected:
    // Default constructor.
    WindowEvent(EventType type);

    // 
    bool is_full_screen_;

    // 
    // 
    int monitor_width_;

    // 
    // 
    int monitor_height_;
};

#endif