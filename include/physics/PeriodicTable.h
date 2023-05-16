/**
 * @file PeriodicTable.h
 * Created on 05/16/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _PERIODIC_TABLE_H_
#define _PERIODIC_TABLE_H_

#include "Atom.h"
#include <vector>

class PeriodicTable {
    public:
        /**
         * 
         * 
         * @return PeriodicTable& 
         */
        static PeriodicTable & getInstance();

        /**
         * 
         * 
         * @param[in] atomicNumber 
         * @return Atom& 
         */
        Atom & getElement(int atomicNumber);

    private:
        // Default constructor
        PeriodicTable();

        // Disable copy construtor
        PeriodicTable(const PeriodicTable&) = delete;

        // Disable assignment operator
        PeriodTable & operator = (const PeriodicTable&) = delete;

        /**
         * 
         * 
         */
        void loadElements();

        // 
        std::vector<Atom> elements;
}; // end PeriodicTable class

#endif