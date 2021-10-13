#include "generationalArray.h"

template <class T>
GenerationalIndex GenerationalArray<T>::push(T value)
{
    GenerationalIndex r;
    r.index = -1;
    r.generation = -1;
    size_t int size = data.size();
    for(int i = 0; i < size; i++)
    {
        //If a dead (freed) entry was found overwrite it with
        //an empty one
        if(!data[i].alive)
        {

            data[i].value = value;

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


template <class T>
T& GenerationalArray<T>::get(GenerationalIndex index)
{
    if(data[index.index].alive)
    {
        if(data[index.index].generation == index.generation)
        {
            return data[index.index].value;
        }
    }

    return nullptr;
}

template <class T>
void GenerationalArray<T>::free(GenerationalIndex& index)
{
    data[index.index].alive = false;
}

template <class T>
T& GenerationalArray<T>::operator[](GenerationalIndex index)
{
    return get(index);
}