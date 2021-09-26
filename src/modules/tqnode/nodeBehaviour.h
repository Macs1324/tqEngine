#pragma once

class NodeBehaviour
{
    public:
        virtual void start() = 0;
        virtual void update(float delta) = 0;
};