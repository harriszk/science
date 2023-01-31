/**
 * @file ModelTrash.h
 * Created on 01/20/2023
 * 
 * This class represents a 3D model. A model has a collection of vertices along
 * with a collection of triangles that are composed from those vertices. Analogous
 * to element buffer objects with OpenGL.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
//#ifndef _MODEL_H_
//#define _MODEL_H_

#include "Vertex.h"
#include "Triangle.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

class ModelTrash {
    public:
        // Default constructor
        ModelTrash(const char *name);

        // Copy constructor
        ModelTrash(const ModelTrash & model);

        // Destructor
        ~ModelTrash();

        /**
         * 
         * 
         * @param[in] v 
         * @return true 
         * @return false 
         */
        bool addVertex(const Vertex & v);

        /**
         * 
         * 
         * @param[in] t 
         * @return true 
         * @return false 
         */
        bool addTriangle(const Triangle & t);

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

        bool loadTexture(const char * file);

        /**
         * 
         * 
         * @param[in] dt 
         */
        void draw(float dt);
    private:
        const char *name;
        std::vector<Vertex> vertices;
        std::vector<Triangle> triangles;
        unsigned int texture;
}; // end ModelTrash class

//#endif
