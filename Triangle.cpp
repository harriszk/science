/**
 * @file Triangle.cpp
 * Created on 01/20/2023
 * 
 * Implemenation of the Triangle class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "Triangle.h"

Triangle::Triangle(size_t v_0, size_t v_1, size_t v_2):
    v_0(v_0),
    v_1(v_1),
    v_2(v_2)
{

} // end constructor

size_t Triangle::getv0() const
{
    return this->v_0;
} // end getv0

size_t Triangle::getv1() const
{
    return this->v_1;
} // end getv1

size_t Triangle::getv2() const
{
    return this->v_2;
} // end getv2