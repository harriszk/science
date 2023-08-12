// @file event_listener.h
// Created on 08/11/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _EVENT_LISTENER_H_
#define _EVENT_LISTENER_H_

#include "events/event.h"

class EventListener {
  public:
    virtual void OnEvent(const Event& event) = 0;
};

#endif