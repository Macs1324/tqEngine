#include <vector>
#include <string>
#include "nodeBehaviour.h"

class Node
{
    private:
        Node* parent;
        std::vector<Node*> children;
        NodeBehaviour* behaviour;
    public:
        //The name of the node
        //Useful for UI and shit
        std::string nodeName;
        //The number of children the node has
        //Make sure to always update it when adding / removing children!
        unsigned int nrChildren;
        //Constructor
        Node();
        //Pointer to the parent of the node
        Node* getParent();
        //Pointer to the i-th child of the node
        Node* getChild(int index);

        //Start virtual function
        //Used by derived classes
        void start();
        //Update virtual function
        //Used by derived classes
        void update(float delta);

        //Method to add a child
        void addChild(Node* newChild);
        //Method to add a NodeBehaviour object (a script basically)
        void setBehaviour(NodeBehaviour* behaviour);

        //Method that gets a pointer to the 
        //NodeBehaviour of the node
        template <class B>
        B* getBehaviour()
        {
            return dynamic_cast<B*>(behaviour);        
        }
};