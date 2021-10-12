#pragma once

#include <map>
#include <any>
#include <vector>
#include "entity.h"
#include "component.h"


//A data oriented ECS-World
class World
{
    friend class Entity;
    private:
        //
        class EntityData
        {
            public:
                /*
                    A vector of maps from component types to indices in the relative componentData sub-vector
                    E.g
                    BoxCollider: 0
                    SpriteRenderer: 5
                    ...
                */
                std::vector<std::map<std::type_info, unsigned int>> indices;
                bool alive;
        };
        /*
        This map will map a component typeID to a component
            {
                vector<BoxCollider> {....}
                vector<Health> {......}
                vector<SpriteRenderer> {....}
            }
        */
        std::map<std::type_info, Component> components;
        std::vector<EntityData> entities;

        template <class T>
        void addComponent();

        template <class T>
        void getComponent();

        template <class T>
        void removeComponent();
    public:
        //Create an entity
        //A "Constructor" if you want
        Entity entity();

        void init();
        void update();

        template <class T>
        void addSystem();
};