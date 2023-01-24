/**
 * @file Model.cpp
 * Created on 01/23/2023
 * 
 * Implemenation of Model class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "Model.h"

Model::Model(std::string name):
    name(name)
{

} // end default constructor

Model::Model(const Model & model)
{

} // end copy constructor

Model::~Model()
{

} // end destructor

bool Model::addVertex(const Vector<3> & v)
{
    this->vertices.push_back(v);

    return true;
} // end addVertex

std::string Model::getName() const
{
    return this->name;
} // end getName

size_t Model::getNumberOfVertices() const 
{
    return this->vertices.size();
} // end getNumberOfVertices

size_t Model::getNumberOfTriangles() const
{
    return this->triangles.size();
}