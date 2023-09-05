// @file menu_bar_panel.h
// Created on 09/05/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _MENU_BAR_PANEL_H_
#define _MENU_BAR_PANEL_H_

#include "panel.h"

class MenuBarPanel : public Panel {
  public:
    // Default constructor.
    // 
    MenuBarPanel();

    // Destructor.
    // 
    ~MenuBarPanel();

    // 
    // 
    void Render() override;
};

#endif