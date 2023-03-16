/**
 * @file Rectangle.h
 * Created on 03/15/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Renderable2D.h"

class Rectangle : public Renderable2D {
    public:
        Rectangle(float width, float height);

        ~Rectangle();

        void setWidth(float width);

        void setHeight(float height);

        void render() override;

    private:
        void updateModelMatrix();

        float m_width;

        float m_height;
}; // end Rectangle class

#endif