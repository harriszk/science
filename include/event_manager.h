// @file event_manager.h
// Created on 08/10/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _EVENT_MANAGER_H_
#define _EVENT_MANAGER_H_

#include <vector>
#include <typeindex>
#include <unordered_map>

#include "event_listener.h"
#include "events/event.h"

class EventManager {
  public:
    EventManager();

    ~EventManager();

    bool Subscribe(EventListener* observer, EventType type);

    bool Unsubscribe(EventListener* observer, EventType type);

    bool UnsubscribeAll();

    void Dispatch(const Event& event);
  private:
    std::unordered_map<EventType, std::vector<EventListener*>> observers_;
};

#endif