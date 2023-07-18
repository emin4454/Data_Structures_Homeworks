#include <iostream>
#include "doublyLinkedList.hpp"

using namespace std;

int main()
{
    doublyNode *doubleSidedList = new doublyNode(125);
    cout << "List has been created" << endl;
    doubleSidedList->addNodeToUp(5);
    doubleSidedList->addNodeToUp(7);
    doubleSidedList->addNodeToUp(8);
    doubleSidedList->addNodeToUp(9);

    doubleSidedList->printAllUpNodes();

    cout << "Down Nodes" << endl;

    doubleSidedList->addNodeToDown(1);
    doubleSidedList->addNodeToDown(2);
    doubleSidedList->addNodeToDown(3);
    doubleSidedList->addNodeToDown(4);

    doubleSidedList->printAllDownNodes();

    cout << "  TEST  " << endl;
    doublyNode *currentNode = doubleSidedList->rootNode;
}