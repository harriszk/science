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

#include "Triangle.h"
#include <glm/glm.hpp>
#include <string>
#include <vector>

class Model {
    public:
        // Default constructor
        Model(std::string name);

        // Copy constructor
        Model(const Model & model);

        // Destructor
        ~Model();

        /**
         * 
         * 
         * @param[in] v 
         * @return true 
         * @return false 
         */
        bool addVertex(const glm::vec3 & v);

        /**
         * Gets the name of the model.
         * 
         * @return std::string 
         */
        std::string getName() const;

        /**
         * Gets the number of vertices that the compose the model.
         * 
         * @return size_t 
         */
        size_t getNumberOfVertices() const;

        /**
         * Gets the number of triangles that the compose the model.
         * 
         * @return size_t 
         */
        size_t getNumberOfTriangles() const;

        std::vector<glm::vec3> getPoints() const;
    private:
        std::string name;
        std::vector<glm::vec3> vertices;
        std::vector<Triangle> triangles;
}; // end Model class

#endif
