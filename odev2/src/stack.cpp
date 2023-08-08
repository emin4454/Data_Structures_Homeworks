#ifndef STACK_CPP
#define STACK_CPP
#include <iostream>
#include "stack.hpp"
#include "node.hpp"

Stack::Stack()
{
    topOfStack = NULL;
    itemCount = 0;
}
void Stack::push(int num)
{
    if (itemCount == 0)
    {
        topOfStack = new Node(num);
        itemCount++;
    }
    else
    {
        Node *newTop = new Node(num);
        newTop->nextNode = topOfStack;
        topOfStack = newTop;
        itemCount++;
    }
}
int Stack::pop()
{
    if (itemCount == 1)
    {
        int returnvalue = topOfStack->value;
        delete topOfStack;
        topOfStack = NULL;
        itemCount--;
        return returnvalue;
    }
    else if (itemCount == 0)
    {
        throw "ITEM YOK";
    }
    else
    {
        Node *otof = topOfStack;
        topOfStack = topOfStack->nextNode;
        int returnValue = otof->value;
        delete otof;
        itemCount--;
        return returnValue;
    }
}

int Stack::getNodeCount()
{
    return itemCount;
}

void Stack::printAllItems()
{
    Node *currentNode = topOfStack;
    while (currentNode != NULL)
    {
        std::cout << "value: " << currentNode->value << std::endl;
        currentNode = currentNode->nextNode;
    }
    std::cout << "------" << std::endl;
}

int Stack::getTopOfStack()
{
    return topOfStack->value;
}
Stack::~Stack()
{
    while (itemCount != 0)
    {
        this->pop();
    }
}
#endif