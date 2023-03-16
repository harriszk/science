/**
 * @file Renderable3D.h
 * Created on 01/29/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _RENDERABLE_3D_H_
#define _RENDERABLE_3D_H_

#include "Renderable.h"

class Renderable3D : public Renderable{
    public:
        virtual void render() override = 0;
}; // end Renderable3D class

#endif