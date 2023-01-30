/**
 * @file Renderer.h
 * Created on 01/29/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Display.h"
#include "Scene.h"

class Renderer {
    public:
        /**
         * Default constructor.
         * 
         */
        Renderer();

        // Destructor.
        ~Renderer();

        /**
         * Starts the rendering loop. Continuously draws the scene
         * until the window is closed.
         * 
         */
        void startRendering();

        // Renders the scene.
        void render();
    private:
        // Pointer to an array of scenes
        //Scene *m_scenes;

        // The display used to render to.
        Display m_display;
}; // end Renderer class

#endif