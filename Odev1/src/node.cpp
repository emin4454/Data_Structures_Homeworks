#ifndef NODE_CPP
#define NODE_CPP
#include "node.hpp"

Node::Node(int value = 0)
{
    this->value = value;
    this->nextNode = nullptr;
}

#endif
