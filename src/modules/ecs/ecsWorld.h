#pragma once

#include <map>
#include <any>
#include <vector>
#include "entity.h"
#include "component.h"
#include "system.h"

//A data oriented ECS-World
class World
{
    private:
        friend class Entity;
        class EntityData
        {
            public:
                //Should the entity be freed? Probably not
                bool alive;
                //The generation of the entity: if it doesn't correspond to
                //the handle then something went wrong
                unsigned int generation;
                /*
                    A vector of maps from component types to indices in the relative componentData sub-vector
                    E.g
                    BoxCollider: 0
                    SpriteRenderer: 5
                    ...
                */
                std::vector<std::map<std::type_info, unsigned int>> indices;
        };
        /*
        This map will map a component typeID to a component
            {
                vector<BoxCollider> {....}
                vector<Health> {......}
                vector<SpriteRenderer> {....}
            }
        */
        std::vector<EntityData> entities;
        std::map<std::type_info, Component> components;
        std::vector<System<std::any>> systems;

        template <class T>
        void addComponent(Entity entity);

        template <class T>
        void getComponent(Entity entity);

        template <class T>
        void removeComponent(Entity entity);
    public:
        //Create an entity
        //A "Constructor" if you want
        Entity entity();

        void init();
        void update();

        template <class T>
        void addSystem(System<T> system);
};