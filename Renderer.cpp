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

Renderer::Renderer(Display &display):
    m_display(display)
{

} // end default constructor

Renderer::~Renderer()
{

} // end destructor

void Renderer::startRendering()
{
    glEnable(GL_DEPTH_TEST); 

    while(!m_display.shouldClose()) 
    {
        render();
    } // end while
} // end startRendering

void Renderer::render()
{
    glClearColor(0.0f, 0.6f, 0.6f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Compute dt
    // Render models from the scene

    m_display.update();
} // end render