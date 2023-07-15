// @file atom.h
// Created on 05/16/2023
// 
// This class represents an atom in the periodic table with the properties
// of that atom. These include things such as atomic number, symbol, boiling
// point, etc. This is a read-only class.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _ATOM_H_
#define _ATOM_H_

#include <string>

class Atom {
  public:
    friend class PeriodicTable;

    // Destructor
    ~Atom();

    // Gets the name of the atom.
    // 
    // @return std::string The name of the atom.
    std::string get_name();

    // Gets the symbol of the atom.
    // 
    // @return std::string The symbol of the atom.
    std::string get_symbol();

    // Gets the atomic number of the atom.
    // 
    // @return int The atomic number of the atom.
    int get_atomic_number();

    // Gets the atomic mass of the atom.
    // 
    // @return double The atomic mass of the atom.
    double get_atomic_mass();

  private:
    // Default constructor
    Atom();

    // Initializing constructor
    Atom(std::string name, std::string symbol, int atomic_number, double atomic_mass);

    // Sets the name of the atom.
    // 
    // @param[in] name Name of the atom.
    void set_name(std::string name);

    // Sets the symbol of the atom.
    // 
    // @param[in] symbol Symbol of the atom.
    void set_symbol(std::string symbol);

    // Sets the atomic number of the atom.
    // 
    // @param[in] number Atomic number of the atom.
    void set_atomic_number(int number);

    // Sets the atomic mass of the atom.
    // 
    // @param[in] mass Atomic mass of the atom.
    void set_atomic_mass(double mass);

    // The name of the atom.
    std::string name_;

    // The symbol of the atom.
    std::string symbol_;

    // The atomic number of the atom.
    int atomic_number_;
    
    // The atomic mass of the atom.
    double atomic_mass_;
}; // end Atom class

#endif