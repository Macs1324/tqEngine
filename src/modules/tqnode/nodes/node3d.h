#pragma once
#include <glm/glm.hpp>

#include "../node.h"

class Node3D : public Node
{
    public:
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
};