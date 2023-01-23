/**
 * @file Model.h
 * Created on 01/20/2023
 * 
 * This class represents a 3D model. A model has a collection of vertices along
 * with a collection of triangles that are composed from those vertices. Analogous
 * to element buffer objects with OpenGL.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _MODEL_H_
#define _MODEL_H_

#include "Vector.h"
#include "Triangle.h"
#include <string>
#include <vector>

class Model {
    public:
        // Default constructor
        Model();

        // Copy constructor
        Model(const Model & model);

        // Destructor
        ~Model();

    private:
        std::string name;
        std::vector<Vector<3>> vertices;
        std::vector<Triangle> triangles;
}; // end Model class

#endif
