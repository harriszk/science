// @file window_resized_event.h
// Created on 08/03/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _WINDOW_RESIZED_EVENT_H_
#define _WINDOW_RESIZED_EVENT_H_

#include "window_event.h"

class WindowResizedEvent : public WindowEvent {
  public:
    // Default constructor.
    // 
    // @param[in] width 
    // @param[in] height 
    WindowResizedEvent(int width, int height);

    // Get the width
    // 
    // @return int 
    int get_width() const;

    // Get the height
    // 
    // @return int 
    int get_height() const;

    // 
    // 
    // @return std::string 
    std::string ToString() const override;
  private:
    // 
    int width_;

    // 
    int height_;
};

#endif