/**
 * @file CoordinateSystem2D.h
 * Created on 04/10/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _COORDINATE_SYSTEM_2D_H_
#define _COORDINATE_SYSTEM_2D_H_

#include "Renderable2D.h"
#include "Line.h"
#include <vector>

class CoordinateSystem2D : public Renderable2D {
    public:
        CoordinateSystem2D(float minX, float maxX, float minY, float maxY);

        ~CoordinateSystem2D();

        void render() override;

    private:
        int numberOfLines = 0;
}; // end CoordinateSystem class

#endif