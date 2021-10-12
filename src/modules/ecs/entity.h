#pragma once

#include "../util/generationalArray.h"
// #include "ecsWorld.h"
class World;


//A Generational index for the ecsWorld
//Basically handles for entities
class Entity
{
    public:
        friend class World;
        //A pointer to the world the entity is in
        World* world;

        //The index of the entity in the world
        unsigned int index;
        //The generation (to handle use after free cases etc etc)
        unsigned int generation;

        GenerationalIndex genIndex;
    public:

        template <class T>
        T getComponent();

        template <class T>
        void addComponent();

        template <class T>
        void removeComponent();
};