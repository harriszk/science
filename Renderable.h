/**
 * @file Renderable.h
 * Created on 01/29/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElementBufferObject.h"
#include "Vertex.h"
#include "Triangle.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glad/glad.h>

class Renderable {
    public:
        /**
         * Renders the object.
         */
        virtual void render() = 0;

        /**
         * Returns the models transformation matrix.
         * 
         * @return glm::mat4 The model matrix of the model, transforming from the models local space to world space.
         */
        glm::mat4 getModelMatrix() const 
        {
            return m_modelMatrix;
        };
    
    protected:
        // The collection of vertices that make up the renderable object.
        std::vector<Vertex> m_vertices;

        // The collection of triangles that make up the renderable object.
        std::vector<Triangle> m_triangles;

        // The collection of lines that make up the renderable object.
        //std::vector<Line> m_lines;

        // The vertex array object associated with the renderable object.
        VertexArrayObject m_vao;

        // The vertex buffer object associated with the renderable object.
        VertexBufferObject m_vbo;

        // The element buffer object associated with the renderable object.
        ElementBufferObject m_ebo;

        // The models transformation matrix. It maps vertices from local space to world space.
        glm::mat4 m_modelMatrix = glm::mat4(1.0f);
}; // end Renderable class

#endif