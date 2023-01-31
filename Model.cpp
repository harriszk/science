/**
 * @file Model.cpp
 * Created on 01/30/2023
 * 
 * Implementation of the Model class. 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "Model.h"

#include <glad/glad.h>

Model::Model()
{

} // end default constructor

Model::~Model()
{

} // end destructor

bool Model::addVertex(const Vertex &vertex)
{
    m_vertices.push_back(vertex);

    // TODO: Check if a vertex with same positions is already apart of the model.

    m_vao.bind();
    m_vbo.setData(&m_vertices);

    return true;
} // end addVertex

bool Model::addTriangle(const Triangle &triangle)
{
    m_triangles.push_back(triangle);

    // TODO: Check if triangle with same indices is already apart of the model.

    m_vao.bind();
    m_ebo.setData(&m_triangles);

    return true;
} // end addTriangle

void Model::render()
{
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    m_vao.bind();
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, m_triangles.size() * 3, GL_UNSIGNED_INT, 0);
} // end render