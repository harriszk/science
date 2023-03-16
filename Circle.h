/**
 * @file Circle.h
 * Created on 03/15/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Renderable2D.h"

class Circle : public Renderable2D {
    public:
        Circle(float radius);

        ~Circle();

        void render() override;

        void updateModelMatrix();
    private:
        float m_radius;
}; // end Circle class

#endif