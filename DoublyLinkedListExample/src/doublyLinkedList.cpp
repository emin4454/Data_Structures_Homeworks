#ifndef doublyLinkedList_cpp
#define doublyLinkedList_cpp
#include <iostream>
#include "doublyLinkedList.hpp"

int doublyNode::nodeCount = 0;
doublyNode *doublyNode::rootNode = nullptr;

doublyNode ::doublyNode(int num)
{
    this->nextNode = nullptr;
    this->previousNode = nullptr;
    this->value = num;
    if (nodeCount == 0)
    {
        rootNode = this;
        nodeCount++;
        std::cout << "prev: " << rootNode->previousNode << "  current: " << rootNode << "  next: " << rootNode->nextNode << " value: " << rootNode->value << std::endl;
    }
}
void doublyNode::addNode(int num)
{
    nodeCount++;
    doublyNode *lastNode = goToLastNode();
    lastNode->nextNode = new doublyNode(num);
    lastNode->nextNode->previousNode = lastNode;
    lastNode = lastNode->nextNode;
    std::cout << "prev: " << lastNode->previousNode << "  current: " << lastNode << "  next: " << lastNode->nextNode << " value: " << lastNode->value << std::endl;
}

int doublyNode::getNodeCount()
{
    return nodeCount;
}

doublyNode *doublyNode::goToLastNode()
{
    doublyNode *currentNode = rootNode;
    while (currentNode->nextNode != nullptr)
    {
        currentNode = currentNode->nextNode;
    }
    return currentNode;
}

void doublyNode::printAllNodes()
{
    doublyNode *currentNode = rootNode;
    while (currentNode != nullptr)
    {
        std::cout << "prev: " << currentNode->previousNode << "  current: " << currentNode << "  next: " << currentNode->nextNode << " value: " << currentNode->value << std::endl;
        currentNode = currentNode->nextNode;
    }
}
#endif