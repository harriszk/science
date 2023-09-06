// @file asset_panel.cc
// Created on 09/05/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "editor/asset_panel.h"

AssetPanel::AssetPanel()
    : cell_size_(75, 30), 
      min_column_width_(cell_size_.x + ImGui::GetStyle().ItemSpacing.x) {
  labels_.push_back("Asset 1"); 
  labels_.push_back("Asset 2"); 
  labels_.push_back("Asset 3"); 
  labels_.push_back("Asset 4"); 
  labels_.push_back("Asset 5"); 
  labels_.push_back("Asset 6"); 
  labels_.push_back("Asset 7"); 
  labels_.push_back("Asset 8");
}

AssetPanel::~AssetPanel() {

}

void AssetPanel::Render() {
  ImGui::Begin("Assets");

   // Counter for the labels
  int asset_counter = 0;

  // Calculate the number of columns based on the minimum width.
  // Ensure that there is at least one column.
  int number_of_columns = static_cast<int>(ImGui::GetWindowWidth() / min_column_width_);
  number_of_columns = std::max(number_of_columns, 1);

  for (const std::string& label : labels_) {
    if (asset_counter > 0 && asset_counter % number_of_columns != 0) {
      ImGui::SameLine();
    }

    ImGui::PushID(asset_counter);

    if (ImGui::Selectable(label.c_str(), false, 0, cell_size_)) {
      // Handle the selection action here
      // You can use asset_counter to identify the selected item
    }

    ImGui::PopID();
    asset_counter++;
  }

  ImGui::End();
}