/**
 * @file Shader.h
 * Created on 01/23/2023
 * 
 * A helper class to manage shaders that will be used in our OpenGL application.
 * It can read the shaders from the disk, compile and link them, as well as checks 
 * for errors. The standard for this application is that the shader file has the 
 * extension '.shader' but any text file will work.
 * 
 * Main class functions are taken from Learn OpenGL: https://learnopengl.com/Getting-started/Shaders
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _SHADER_H_
#define _SHADER_H_

#include <glad/glad.h>
#include <string>

class Shader {
    public:
        // Constructor
        Shader(const std::string &vertex_shader_file, const std::string &fragment_shader_file);

        // Destructor
        ~Shader();

        // use/activate the shader
        void use();

        unsigned int getID();

        // utility uniform functions
        /*
        void setBool(const std::string &name, bool value) const;  
        void setInt(const std::string &name, int value) const;   
        void setFloat(const std::string &name, float value) const;
        */
    private:
        // Program ID
        unsigned int id;

        // Utility error checking method
        void checkCompileErrors(unsigned int shader, std::string type);
}; // end Shader class

#endif