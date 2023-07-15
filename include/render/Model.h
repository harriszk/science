// @file model.h
// Created on 01/29/2023
// 
// This class represents an object in the world that may be either 2D or 3D. It 
// contains information about the geometry and appearance of the object, including 
// its vertices, normals, textures, and material properties.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _MODEL_H_
#define _MODEL_H_

#include <vector>

#include "glm/glm.hpp"

#include "renderable.h"

class Model : public Renderable {
  public:
    // Default constructor. 
    // 
    // Creates an empty model, ready to have vertices and triangles added.
    Model();

    // Destructor.
    virtual ~Model();

    
    // Adds a vertex to the model.
    // 
    // @param[in] vertex The vertex to be added to the model.
    // @return true The vertex was added successfully.
    // @return false The vertex could not be added (e.g. because it is invalid).
    bool AddVertex(const Vertex &vertex);

    
    // Adds a triangle to the model.
    // 
    // @param[in] triangle The triangle to be added to the model.
    // @return true The triangle was added successfully.
    // @return false The triangle could not be added (e.g. because it is invalid).
    bool AddTriangle(const Triangle &triangle);

    
    // Returns a reference to the collection of vertices that make up the model.
    // 
    // @return std::vector<Vertex>& 
    std::vector<Vertex>& get_vertices();

    
    // Returns a reference to the collection of triangles that make up the model.
    // 
    // @return std::vector<Triangle>& 
    std::vector<Triangle>& get_triangles();

    // 
    // 
    // @param[in] filename 
    void LoadModel(const char* filename);

    
    // Renders the model.
    virtual void Render() override;
    
  private:
    // Uploads the model to the GPU.
    // This method should be called whenever the model has changed and needs
    // to be reuploaded.
    void Upload();

    // A flag indicating whether the model has changed and need to be reuploaded to the GPU.
    bool has_changed_;
};

#endif