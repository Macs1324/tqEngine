#include "ecsWorld.h"

template <class T>
void World::addComponent(Entity entity)
{
    components[typeid(T)].alive = true;
    components[typeid(T)].generation = 0;
}

Entity World::entity()
{
    Entity r;
    r.index = -1;
    r.generation = -1;
    int size = entities.size();
    for(int i = 0; i < size; i++)
    {
        if(!entities[i].alive)
        {
            r.index = i;
            break;
        }
    }

    //If the index has remained -1 itr means that
    //a free memory spot could not be found
    if(r.index == -1)
    {
        r.index = size;
        r.generation = 0;
    }
}

template <class T>
void World::addSystem(System<T> system)
{
    systems.push_back(system);
}