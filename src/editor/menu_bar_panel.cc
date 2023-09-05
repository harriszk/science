// @file menu_bar_panel.cc
// Created on 09/05/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "editor/menu_bar_panel.h"

MenuBarPanel::MenuBarPanel() {

}

MenuBarPanel::~MenuBarPanel() {

}

void MenuBarPanel::Render() {
  if (ImGui::BeginMainMenuBar()) {
    if (ImGui::BeginMenu("File")) {
      if (ImGui::MenuItem("Open", "Ctrl+O")) {
        // Handle the "Open" menu item click
      }
      if (ImGui::MenuItem("Save", "Ctrl+S")) {
        // Handle the "Save" menu item click
      }
      ImGui::EndMenu();
    }

    if (ImGui::BeginMenu("Edit")) {
      if (ImGui::MenuItem("Undo", "Ctrl+Z")) {
        // Handle the "Undo" menu item click
      }
      if (ImGui::MenuItem("Redo", "Ctrl+Y")) {
        // Handle the "Redo" menu item click
      }
      ImGui::EndMenu();
    }

    ImGui::EndMainMenuBar();
  }
}