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
#ifndef _MODEL_H_
#define _MODEL_H_

#include "Renderable.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElementBufferObject.h"
#include "Vertex.h"
#include "Triangle.h"

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
        virtual ~Model();

        /**
         * Adds a vertex to the model.
         * 
         * @param[in] vertex The vertex to be added to the model.
         * @return true The vertex was added successfully.
         * @return false The vertex could not be added (e.g. because it is invalid).
         */
        bool addVertex(const Vertex &vertex);

        /**
         * Adds a triangle to the model.
         * 
         * @param[in] triangle The triangle to be added to the model.
         * @return true The triangle was added successfully.
         * @return false The triangle could not be added (e.g. because it is invalid).
         */
        bool addTriangle(const Triangle &triangle);

        /**
         * Renders the model.
         * 
         */
        virtual void render() override;
    private:
        // The collection of vertices that make up the model.
        std::vector<Vertex> m_vertices;

        // The collection of triangles that make up the model.
        std::vector<Triangle> m_triangles;

        // The vertex array object associated with the model.
        VertexArrayObject m_vao;

        // The vertex buffer object associated with the model.
        VertexBufferObject m_vbo;

        // The element buffer object associated with the model.
        ElementBufferObject m_ebo;
}; // end Model class

#endif