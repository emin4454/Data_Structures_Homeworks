#include <iostream>
#include "doublyLinkedList.hpp"

using namespace std;

int main()
{
    doublyNode *doubleSidedList = new doublyNode(125);
    cout << "List has been created" << endl;
    doubleSidedList->addNode(55);
    doubleSidedList->addNode(75);
    doubleSidedList->addNode(85);
    doubleSidedList->addNode(95);

    doubleSidedList->printAllNodes();
}