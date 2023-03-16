/**
 * @file Renderable2D.h
 * Created on 01/29/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _RENDERABLE_2D_H_
#define _RENDERABLE_2D_H_

#include "Renderable.h"

class Renderable2D : public Renderable {
    public:
        virtual void render() override = 0;
    
        virtual void setPosition(float x, float y)
        {
            m_position.x = x;
            m_position.y = y;
        } // end setPosition

        virtual void setRotation(float angle)
        {
            m_degreesRotated = angle;
        } // end setRotation

    protected:
        glm::vec2 m_position;

        float m_degreesRotated;
}; // end Renderable2D class

#endif