
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "node.hpp"

class Stack
{
public:
    Stack();
    ~Stack();
    void push(int);
    int pop();
    int getTopOfStack();
    void printAllItems();

    int getNodeCount();
    int getValue();

private:
    Node *topOfStack;
    int itemCount;
};

#endif