/**
 * @file Model.h
 * Created on 01/29/2023
 * 
 * This class represents an object in the world that may be either 2D or 3D. It 
 * contains information about the geometry and appearance of the object, including 
 * its vertices, normals, textures, and material properties.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifdef _MODEL_H_
#define _MODEL_H_

#include "Renderable.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElementBufferObject.h"

#include <vector>

class Model : public Renderable {
    public:
        /**
         * Default constructor. 
         * Creates an empty model, ready to have vertices and triangles added.
         * 
         */
        Model();

        // Desetructor
        ~Model();

        /**
         * Adds a vertex to the model.
         * 
         * @param[in] v The vertex to be added to the model.
         * @return true The vertex was added successfully.
         * @return false The vertex could not be added (e.g. because it is invalid).
         */
        bool addVertex(const Vertex &v);

        /**
         * Adds a triangle to the model.
         * 
         * @param[in] t The triangle to be added to the model.
         * @return true The triangle was added successfully.
         * @return false The triangle could not be added (e.g. because it is invalid).
         */
        bool addTriangle(const Triangle &t);

        /**
         * Renders the model.
         * 
         */
        virtual void render() override;
    private:
        // The collection of vertices that make up the model.
        std::vector<Vertex> vertices;

        // The collection of triangles that make up the model.
        std::vector<Triangle> triangles;

        // The Vertex Array Object associated with the model.
        VertexArrayObject m_vao;

        // The Vertex Buffer Object associated with the model.
        VertexBufferObject m_vbo;

        // The element buffer object associated with the model.
        ElementBufferObject m_ebo;
}; // end Model class

#endif