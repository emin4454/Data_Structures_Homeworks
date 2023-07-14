#ifndef doublyLinkedList_hpp
#define doublyLinkedList_hpp

class doublyNode
{
public:
    doublyNode(int);
    void addNode(int);
    void goToNextNode();
    void goToPreviousNode();
    doublyNode *goToLastNode();
    int getNodeCount();
    ~doublyNode();
    static doublyNode *rootNode;
    static int nodeCount;
    void printAllNodes();

private:
    doublyNode *nextNode;
    doublyNode *previousNode;
    int value;
};

#endif