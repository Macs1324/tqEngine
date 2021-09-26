#include "node.h"

/*

        MORE INFO IN THE node.cpp FILE

*/

Node::Node()
{
    parent = nullptr;
    nrChildren = 0;
    behaviour = nullptr;
}

Node* Node::getParent()
{
    return parent;
}

Node* Node::getChild(int index)
{
    return children[index];
}

void Node::addChild(Node* newChild)
{
    children.push_back(newChild);
    nrChildren++;
}


void Node::setBehaviour(NodeBehaviour* newBehaviour)
{
    behaviour = newBehaviour;
}