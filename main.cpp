#include "Model.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include "Shader.h"
#include <glm/glm.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    std::cout << "Window has been resized to (" << width << "x" << height << ")\n";
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char * argv[])
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Shader shader("shaders/vertexShaderSource.shader", "shaders/fragmentShaderSource.shader");

    //int vertexColorLocation = glGetUniformLocation(s.getID(), "ourColor");
    //s.use();
    //glUniform4f(vertexColorLocation, v[0], v[1], v[2], 1.0f);

    Model model("Test");
    model.addVertex({-0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f});
    model.addVertex({-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f});
    model.addVertex({0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f});
    model.addVertex({0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f});

    model.addTriangle({0, 1, 3});
    model.addTriangle({1, 2, 3});

    
    Model model2("Test2");
    model2.addVertex({0.1f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f});
    model2.addVertex({0.1f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f});
    model2.addVertex({0.6f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f});
    model2.addVertex({0.6f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f});

    model2.addTriangle({0, 1, 2});
    model2.addTriangle({0, 2, 3});
    

    // Render loop
    while(!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        model.draw(glfwGetTime());
        model2.draw(0);
        //glBindVertexArray(VAO);
        //glDrawArrays(GL_TRIANGLES, 0, 4);
        //glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    //glDeleteVertexArrays(1, &VAO);
    //glDeleteBuffers(1, &VBO);

    glfwTerminate();
    

    return 0;
}