/**
 * @file Atom.h
 * Created on 05/16/2023
 * 
 * This class represents an atom in the periodic table with the properties
 * of that atom. These include things such as atomic number, symbol, boiling
 * point, etc. This is a read-only class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _ATOM_H_
#define _ATOM_H_

#include <string>

class Atom {
    public:
        // Default constructor
        Atom();

        // Destructor
        ~Atom();

        /**
         * Get the name of the atom.
         * 
         * @return std::string The name of the atom.
         */
        std::string getName();

        /**
         * Get the symbol of the atom.
         * 
         * @return std::string The symbol of the atom.
         */
        std::string getSymbol();

        /**
         * Get the atmoic number of the atom.
         * 
         * @return int The atomic number of the atom.
         */
        int getAtomicNumber();

        /**
         * Get the atomic mass of the atom.
         * 
         * @return double The atomic mass of the atom.
         */
        double getAtomicMass();
    private:
        // The name of the atom.
        std::string m_name;

        // The symbol of the atom.
        std::string m_symbol;

        // The atomic number of the atom.
        int m_atomicNumber;
        
        // The atmoic mass of the atom.
        double m_atomicMass;
}; // end Atom class

#endif