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
    }
} // end destructor

PeriodicTable& PeriodicTable::getInstance()
{
    static PeriodicTable instance;
    return instance;
} // end getInstance

void PeriodicTable::getElement(int atomicNumber)
{
    std::cout << this->m_elements.at(atomicNumber - 1)->getName() << " " << this->m_elements.at(atomicNumber - 1)->getSymbol() << "\n";

    return;
} // end getElement

void PeriodicTable::loadAllElements()
{
    FILE* filePointer = fopen("../src/physics/JSON/PeriodicTable.json", "r"); // non-Windows use "r"
 
    char readBuffer[65536];
    rapidjson::FileReadStream inputStream(filePointer, readBuffer, sizeof(readBuffer));
    
    rapidjson::Document document;
    document.ParseStream(inputStream);
    
    fclose(filePointer);

    for(int index = 0; index < NUMBER_OF_ELEMNTS; index++)
    {
        Atom* atom = new Atom(
            document["elements"][index]["name"].GetString(),
            document["elements"][index]["symbol"].GetString(),
            index + 1,
            document["elements"][index]["atomic_mass"].GetDouble()
        );

        this->m_elements.push_back(atom);
    } // end for

    // Name
    //d["elements"][atomicNumber]["name"].GetString()
    // Symbol
    //d["elements"][atomicNumber]["symbol"].GetString()
    // Atomic Number
    //index + 1
    // Atomic Mass
    // d["elements"][atomicNumber]["atomic_mass"].GetDouble()
} // end loadAllElements

void PeriodicTable::loadElement(int atomicNumber)
{

} // end loadElement