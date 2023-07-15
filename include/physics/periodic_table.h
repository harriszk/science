// @file periodic_table.h
// Created on 05/16/2023
// 
// This class represents the periodic table of elements. It follows the singleton 
// pattern, allowing only one instance of the class to exist throughout the program 
// execution. It provides functionality to retrieve information about elements 
// based on their atomic number. It also internally loads element data from a data 
// source, such as a JSON file, upon instantiation.
// 
// Usage example:
// // Retrieve an instance of the PeriodicTable class
// PeriodicTable& periodicTable = PeriodicTable::getInstance();
// 
// // Get an element by its atomic number
// Atom& hydrogen = periodicTable.getElement(1);
// int atomicNumber = hydrogen.getAtomicNumber();
// std::string symbol = hydrogen.getSymbol();
// std::string name = hydrogen.getName();
// ...
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _PERIODIC_TABLE_H_
#define _PERIODIC_TABLE_H_

#include <vector>

#include "atom.h"

class PeriodicTable {
    public:
        // Get the singleton instance of the PeriodicTable.
        // 
        // @return PeriodicTable& Reference to the singleton instance of the PeriodicTable.
        static PeriodicTable& get_instance();

        // Get the Atom associated with the given atomic number.
        // 
        // @param[in] atomic_number The atomic number of the element.
        // 
        // @return Atom& Reference to the Atom associated with the atomic number.
        Atom& get_element(int atomic_number);
        //void get_element(int atomic_number);

    private:
        // Default constructor
        PeriodicTable();

        // Disable copy constructor
        PeriodicTable(const PeriodicTable&) = delete;

        // Destructor
        ~PeriodicTable();

        // Disable assignment operator
        PeriodicTable& operator=(const PeriodicTable&) = delete;

        // Load all of the elements from a data source.
        void LoadAllElements();

        // Load the element with the given atomic number from a data source.
        // 
        // @param[in] atomic_number The atomic number of the element to load.
        void LoadElement(int atomic_number);

        // Storage for the periodic table elements.
        std::vector<Atom*> elements_;
}; // end PeriodicTable class

#endif