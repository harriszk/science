/**
 * @file Line.h
 * Created on 03/15/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _LINE_H_
#define _LINE_H_

#include "Renderable.h"
#include <cstdint>

class Line : public Renderable {
    public:
        Line(const Vertex &p1, const Vertex &p2);

        ~Line();

        void render() override;

    private:

}; // end Line class

#endif