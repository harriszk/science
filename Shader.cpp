/**
 * @file Shader.cpp
 * Created on 01/23/2023
 * 
 * Implemenation of the Shader class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(const std::string &vertexFile, const std::string &fragmentFile) {
        // Create strings to hold the shader source code
        std::string vertexShaderSource, fragmentShaderSource;

        // Open the vertex and fragment shader files
        std::ifstream vertexShaderFileStream(vertexFile);
        std::ifstream fragmentShaderFileStream(fragmentFile);

        // Check if the files were successfully opened
        if (!vertexShaderFileStream.is_open()) 
        {
            std::cerr << "ERROR::VERTEX::SHADER::FILE_NOT_SUCCESFULLY_READ: " << vertexFile << std::endl;
            return;
        } // end if

        if (!fragmentShaderFileStream.is_open()) 
        {
            std::cerr << "ERROR::FRAGMENT::SHADER::FILE_NOT_SUCCESFULLY_READ: " << fragmentFile << std::endl;
            return;
        } // end if

        // Read the contents of the files into stringstreams
        std::stringstream vertexShaderStream, fragmentShaderStream;
        vertexShaderStream << vertexShaderFileStream.rdbuf();
        fragmentShaderStream << fragmentShaderFileStream.rdbuf();

        // Close the file streams
        vertexShaderFileStream.close();
        fragmentShaderFileStream.close();

        // Extract the contents of the stringstreams as strings
        vertexShaderSource = vertexShaderStream.str();
        fragmentShaderSource = fragmentShaderStream.str();

        // Convert to C strings
        const char* vertexShaderCode = vertexShaderSource.c_str();
        const char* fragmentShaderCode = fragmentShaderSource.c_str();

        //std::cout << vertexShaderCode << "\n\n" << fragmentShaderCode << std::endl;

        unsigned int vertexShader, fragmentShader;

        // Compile vertex shader
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderCode, NULL);
        glCompileShader(vertexShader);    
        checkCompileErrors(vertexShader, "VERTEX");

        // Compile fragment shader
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderCode, NULL);
        glCompileShader(fragmentShader);
        checkCompileErrors(fragmentShader, "FRAGMENT");

        // Shader program
        this->id = glCreateProgram();
        glAttachShader(this->id, vertexShader);
        glAttachShader(this->id, fragmentShader);
        glLinkProgram(this->id);
        checkCompileErrors(this->id, "PROGRAM");

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
} // end constructor

Shader::~Shader()
{
    glDeleteProgram(this->id);
}

void Shader::use()
{
    glUseProgram(this->id);
} // end use

void Shader::checkCompileErrors(unsigned int shader, std::string type)
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
} // end checkCompileErrors