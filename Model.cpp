/**
 * @file Model.cpp
 * Created on 01/23/2023
 * 
 * Implemenation of Model class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Model.h"
#include <iostream>

Model::Model(const char *name):
    name(name),
    texture(0)
{
    
} // end default constructor

Model::Model(const Model & model)
{

} // end copy constructor

Model::~Model()
{

} // end destructor

bool Model::addVertex(const Vertex & v)
{
    this->vertices.push_back(v);

    // TODO: Check if a vertex with same positions is already apart of the model.

    return true;
} // end addVertex

bool Model::addTriangle(const Triangle & t)
{
    this->triangles.push_back(t);

    // TODO: Check if triangle with same indices is already apart of the model.

    return true;
} // end addTriangle

std::string Model::getName() const
{
    return this->name;
} // end getName

size_t Model::getNumberOfVertices() const 
{
    return this->vertices.size();
} // end getNumberOfVertices

size_t Model::getNumberOfTriangles() const
{
    return this->triangles.size();
}

bool Model::loadTexture(const char * file)
{
    glGenTextures(1, &this->texture);
    glBindTexture(GL_TEXTURE_2D, this->texture);

    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    bool response;

    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load(file, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        response = true;
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
        response = false;
    }
    stbi_image_free(data);
    return response;
}

void Model::draw(float dt)
{
    //this->vertices[0][0] = sin(dt);
    //this->vertices[0][1] = cos(dt)/2;

    // Playing around with changing vertex colors
    if(dt != 0)
    {
        for(Vertex & v : vertices)
        {
            v.r = sin(dt);
            v.b = abs(cos(dt)) - 0.25f;
            v.g = sin(dt);
        }
    }

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO); 
    glGenBuffers(1, &EBO);

    // ..:: Initialization code (done once (unless your object frequently changes)) :: ..
    // 1. bind Vertex Array Object
    glBindVertexArray(VAO);
    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(Vertex), &this->vertices.front(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->triangles.size() * sizeof(Triangle), &this->triangles.front(), GL_STATIC_DRAW);

    // 3. then set our vertex attributes pointers
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2); 

    glBindTexture(GL_TEXTURE_2D, this->texture);
    
    

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, this->triangles.size() * 3, GL_UNSIGNED_INT, 0);
}