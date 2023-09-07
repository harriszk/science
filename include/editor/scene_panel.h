// @file scene_panel.h
// Created on 09/05/2023
// 
// This panel is what our renderer will render the scene to using
// a frame buffer.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _SCENE_PANEL_H_
#define _SCENE_PANEL_H_

#include "panel.h"
#include "event_listener.h"

class ScenePanel : public Panel, public EventListener {
  public:
    // Default constructor.
    // 
    ScenePanel(unsigned int texture_id);

    // Destructor.
    // 
    ~ScenePanel();

    // 
    // 
    void Render() override;

    // 
    // 
    // @param[in] event 
    void OnEvent(const Event& event) override;
  private:
    // TESTING VARIABLES ARE NOT PERMANENT.
    float x_pos_;

    float y_pos_;

    unsigned int texture_id_;
};

#endif