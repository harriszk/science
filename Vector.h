/**
 * @file Vector.h
 * Created on 01/20/2023
 * 
 * This class represents a row vector in n-space. It is used as an alternative to
 * an n x 1 matrix. You may perform the standard vector operations as you would
 * see in Linear Algebra. i.e. addition, scalar multiplication, cross product, etc.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdlib.h>
#include <iterator>
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iostream>
#include <exception>


template <size_t N, typename T = float>
class Vector {
    public:
        // Type definition of the element type.
        typedef T type;

        // Default constructor
        Vector();

        /**
         * Copy constructor.
         * 
         * @param[in]   v   The source vector 
         */
        Vector(const Vector &v);

        // Destructor
        ~Vector();

        /**
         * Gets the element at the specified index. If the index is
         * not within range std::out_of_range exception is thrown.
         * 
         * @param[in]   index   Zero-based location
         * @exception   std::out_of_range   Invalid index value
         */
        T & operator [] (size_t index);

        /**
         * Computes the dot product of the two vectors.
         * 
         * @param[in]   rhs     Right-hand side of the multiplication sign
         * @return      T       The sum of the products
         */
        T operator * (const Vector & rhs);

        /**
         * Scales the vector by the factor specified on the right-hand side.
         * 
         * @param[in]   scalar  The scaling factor 
         */
        void operator * (const float scalar);
    private:
        // Pointer to the actual data.
        T * data;

        // Size, or dimension, of the vector.
        size_t dimension;
}; // end Vector class

#endif

// --- Implementation ---

template <size_t N, typename T>
Vector<N, T>::Vector():
    data(nullptr),
    dimension(N)
{
    this->data = new T[N];
} // end constructor

template <size_t N, typename T>
Vector<N, T>::Vector(const Vector &v):
    data(nullptr),
    dimension(v.dimension)
{
    this->data = new T[this->dimension];

    for(size_t i = 0; i < this->dimension; i++)
    {
        this->data[i] = v.data[i];
    } // end for
} // end copy constructor

template <size_t N, typename T>
Vector<N, T>::~Vector()
{
    delete[] this->data;
} // end destructor

template <size_t N, typename T>
T & Vector<N, T>::operator [] (size_t index)
{
    if(this->dimension <= index)
    {
        throw std::out_of_range("Out of range.");
    } // end if

    return this->data[index];
} // end index operator

template <size_t N, typename T>
T Vector<N, T>::operator * (const Vector & rhs)
{
    T result = 0.0;

    for(size_t i = 0; i < this->dimension; i++)
    {
        result += this->data[i] * rhs.data[i];
    }

    return result;
} // end multiplication operator (dot product)

template <size_t N, typename T>
void Vector<N, T>::operator * (const float scalar)
{
    for(size_t i = 0; i < N; i++)
    {
        this->data[i] *= scalar;
    } // end for
} // end multiplication operator (scalar product)

template <size_t N, typename T>
void operator * (const float scalar, Vector<N, T> & v)
{
    v * scalar;
} // end multiplication operator (scalar product)
