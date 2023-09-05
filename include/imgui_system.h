// @file imgui_system.h
// Created on 08/14/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _IMGUI_SYSTEM_H_
#define _IMGUI_SYSTEM_H_

#include "system.h"
#include "event_listener.h"

class ImGuiSystem : public System, public EventListener {
  public:
    // Default constructor.
    // 
    ImGuiSystem();

    // Destructor.
    // 
    ~ImGuiSystem();

    // 
    // 
    void OnUpdate() override;

    // 
    // 
    // @param[in] event 
    void OnEvent(const Event& event) override;
  private:
    // 
    // 
    // @param[in] event 
    void OnMouseEvent(const Event& event);

    // 
    // 
    // @param[in] event 
    void OnKeyboardEvent(const Event& event);

    // 
    // 
    float time_ = 1.0f / 60.0f;
};

#endif