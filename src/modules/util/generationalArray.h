#pragma once

#include <vector>

/*
    A CLASS THAT IMPLEMENTS THE GENERATIONAL ARRAY PATTERN

    USEFUL FOR STORING DATA IN THE ECS
    AND USING MEMORY IN AN OPTIMAL WAY
*/

class GenerationalIndex
{
    public:
        friend class Entity;

        unsigned int index;
        unsigned int generation;
};


template <class T>
class GenerationalArray
{
    private:
        template <class T1>
        class Entry
        {
            public:
                T1 value;
                unsigned int generation;
                bool alive;
        };
        std::vector<Entry<T>> data;

    public:
        GenerationalIndex push(T value);
        T& get(GenerationalIndex index);
        void free(GenerationalIndex& index);

        T& operator[](GenerationalIndex index);
};

// #include "generationalArray.cpp"