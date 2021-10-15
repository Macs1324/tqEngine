#pragma once

#include <map>
#include <typeindex>
#include "components/component.h"

class GameObject
{
    private:
        std::map<std::type_index, std::unique_ptr<Component>> components;
    public:
        template <class T>
        void addComponent()
        {
            components[typeid(T)] = std::make_unique<T>();
            components[typeid(T)].get()->parent = this;
        }

        template <class T>
        T& getComponent()
        {
            // return &components.at(typeid(T));
            T* component = dynamic_cast<T*>(components[typeid(T)].get());

            return *component;
        }

        template <class T>
        void removeComponent()
        {
            delete components[typeid(T)];
        }

        void start()
        {
            for (auto it = components.begin(); it != components.end(); ++it) {
                it->second.get()->start();
            }
        }
        void update(float delta)
        {
            for (auto it = components.begin(); it != components.end(); ++it) {
                it->second.get()->update(delta);
            }
        }
};