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
#include <iostream>

Model::Model():
    hasChanged(false)
{

} // end default constructor

Model::~Model()
{

} // end destructor

bool Model::addVertex(const Vertex &vertex)
{
    m_vertices.push_back(vertex);
    hasChanged = true;
    // TODO: Check if a vertex with same positions is already apart of the model.

    return true;
} // end addVertex

bool Model::addTriangle(const Triangle &triangle)
{
    m_triangles.push_back(triangle);
    hasChanged = true;
    // TODO: Check if triangle with same indices is already apart of the model.

    return true;
} // end addTriangle

std::vector<Vertex> & Model::getVertices()
{
    return m_vertices;
}

std::vector<Triangle> & Model::getTriangles()
{
    return m_triangles;
}

void Model::render()
{
    if(hasChanged)
    {
        upload();
        hasChanged = false;
    }

    //glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
    //std::cout << "Drawing elements...\n";
    m_vao.bind();
    glDrawElements(GL_TRIANGLES, m_triangles.size() * 3, GL_UNSIGNED_INT, 0);
} // end render

void Model::upload()
{
    m_vao.bind();

    m_vbo.bind();
    m_vbo.setData(&m_vertices);

    m_ebo.bind();
    m_ebo.setData(&m_triangles);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    m_vbo.unbind();
    m_vao.unbind();
}