#version 330 core
layout (location = 0) in vec3 aPos;
out vec4 FragColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // Apply the model, view, and projection transformations
    mat4 MVP = projection * view * model;
    gl_Position = MVP * vec4(aPos, 1.0);
}