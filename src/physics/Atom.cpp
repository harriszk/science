/**
 * @file Atom.cpp
 * Created on 05/17/2023
 * 
 * Implementation of Atom class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "../../include/physics/Atom.h"

Atom::Atom(std::string name, std::string symbol, int atomicNumber, double atomicMass):
    m_name(std::move(name)),
    m_symbol(std::move(symbol)),
    m_atomicNumber(atomicNumber),
    m_atomicMass(atomicMass)
{

} // end default constructor

Atom::~Atom()
{

} // end destructor

std::string Atom::getName()
{
    return m_name;
} // end getName

std::string Atom::getSymbol()
{
    return m_symbol;
} // end getSymbol

int Atom::getAtomicNumber()
{
    return m_atomicNumber;
} // end getAtomicNumber

double Atom::getAtomicMass()
{
    return m_atomicMass;
} // end getAtomicMass