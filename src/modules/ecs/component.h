#pragma once

#include "entity.h"


//The component interface
//Every component MUST inherit from this
class Component
{
    public:
        Entity parent;
        bool alive;
        unsigned int generation;
};