#ifndef TREENODE_CPP
#define TREENODE_CPP
#include <iostream>
#include "treenode.hpp"

TreeNode::TreeNode(int value = 0)
{
    this->value = value;    // Dugumun  elemani
    this->rightNode = NULL; // baglanacagi sag dugum
    this->leftNode = NULL;  // baglanacagi sol dugum
}

#endif
