#pragma once

#include <map>
#include <vector>
#include <typeindex>
#include "../util/generationalArray.h"
#include "component.h"
#include "system.h"

class Entity;

//A data oriented ECS-World
class World
{
    private:
        friend class Entity;
        class EntityData
        {
            public:
                /*
                    A map that maps component types to (Generational)indices in the relative componentData sub-vector
                    E.g              index  generation 
                    BoxCollider:      0    |     2
                    SpriteRenderer:   5    |     0
                    ...
                */
                std::map<std::type_index, GenerationalIndex> indices;
        };
        /*
        This map will map a component typeID to a Generational Array of components
            {
                vector<BoxCollider> {....}
                vector<Health> {......}
                vector<SpriteRenderer> {....}
            }
        */
        std::map<std::type_index, GenerationalArray<Component>> components;
        GenerationalArray<EntityData> entities;

        //A vector and not a generational array bc I don't plan on
        //randomly adding / removing systems
        std::vector<System<Component>> systems;

    public:
        template <class T>
        void addComponent(Entity* entity);
        // {
        //     T newComponent;
        //     ((Component)(newComponent)).parent = entity;
        //     components[typeid(T)].push(newComponent);
        // }

        template <class T>
        T& getComponent(Entity entity);
        // {
        //     return components[typeid(T)][entity.index];
        // }

        template <class T>
        void removeComponent(Entity entity);
        // {
        //     components[typeid(T)].free(entity.index);
        // }
        //Create an entity
        //A "Constructor" if you want
        Entity entity();
        // {
        //     Entity r;
        //     EntityData entityData;
        //     GenerationalIndex index = entities.push(entityData);
        //     r.index = index;
        //     r.world = this;

        //     return r;
        // }
        void init();
        void update();

        template <class T>
        void addSystem(System<T> system)
        {
            systems.push_back(system);
        }
};

#include "ecsWorld.cpp"