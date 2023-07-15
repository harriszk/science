// @file circle.h
// Created on 03/15/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "renderable_2d.h"

class Circle : public Renderable2D {
  public:
    Circle(float radius);

    ~Circle();

    void Render() override;

    void UpdateModelMatrix();
  private:
    float radius_;
};

#endif