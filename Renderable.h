/**
 * @file Renderable.h
 * Created on 01/29/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

class Renderable {
    public:
        /**
         * Renders the object.
         */
        virtual void render() = 0;
}; // end Renderable class

#endif