// @file rectangle.h
// Created on 03/15/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "renderable_2d.h"

class Rectangle : public Renderable2D {
  public:
    // Default constructor.
    // 
    // @param[in] width 
    // @param[in] height 
    Rectangle(float width, float height);

    // Destructor.
    ~Rectangle();

    // Set the width
    // 
    // @param[in] width 
    void set_width(float width);

    // Set the height
    // 
    // @param[in] height 
    void set_height(float height);

    // 
    void Render() override;

  private:
    // 
    void UpdateModelMatrix();

    // 
    float width_;

    // 
    float height_;
};

#endif