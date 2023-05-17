/**
 * @file PeriodicTable.cpp
 * Created on 05/17/2023
 * 
 * Implementation of PeriodicTable class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "../../include/physics/PeriodicTable.h"

#include <iostream>

PeriodicTable::PeriodicTable()
{

} // end default constructor

PeriodicTable& PeriodicTable::getInstance()
{
    static PeriodicTable instance;
    return instance;
} // end getInstance

void PeriodicTable::getElement(int atomicNumber)
{
    std::cout << "Getting element with atomic number " << atomicNumber << "\n";
    return;
} // end getElement

void PeriodicTable::loadAllElements()
{

} // end loadAllElements

void PeriodicTable::loadElement(int atomicNumber)
{

} // end loadElement