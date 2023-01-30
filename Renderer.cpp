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
    while(!m_display.shouldClose()) 
    {
        glClearColor(0.0f, 0.6f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        render();
        m_display.update();
    } // end while
} // end startRendering

void Renderer::render()
{
    
} // end render