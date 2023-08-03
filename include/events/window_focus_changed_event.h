// @file window_focus_changed_event.h
// Created on 08/03/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _WINDOW_FOCUS_CHANGED_EVENT_H_
#define _WINDOW_FOCUS_CHANGED_EVENT_H_

#include "window_event.h"

enum class WindowFocusChangeType {
  Unknown = -1,
  Minimized,
  Maximized,
  FocusLost,
  FocusGained
};

class WindowFocusChangedEvent : public WindowEvent {
  public:
    // Default constructor.
    // 
    // @param[in] focus_type 
    WindowFocusChangedEvent(WindowFocusChangeType focus_type);

    // Get the focus type
    // 
    // @return WindowFocusChangeType 
    WindowFocusChangeType get_focus_type();

    // 
    // 
    // @return std::string 
    std::string ToString() const override;
  private:
    // 
    WindowFocusChangeType focus_type_;
};

#endif