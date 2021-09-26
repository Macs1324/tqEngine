#pragma once
#include <string>
#include "sprite3d.h"
#include <GL/glew.h>
#include <stb_image.h>

void Sprite3D::start()
{
    glGenTextures(1, &textureID);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);

    stbi_load(filename.c_str(), &imageWidth, &imageHeight, &imageChannels, 0);
};