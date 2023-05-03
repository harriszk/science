/**
 * @file Model.cpp
 * Created on 01/30/2023
 * 
 * Implementation of the Model class. 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "../../include/render/Model.h"
#include <glad/glad.h>
#include <iostream>

#include <string>
#include <fstream>
#include <sstream>

#include <glm/gtc/matrix_transform.hpp>

Model::Model():
    m_hasChanged(false)
{
    m_modelMatrix = glm::mat4(1.0f);
    //m_modelMatrix = glm::rotate(m_modelMatrix, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
} // end default constructor

Model::~Model()
{

} // end destructor

bool Model::addVertex(const Vertex &vertex)
{
    m_vertices.push_back(vertex);
    m_hasChanged = true;
    // TODO: Check if a vertex with same positions is already apart of the model.

    return true;
} // end addVertex

bool Model::addTriangle(const Triangle &triangle)
{
    m_triangles.push_back(triangle);
    m_hasChanged = true;
    // TODO: Check if triangle with same indices is already apart of the model.

    return true;
} // end addTriangle

std::vector<Vertex> & Model::getVertices()
{
    return m_vertices;
} // enf getVertices

std::vector<Triangle> & Model::getTriangles()
{
    return m_triangles;
} // end getTriangles

void Model::loadModel(const char *filename)
{
    std::ifstream in;
    in.open(filename, std::ifstream::in);

    if(in.fail()) 
    {
        std::cerr << "ERROR::MODEL::FILE_NOT_SUCCESFULLY_READ: " << filename << std::endl;
        return;
    }

    std::string line;

    while (!in.eof()) 
    {
        std::getline(in, line);
        std::istringstream iss(line.c_str());
        char trash;

        if(!line.compare(0, 2, "v ")) {
            iss >> trash;
            Vertex v;

            iss >> v.x;
            iss >> v.y;
            iss >> v.z;

            m_vertices.push_back(v);
        } else if(!line.compare(0, 2, "f ")) {
            iss >> trash;
            Triangle f;
            
            iss >> f.v0;
            iss >> f.v1;
            iss >> f.v2;

            f.v0--;
            f.v1--;
            f.v2--;

            m_triangles.push_back(f);
        }
    } // end while

    m_hasChanged = true;
} // end loadModel

void Model::render()
{
    if(m_hasChanged)
    {
        upload();
        m_hasChanged = false;
    }

    /*
    for(int i = 0; i < m_vertices.size(); i++)
    {
        std::cout << m_vertices[i].x << " " << m_vertices[i].y << " " << m_vertices[i].z << "\n"; 
    }
    std::cout << "\n";
    */

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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    m_vbo.unbind();
    m_vao.unbind();
}