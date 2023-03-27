/**
 * @file Renderer.cpp
 * Created on 01/30/2023
 * 
 * Implementation fo the Renderer class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "../../include/render/Renderer.h"
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Renderer::Renderer(Shader &shader):
    m_shader(shader),
    m_width(800),
    m_height(600)
{

} // end default constructor

Renderer::~Renderer()
{

} // end destructor

void Renderer::render()
{
    glClearColor(0.0f, 0.6f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_shader.use();

    // create transformations
    //glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 view          = glm::mat4(1.0f);
    glm::mat4 projection    = glm::mat4(1.0f);
    //model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
    //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    //view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
    projection = glm::perspective(glm::radians(45.0f), float(m_width) / float(m_height), 0.1f, 100.0f);

    glm::mat4 view = m_scenes.at(0)->getViewMatrix();

    // retrieve the matrix uniform locations
    uint32_t modelLoc = glGetUniformLocation(m_shader.getID(), "model");
    uint32_t viewLoc  = glGetUniformLocation(m_shader.getID(), "view");
    uint32_t projectionLoc  = glGetUniformLocation(m_shader.getID(), "projection");
    // pass them to the shaders
    //glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));
    
    // Render models from the scene
    auto &renderables = m_scenes.at(0)->getRenderables();
    for (auto &renderable : renderables) {
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(renderable->getModelMatrix()));
        renderable->render();
    } // end for

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

void Renderer::addScene(Scene *scene)
{
    m_scenes.push_back(scene);
} // end addScene

void Renderer::setWidth(int width)
{
    m_width = width;
} // end setWidth

void Renderer::setHeight(int height)
{
    m_height = height;
} // end setHeight