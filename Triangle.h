/**
 * @file Triangle.h
 * Created on 01/20/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <stdlib.h>

class Triangle {
    public:
        // Constructor
        Triangle(size_t v_0, size_t v_1, size_t v_2);

        size_t getv0() const;

        size_t getv1() const;

        size_t getv2() const;
    private:
        size_t v_0;
        size_t v_1;
        size_t v_2;
}; // end Triangle class

#endif