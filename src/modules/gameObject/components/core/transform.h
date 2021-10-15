#pragma once

#include <glm/glm.hpp>
#include "../component.h"

class Transform : public Component
{
    public:
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;

        Transform()
        {
            position = glm::vec3(0.0, 0.0, 0.0);
            rotation = glm::vec3(0.0, 0.0, 0.0);
            scale = glm::vec3(1.0, 1.0, 1.0);
        }

        void translate()
        {

        }

        void start(){}
        void update(float delta){}
};