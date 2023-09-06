// @file asset_panel.h
// Created on 09/05/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _ASSET_PANEL_H_
#define _ASSET_PANEL_H_

#include <vector>
#include <string>

#include "panel.h"

class AssetPanel : public Panel {
  public:
    AssetPanel();

    ~AssetPanel();

    void Render() override;
  private:
    std::vector<std::string> labels_;

    ImVec2 cell_size_;

    float min_column_width_ ;
};

#endif