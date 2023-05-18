/**
 * @file Atom.cpp
 * Created on 05/17/2023
 * 
 * Implementation of Atom class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "../../include/physics/Atom.h"

Atom::Atom()
{

} // end default constructor

Atom::Atom(std::string name, std::string symbol, int atomicNumber, double atomicMass):
    m_name(std::move(name)),
    m_symbol(std::move(symbol)),
    m_atomicNumber(atomicNumber),
    m_atomicMass(atomicMass)
{

} // end initializing constructor

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

void Atom::setName(std::string name)
{
    this->m_name = name;
} // end setName

void Atom::setSymbol(std::string symbol)
{
    this->m_symbol = symbol;
} // end setSymbol

void Atom::setAtomicNumber(int number)
{
    this->m_atomicNumber = number;
} // end setAtomicNumber

void Atom::setAtomicMass(double mass)
{
    this->m_atomicMass = mass;
} // end setAtomicMass