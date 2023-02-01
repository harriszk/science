/**
 * @file Renderer.cpp
 * Created on 01/30/2023
 * 
 * Implementation fo the Renderer class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "Renderer.h"
#include <iostream>

Renderer::Renderer(Display &display, Shader &shader):
    m_display(display),
    m_shader(shader)
    
{

} // end default constructor

Renderer::~Renderer()
{

} // end destructor

void Renderer::startRendering()
{
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while(!m_display.shouldClose()) 
    {
        render();
    } // end while
} // end startRendering

void Renderer::render()
{
    glClearColor(0.0f, 0.6f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_shader.use();

    // Compute dt
    // Render models from the scene
    auto &models = m_scenes.at(0).getModels();
    for (auto &model : models) {
        model->render();
    }

    m_display.update();

    /*
    std::vector<Vertex> vertices;
    std::vector<Triangle> triangles;

    
    int number_of_points = 0;
    auto &models = m_scenes.at(0).getModels();
    for(auto &model : models)
    {
        std::vector<Vertex> &tempV = model.getVertices();
        for(auto vertex : tempV)
        {
            vertices.push_back(vertex);
        }

        std::vector<Triangle> &tempT = model.getTriangles();
        for(auto triangle : tempT)
        {
            triangle.v0 += number_of_points;
            triangle.v1 += number_of_points;
            triangle.v2 += number_of_points;
            triangles.push_back(triangle);
        }
        number_of_points = vertices.size();
    }
    
    m_vao.bind();
    m_vbo.setData(&vertices);
    m_ebo.setData(&triangles);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glDrawElements(GL_TRIANGLES, triangles.size() * 3, GL_UNSIGNED_INT, 0);
    */
} // end render

void Renderer::addScene(const Scene &scene)
{
    m_scenes.push_back(scene);
} // end addScene