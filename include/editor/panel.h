// @file panel.h
// Created on 09/05/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _PANEL_H_
#define _PANEL_H_

#include "imgui/imgui.h"

class Panel {
  public:
    virtual ~Panel() {}

    virtual void Render() = 0;
};

#endif