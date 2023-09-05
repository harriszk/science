// @file scene_panel.cc
// Created on 09/05/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "editor/scene_panel.h"

#include "event_manager.h"
#include "events/mouse_moved_event.h"

ScenePanel::ScenePanel() {
  EventManager::Get()->Subscribe(this, EventType::MouseMoved);
}

ScenePanel::~ScenePanel() {

}

void ScenePanel::Render() {
  ImGui::Begin("Scene");

  ImGui::Text("Mouse Position: (%.2f, %.2f)", x_pos_, y_pos_);
  
  ImGui::End();
}

void ScenePanel::OnEvent(const Event& event) {
  switch (event.get_event_type()) {
    case EventType::MouseMoved: {
      const MouseMovedEvent& mouse_event = static_cast<const MouseMovedEvent&>(event);

      x_pos_ = mouse_event.get_x();
      y_pos_ = mouse_event.get_y();

      break;
    }
    default:
      break;
  }
}