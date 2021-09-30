#pragma once
#include <string>
#include <GL/glew.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "../node3d.h"

class Sprite3D : public Node3D
{
    private:
        unsigned char* imageData;
        int imageWidth;
        int imageHeight;
        int imageChannels;

        unsigned int textureID;
        unsigned int VBO;
        unsigned int VAO;
        unsigned int EBO;
    public:
        bool visible;
        std::string filename;

        void start()
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
        }

        void update(float delta)
        {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, textureID);

            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBindVertexArray(VAO);

            glDrawArrays(GL_TRIANGLES, 0, 4);
        }
};