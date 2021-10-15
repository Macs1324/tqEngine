#pragma once

class GameObject;

class Component
{
    private:
        friend class GameObject;
        GameObject* parent;
    public:
        virtual void start() = 0;
        virtual void update(float delta) = 0;

        template <class T>
        T& getComponent()
        {
            return parent->getComponent<T>();
        }
};