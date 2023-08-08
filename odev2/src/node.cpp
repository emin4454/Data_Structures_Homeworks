#ifndef NODE_CPP
#define NODE_CPP
#include <iostream>
#include "node.hpp"

Node::Node(int value = 0)
{
    this->value = value;   // Dugumun  elemani
    this->nextNode = NULL; // baglanacagi sonraki dugum
}

#endif
