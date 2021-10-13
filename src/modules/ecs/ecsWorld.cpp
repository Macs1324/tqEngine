#include "ecsWorld.h"

template <class T>
void World::addComponent(Entity* entity)
{
    T newComponent;
    dynamic_cast<Component*>(&newComponent)->parent = entity;
    GenerationalIndex i = components[typeid(T)].push(newComponent);
    entities[entity->index].indices[typeid(T)] = i;
}
// FUCKING USE THE ENTITY DATA INDEX INSTEAD OF THE 
// ENTITY HANDLE INDEX IDIOT
template <class T>
T& World::getComponent(Entity entity)
{
    return (T&)(components[typeid(T)][entities[entity.index].indices[typeid(T)]]);
}


template <class T>
void World::removeComponent(Entity entity)
{
    components[typeid(T)].free(entity.index);
}

Entity World::entity()
{
    Entity r;
    EntityData entityData;
    GenerationalIndex index = entities.push(entityData);
    r.index = index;

    return r;
}