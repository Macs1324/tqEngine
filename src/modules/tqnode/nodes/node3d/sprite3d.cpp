#pragma once
#include <string>
#include "sprite3d.h"
#include <GL/glew.h>
// #define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

void Sprite3D::start()
{
    glGenTextures(1, &textureID);
            glGenBuffers(1, &VBO);
            glGenBuffers(1, &EBO);
            glGenVertexArrays(1, &VAO);

            glBindTexture(GL_TEXTURE_2D, textureID);
            glBindVertexArray(VAO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

            float vertices[] = {
                //Position
                 1.0,  1.0, 0.0,
                 1.0, -1.0, 0.0,
                -1.0, -1.0, 0.0,
                -1.0,  1.0, 0.0
            };

            unsigned int indices[] = {
                0, 1, 2,
                0, 2, 3
            };

            glBindVertexArray(VAO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
            glVertexAttribPointer(0, 3 * sizeof(float), GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);


            imageData = stbi_load(filename.c_str(), &imageWidth, &imageHeight, &imageChannels, 0);
            if(imageData)
            {
                glBindTexture(GL_TEXTURE_2D, textureID);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
                glGenerateMipmap(GL_TEXTURE_2D);
            }
            else
            {
                std::cout << "Failed to load image data!" << std::endl;
            }
};