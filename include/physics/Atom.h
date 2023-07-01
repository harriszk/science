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
        friend class PeriodicTable;

        // Destructor
        ~Atom();

        /**
         * Gets the name of the atom.
         * 
         * @return std::string The name of the atom.
         */
        std::string getName();

        /**
         * Gets the symbol of the atom.
         * 
         * @return std::string The symbol of the atom.
         */
        std::string getSymbol();

        /**
         * Gets the atmoic number of the atom.
         * 
         * @return int The atomic number of the atom.
         */
        int getAtomicNumber();

        /**
         * Gets the atomic mass of the atom.
         * 
         * @return double The atomic mass of the atom.
         */
        double getAtomicMass();
    private:
        // Default constructor
        Atom();

        // Initializing constructor
        Atom(std::string name, std::string symbol, int atomicNumber, double atomicMass);

        /**
         * Sets the name of the atom.
         * 
         * @param[in] name Name of the atom.
         */
        void setName(std::string name);

        /**
         * Sets the symbol of the atom.
         * 
         * @param[in] symbol Symbol of the atom.
         */
        void setSymbol(std::string symbol);

        /**
         * Sets the atomic number of the atom.
         * 
         * @param[in] number Atomic number of the atom.
         */
        void setAtomicNumber(int number);

        /**
         * Sets the atomic mass of the atom.
         * 
         * @param[in] mass Atomic mass of the atom.
         */
        void setAtomicMass(double mass);

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