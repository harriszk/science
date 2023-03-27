/**
 * @file Triangle.h
 * Created on 01/20/2023
 * 
 * Simple structure to contain the indicies of three vertices what make up a triangle.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <cstdint>

struct Triangle
{
    uint32_t v0;
    uint32_t v1;
    uint32_t v2;
}; // end Triangle struct

#endif