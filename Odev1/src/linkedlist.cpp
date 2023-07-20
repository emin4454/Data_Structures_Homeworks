#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include <iostream>
#include "linkedlist.hpp"
#include "node.hpp"

LinkedList::LinkedList()
{
    rootNode = nullptr;
    nodeCount = 0;
}
void LinkedList::addNode(int num)
{
    if (nodeCount == 0)
    {
        rootNode = new Node(num);
        nodeCount++;
    }
    else
    {
        Node *lastNode = goToLastNode();
        lastNode->nextNode = new Node(num);
        nodeCount++;
    }
}

int LinkedList::getNodeCount()
{
    return nodeCount;
}

void LinkedList::printAllNodes()
{
    Node *currentNode = rootNode;
    // std::cout << "RootNode = " << currentNode << std::endl;
    while (currentNode != nullptr)
    {
        // std::cout << "currentNode: " << currentNode << "  nextNode: " << currentNode->nextNode << " value: " << currentNode->value << std::endl;
        std::cout << currentNode->value << " - ";
        currentNode = currentNode->nextNode;
    }
    std::cout << "null";
    std::cout << std::endl;
}

Node *LinkedList::goToLastNode()
{
    Node *currentNode = rootNode;
    while (currentNode->nextNode != NULL)
    {
        currentNode = currentNode->nextNode;
    }
    return currentNode;
}

LinkedList *LinkedList::copyList()
{
    LinkedList *newList = new LinkedList();
    Node *currentNode = rootNode;
    while (currentNode != NULL)
    {
        newList->addNode(currentNode->value);
        currentNode = currentNode->nextNode;
    }
    return newList;
}

Node *LinkedList::getRootNode()
{
    return rootNode;
}
void LinkedList::setRootNode(Node *newNode)
{
    rootNode = newNode;
}
#endif

int LinkedList::getValueByIndex(int index)
{
    if (index > nodeCount - 1)
    {
        return -557; // out of range -- Algoritmada kullanilacak
    }
    else
    {
        Node *currentNode = rootNode;
        for (int i = 0; i < index; i++)
        {
            currentNode = currentNode->nextNode;
        }
        return currentNode->value;
    }
}