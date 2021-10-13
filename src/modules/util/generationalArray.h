#pragma once
#include <iostream>
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
        GenerationalIndex push(T value)
        {
            GenerationalIndex r;
            r.index = -1;
            r.generation = -1;
            unsigned int size = data.size();
            for(int i = 0; i < size; i++)
            {
                //If a dead (freed) entry was found overwrite it with
                //an empty one
                if(!data[i].alive)
                {

                    data[i].value = value;
                    data[i].alive = true;

                    r.index = i;
                    r.generation = data[i].generation;
                    break;
                }
            }

            //If no dead entries were found expand the data vector
            if(r.index == -1)
            {
                Entry<T> val;
                val.value = value;
                val.generation = 0;
                val.alive = true;

                data.push_back(val);

                r.index = size;
                r.generation = 0;
            }

            return r;
        }
        T& get(GenerationalIndex index)
        {
            std::cout << "Debugging generations " << std::endl;
            std::cout << index.generation << " | " << data[index.index].generation << std::endl;
            
            if(data[index.index].alive)
            {
                if(data[index.index].generation == index.generation)
                {
                    return data[index.index].value;
                }
                else
                {
                    std::cout << "Generations do not match!" << std::endl;
                }
            }
            else
            {
                std::cout << "Using a dead handle" << std::endl;
            }

            return *(T*)nullptr;
        }
        void free(GenerationalIndex& index)
        {
            data[index.index].alive = false;
            data[index.index].generation++;
        }

        T& operator[](GenerationalIndex index)
        {
            return get(index);
        }
};

// #include "generationalArray.cpp"