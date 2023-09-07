// @file coordinate_system_2d.h
// Created on 04/10/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _COORDINATE_SYSTEM_2D_H_
#define _COORDINATE_SYSTEM_2D_H_

#include <vector>

#include "renderable_2d.h"
#include "line.h"

class CoordinateSystem2D : public Renderable2D {
  public:
    // Default constructor.
    // 
    // @param[in] min_x 
    // @param[in] max_x 
    // @param[in] min_y 
    // @param[in] max_y 
    CoordinateSystem2D(float min_x, float max_x, float min_y, float max_y);

    // Destructor.
    ~CoordinateSystem2D();

    // 
    // 
    void Render() override;

  private:
    // 
    // 
    int number_of_lines_ = 0;
};

#endif