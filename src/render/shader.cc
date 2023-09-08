// @file shader.cc
// Created on 01/23/2023
// 
// Implementation of the Shader class.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/shader.h"

#include <fstream>
#include <sstream>

#include "logger.h"

Shader::Shader(const std::string& vertex_file, const std::string& fragment_file) {
  // Create strings to hold the shader source code
  std::string vertex_shader_source, fragment_shader_source;

  std::string full_vertex_path = std::string(SHADER_BASE_DIRECTORY) + vertex_file;
  std::string full_fragment_path = std::string(SHADER_BASE_DIRECTORY) + fragment_file;

  // Open the vertex and fragment shader files
  std::ifstream vertex_shader_file_stream(full_vertex_path);
  std::ifstream fragment_shader_file_stream(full_fragment_path);

  // Check if the files were successfully opened
  if (!vertex_shader_file_stream.is_open()) {
    LOG_ERROR("ERROR::VERTEX::SHADER::FILE_NOT_SUCCESSFULLY_READ: {0}", vertex_file);
    return;
  } // end if

  if (!fragment_shader_file_stream.is_open()) {
    LOG_ERROR("ERROR::FRAGMENT::SHADER::FILE_NOT_SUCCESSFULLY_READ: {0}", fragment_file);
    return;
  } // end if

  // Read the contents of the files into stringstream
  std::stringstream vertex_shader_stream, fragment_shader_stream;
  vertex_shader_stream << vertex_shader_file_stream.rdbuf();
  fragment_shader_stream << fragment_shader_file_stream.rdbuf();

  // Close the file streams
  vertex_shader_file_stream.close();
  fragment_shader_file_stream.close();

  // Extract the contents of the stringstream as strings
  vertex_shader_source = vertex_shader_stream.str();
  fragment_shader_source = fragment_shader_stream.str();

  // Convert to const chars
  const char* vertex_shader_code = vertex_shader_source.c_str();
  const char* fragment_shader_code = fragment_shader_source.c_str();

  LOG_INFO("Vertex Shader Code: \n{0} \n\nFragment Shader Code: \n{1}", vertex_shader_code, fragment_shader_code);

  unsigned int vertex_shader, fragment_shader;

  // Compile vertex shader
  vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, &vertex_shader_code, NULL);
  glCompileShader(vertex_shader);    
  CheckCompileErrors(vertex_shader, "VERTEX");

  // Compile fragment shader
  fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, &fragment_shader_code, NULL);
  glCompileShader(fragment_shader);
  CheckCompileErrors(fragment_shader, "FRAGMENT");

  // Shader program
  id_ = glCreateProgram();
  glAttachShader(id_, vertex_shader);
  glAttachShader(id_, fragment_shader);
  glLinkProgram(id_);
  CheckCompileErrors(id_, "PROGRAM");

  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);
} // end constructor

Shader::~Shader() {
  glDeleteProgram(id_);
}

void Shader::Use() {
  glUseProgram(id_);
}

unsigned int Shader::get_id() {
  return id_;
}

void Shader::CheckCompileErrors(unsigned int shader, std::string type) {
  int success;
  char info_log[1024];

  if (type == "PROGRAM") {
    glGetProgramiv(shader, GL_LINK_STATUS, &success);

    if (!success) {
      glGetProgramInfoLog(shader, 1024, NULL, info_log);
      LOG_ERROR("ERROR::PROGRAM_LINKING_ERROR of type: {0}", type); 
      LOG_ERROR("{0}", info_log);
    }

    return;
  } 
  
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(shader, 1024, NULL, info_log);
    LOG_ERROR("ERROR::SHADER_COMPILATION_ERROR of type: {0}", type);
    LOG_ERROR("{0}", info_log);
  }
}