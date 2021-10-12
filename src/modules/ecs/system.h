#pragma once

#include <vector>

//The basic interface for systems
//Each class mush inherit from it
//When instancing, you'll have to specify which component the
//system is attached to
template <class T>
class System
{
    public:
        void init(std::vector<T> query);
        void update(std::vector<T> query, float deltaTime);
};