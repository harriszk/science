/**
 * @file PeriodicTable.cpp
 * Created on 05/17/2023
 * 
 * Implementation of PeriodicTable class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "../../include/physics/PeriodicTable.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <cstdio>
#include <iostream>

#define NUMBER_OF_ELEMNTS 118

PeriodicTable::PeriodicTable()
{
    loadAllElements();
} // end default constructor

PeriodicTable::~PeriodicTable()
{
    for (auto atom : this->m_elements)
    {
        delete atom;
    } // end for
} // end destructor

PeriodicTable& PeriodicTable::getInstance()
{
    static PeriodicTable instance;
    return instance;
} // end getInstance

Atom& PeriodicTable::getElement(int atomicNumber)
{
    //std::cout << this->m_elements.at(atomicNumber - 1)->getName() << " " << this->m_elements.at(atomicNumber - 1)->getSymbol() << "\n";

    return *(this->m_elements.at(atomicNumber - 1));
} // end getElement

void PeriodicTable::loadAllElements()
{
    #ifdef _WIN32
        FILE* filePointer = fopen("../src/physics/JSON/PeriodicTable.json", "rb");
    #else
        FILE* filePointer = fopen("../src/physics/JSON/PeriodicTable.json", "r");
    #endif
 
    char readBuffer[65536];
    rapidjson::FileReadStream inputStream(filePointer, readBuffer, sizeof(readBuffer));
    
    rapidjson::Document document;
    document.ParseStream(inputStream);
    
    fclose(filePointer);

    for(int index = 0; index < NUMBER_OF_ELEMNTS; index++)
    {
        Atom* atom = new Atom();

        atom->setName(document["elements"][index]["name"].GetString());
        atom->setSymbol(document["elements"][index]["symbol"].GetString());
        atom->setAtomicNumber(index + 1);
        atom->setAtomicMass(document["elements"][index]["atomic_mass"].GetDouble());

        this->m_elements.push_back(atom);
    } // end for
} // end loadAllElements

void PeriodicTable::loadElement(int atomicNumber)
{

} // end loadElement