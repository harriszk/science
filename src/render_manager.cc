// @file render_manager.cc
// Created on 09/08/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render_manager.h"

#include "logger.h"

// Include glm headers
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

RenderManager::RenderManager(Display& display) : shader_("vertex_shader_source.glsl", "fragment_shader_source.glsl"){
  glGenFramebuffers(1, &fbo_);
  glBindFramebuffer(GL_FRAMEBUFFER, fbo_);

  glGenTextures(1, &texture_id_);
  glBindTexture(GL_TEXTURE_2D, texture_id_);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, display.get_width(), display.get_height(), 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture_id_, 0);

  glGenRenderbuffers(1, &rbo_);
  glBindRenderbuffer(GL_RENDERBUFFER, rbo_);
  glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, display.get_width(), display.get_height());
  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo_);

  if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
    LOG_ERROR("ERROR::FRAMEBUFFER:: Framebuffer is not complete!");
  }
    
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  glBindTexture(GL_TEXTURE_2D, 0);
  glBindRenderbuffer(GL_RENDERBUFFER, 0);

  ////////////////
  
  float cubeVertices[] = {
    // Front face
    -0.5f, -0.5f, 0.5f,
     0.5f, -0.5f, 0.5f,
     0.5f,  0.5f, 0.5f,
    -0.5f, -0.5f, 0.5f,
     0.5f,  0.5f, 0.5f,
    -0.5f,  0.5f, 0.5f,

    // Back face
    -0.5f, -0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,

    // Left face
    -0.5f, -0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f,  0.5f,

    // Right face
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,

    // Top face
    -0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,

    // Bottom face
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f
  };

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);

  // Bind the Vertex Array Object first
  glBindVertexArray(VAO);

  // Bind and set vertex buffer
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

  // Configure vertex attributes
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // Unbind the VBO (safe to unbind after configuration)
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Unbind the VAO
  glBindVertexArray(0);

}

RenderManager::~RenderManager() {

}

void RenderManager::Render() {
  glBindFramebuffer(GL_FRAMEBUFFER, fbo_);

  glClearColor(173.0f/255.0f, 216.0f/255.0f, 230.0f/255.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Calculate the model matrix to apply a rotation
  glm::mat4 view          = glm::mat4(1.0f);
  glm::mat4 projection    = glm::mat4(1.0f);
  glm::mat4 model = glm::mat4(1.0f);
  float angle = static_cast<float>(glfwGetTime()) * glm::radians(45.0f); // Rotate 45 degrees per second
  model = glm::rotate(model, angle, glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate around the Y-axis

  // Use the shader
  shader_.Use();

  // Get the shader program ID (assuming it's a member variable)
  GLuint shaderProgram = shader_.get_id();

  // Get the location of the "model" uniform variable in the shader
  GLint modelLoc = glGetUniformLocation(shaderProgram, "model");

  // Set the "model" uniform in the shader
  glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

  // retrieve the matrix uniform locations
  uint32_t view_location  = glGetUniformLocation(shader_.get_id(), "view");
  uint32_t projection_location  = glGetUniformLocation(shader_.get_id(), "projection");
  // pass them to the shaders
  //glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));
  glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));
  glUniformMatrix4fv(projection_location, 1, GL_FALSE, glm::value_ptr(projection));

  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 36); // 36 vertices for the cube

  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}