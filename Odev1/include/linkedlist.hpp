#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#include "node.hpp"

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void addNode(int);

    Node *goToNextNode();
    Node *goToLastNode();

    void printAllNodes();

    int getNodeCount();
    int getValue();
    Node *getRootNode();
    void setRootNode(Node *);
    void setNodeCount(int);
    LinkedList *copyList();
    int getValueByIndex(int);

private:
    Node *rootNode;
    int nodeCount;
};

#endif