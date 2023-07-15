// @file renderable_3d.h
// Created on 01/29/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _RENDERABLE_3D_H_
#define _RENDERABLE_3D_H_

#include "renderable.h"

class Renderable3D : public Renderable {
  public:
    virtual void Render() override = 0;
};

#endif