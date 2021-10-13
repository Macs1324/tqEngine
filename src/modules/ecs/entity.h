#pragma once


#include "../util/generationalArray.h"
#include "ecsWorld.h"

class World;


//A Generational index for the ecsWorld
//Basically handles for entities
class Entity
{
    public:
        friend class World;
        //A pointer to the world the entity is in
        // World* world;
        GenerationalIndex index;
    public:

        // template <class T>
        // T& getComponent();

        // template <class T>
        // void addComponent();

        // template <class T>
        // void removeComponent();
};

#include "entity.cpp"
