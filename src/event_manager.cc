// @file event_manager.cc
// Created on 08/11/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "event_manager.h"

#include <algorithm>

#include "logger.h"

EventManager* EventManager::instance_ = nullptr;

EventManager::EventManager() {

}

EventManager::~EventManager() {
  delete instance_;
}

EventManager* EventManager::Get() {
  if (instance_ == nullptr) {
    instance_ = new EventManager();
  }

  return instance_;
}

bool EventManager::Subscribe(EventListener* observer, EventType type) {
  auto iter = listeners_.find(type);
  if (iter == listeners_.end()) {
    listeners_[type] = {observer};
    return true;
  }

  auto& observers = iter->second;
  if (std::find(observers.begin(), observers.end(), observer) != observers.end()) {
    // Observer is already subscribed, return false
    return false;
  } else {
    // Observer is not subscribed, add to the list
    observers.push_back(observer);
    return true;
  }
}

bool EventManager::Unsubscribe(EventListener* observer, EventType type) {
  auto iter = listeners_.find(type);
  if (iter == listeners_.end()) {
    return false;
  }

  auto& observers = iter->second;
  auto it = std::find(observers.begin(), observers.end(), observer);
  if (it != observers.end()) {
    // Observer is subscribed, so we need to remove it.
    observers.erase(it);
    return true;
  }

  return false;
}

bool EventManager::UnsubscribeAll() {
  listeners_.clear();
  return true;
}

void EventManager::Dispatch(const Event& event) {
  LOG_INFO("Dispatching: {0}", event.ToString());

  auto iter = listeners_.find(event.get_event_type());
  if (iter == listeners_.end()) {
    return;
  }

  for (EventListener* listener : iter->second) {
    listener->OnEvent(event);
  }
}