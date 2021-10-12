#pragma once

// #include "entity.h"
class Entity;

//The component interface
//Every component MUST inherit from this
class Component
{
    public:
        Entity parent;
        bool alive;
        unsigned int generation;
};