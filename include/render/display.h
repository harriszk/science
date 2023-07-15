// @file display.h
// Created on 01/16/2023
// 
// This class creates and manages a GLFW window.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "controller.h"
#include "renderer.h"

class Display {
  public:
    // Default constructor.
    // 
    // @param[in] width     The width of the window
    // @param[in] height    The height of the window
    // @param[in] title     The title of the window
    Display(int width, int height, const char* title);

    // Destructor
    ~Display();

    // Creates the GLFW window and initializes GLAD.
    // 
    // @param[in] width     The width of the window
    // @param[in] height    The height of the window
    // @param[in] title     The title of the window
    // 
    // @return true     The window was successfully created.
    // @return false    The window wasn't successfully created.
    bool CreateWindow(int width, int height, const char *title);

    // 
    void Start();

    // 
    void PaintFrame();

    // 
    // 
    // @return true 
    // @return false 
    bool ShouldClose();

    // Toggles the visibility of the window.
    // 
    void ToggleWindow();

    // Updates the window by processing pending events
    // and swapping buffers.
    // 
    void Update();

    // Destroys the window and cleans up GLFW and GLAD.
    // ** Maybe this should just be the destructor? **
    void Destroy();

    // Sets the title of the window.
    // 
    // @param[in] title The title of the window
    void set_title(const char *title);

    // 
    // 
    // @param[in] renderer 
    void set_renderer(Renderer *renderer);

    // 
    // 
    // @param[in] controller 
    void set_controller(Controller* controller);
    
    // Get the width
    // 
    // @return int 
    int get_width();

    // Get the height
    // 
    // @return int 
    int get_height();

    // 
    // 
    void ProcessInput();

    // 
    // 
    // @param[in] window 
    // @param[in] width 
    // @param[in] height 
    static void ScreenSizeCallback(GLFWwindow* window, int width, int height);
  private:
    // Pointer to the GLFW window.
    GLFWwindow* window_;

    // 
    Renderer* renderer_;

    // 
    Controller* controller_;

    // Boolean indicating if the window is open or not.
    bool is_open_;

    // The change in time since the last frame.
    float dt_;

    // Time since the last frame
    float last_frame_;

    // The vertical position of the cursor.
    double x_pos_;

    // The horizontal position of the cursor.
    double y_pos_;

    //
    GLuint fbo_;

    // 
    GLuint rbo_;

    // 
    GLuint texture_id_;
};

#endif