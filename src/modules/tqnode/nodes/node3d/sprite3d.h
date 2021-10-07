#pragma once
#include <string>
#include <GL/glew.h>
// #define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>
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

        void start();
        void update(float delta);
};