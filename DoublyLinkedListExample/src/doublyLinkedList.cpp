#ifndef doublyLinkedList_cpp
#define doublyLinkedList_cpp
#include <iostream>
#include "doublyLinkedList.hpp"

int doublyNode::nodeCount = 0;
doublyNode *doublyNode::rootNode = nullptr;

doublyNode ::doublyNode(int num = 0)
{
    this->upNode = nullptr;
    this->downNode = nullptr;
    this->value = -9999; // Hiç bir veri atanılmadığı anlamına gelir
    if (nodeCount == 0)
    {
        rootNode = this;
        nodeCount++;
        // std::cout << "prev: " << rootNode->downNode << "  current: " << rootNode << "  next: " << rootNode->upNode << " value: " << rootNode->value << std::endl;
    }
    else
        this->value = num;
}
void doublyNode::addNodeToUp(int num)
{
    nodeCount++;
    doublyNode *lastNode = goToUpLastNode();
    lastNode->upNode = new doublyNode(num);
    lastNode = lastNode->upNode;
    // std::cout << "prev: " << lastNode->downNode << "  current: " << lastNode << "  next: " << lastNode->upNode << " value: " << lastNode->value << std::endl;
}

void doublyNode::addNodeToDown(int num)
{
    nodeCount++;
    doublyNode *lastNode = goToDownLastNode();
    lastNode->downNode = new doublyNode(num);
    lastNode = lastNode->upNode;
    // std::cout << "prev: " << lastNode->downNode << "  current: " << lastNode << "  next: " << lastNode->upNode << " value: " << lastNode->value << std::endl;
}

int doublyNode::getNodeCount()
{
    return nodeCount;
}

doublyNode *doublyNode::goToUpLastNode()
{
    doublyNode *currentNode = rootNode;
    while (currentNode->upNode != nullptr)
    {
        currentNode = currentNode->upNode;
    }
    return currentNode;
}

doublyNode *doublyNode::goToDownLastNode()
{
    doublyNode *currentNode = rootNode;
    while (currentNode->downNode != nullptr)
    {
        currentNode = currentNode->downNode;
    }
    return currentNode;
}

void doublyNode::printAllUpNodes()
{

    doublyNode *currentNode = rootNode;
    std::cout << "RootNode = " << currentNode << std::endl;
    while (currentNode != nullptr)
    {
        std::cout << "DownNode: " << currentNode->downNode << "  currentNode: " << currentNode << "  UpNode: " << currentNode->upNode << " value: " << currentNode->value << std::endl;
        currentNode = currentNode->upNode;
    }
}

void doublyNode::printAllDownNodes()
{
    doublyNode *currentNode = rootNode;
    std::cout << "RootNode = " << currentNode << std::endl;
    while (currentNode != nullptr)
    {
        std::cout << "DownNode: " << currentNode->downNode << "  currentNode: " << currentNode << "  UpNode: " << currentNode->upNode << " value: " << currentNode->value << std::endl;
        currentNode = currentNode->downNode;
    }
}

doublyNode *doublyNode::goToUpNode()
{
    return this->upNode;
}

doublyNode *doublyNode::goToDownNode()
{
    return this->downNode;
}

int doublyNode::getValue()
{
    return this->value;
}
#endif