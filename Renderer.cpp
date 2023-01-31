/**
 * @file Renderer.cpp
 * Created on 01/30/2023
 * 
 * Implementation fo the Renderer class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "Renderer.h"

Renderer::Renderer(Display &display, Shader &shader):
    m_display(display),
    m_shader(shader)
{
    model.addVertex({-0.5f, -0.5f, 0.0f});
    model.addVertex({0.5f, -0.5f, 0.0f});
    model.addVertex({0.0f, 0.5f, 0.0f});

    model.addTriangle({0, 1, 2});
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
    model.render();

    m_display.update();
} // end render