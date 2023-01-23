/**
 * @file Display.h
 * Created on 01/16/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <stdlib.h>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Display {
    public:
        Display(int width, int height, const char * title);

        ~Display();

        void start();

        int getWidth();

        int getHeight();

    private:
        GLFWwindow* window;
}; // end Display class

#endif