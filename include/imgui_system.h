// @file imgui_system.h
// Created on 08/14/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _IMGUI_SYSTEM_H_
#define _IMGUI_SYSTEM_H_

#include <vector>

#include "system.h"
#include "event_listener.h"

#include "editor/panel.h"

class ImGuiSystem : public System, public EventListener {
  public:
    // Default constructor.
    // 
    ImGuiSystem(unsigned int frame_buffer_object);

    // Destructor.
    // 
    ~ImGuiSystem();

    // 
    // 
    // @param[in] panel 
    void AddPanel(Panel* panel);

    // 
    // 
    void OnUpdate() override;

    // 
    // 
    // @param[in] event 
    void OnEvent(const Event& event) override;

    // HACKY JUST TO SEE RESULTS!!!
    void test(unsigned int t);
    // END HACKY!!!
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
    std::vector<Panel*> panels_;

    // 
    // 
    float time_ = 1.0f / 60.0f;

    // HACKY JUST TO SEE RESULTS!!!
    unsigned int frame_buffer_object_;
    // END HACKY!!!
};

#endif