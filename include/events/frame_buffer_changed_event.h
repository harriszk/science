// @file frame_buffer_changed_event.h
// Created on 09/08/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _FRAME_BUFFER_CHANGED_EVENT_H_
#define _FRAME_BUFFER_CHANGED_EVENT_H_

#include "window_event.h"

class FrameBufferChangedEvent : public WindowEvent {
  public:
    // Default constructor.
    // 
    // @param[in] width 
    // @param[in] height 
    FrameBufferChangedEvent(float width, float height);

    // Get the width
    // 
    // @return float 
    float get_width() const;

    // Get the height
    // 
    // @return float 
    float get_height() const;

    // 
    // 
    // @return std::string 
    std::string ToString() const override;
  private:
    // 
    // 
    float width_;

    // 
    // 
    float height_;
};

#endif