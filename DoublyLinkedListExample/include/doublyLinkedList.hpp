#ifndef doublyLinkedList_hpp
#define doublyLinkedList_hpp

class doublyNode
{
public:
    doublyNode(int);
    ~doublyNode();

    void addNodeToUp(int);
    void addNodeToDown(int);

    doublyNode *goToUpNode();
    doublyNode *goToDownNode(); // Bu iki fonksiyon kontrol amaçlı

    doublyNode *goToUpLastNode();
    doublyNode *goToDownLastNode();

    void printAllUpNodes();
    void printAllDownNodes();

    int getNodeCount();
    int getValue();

    static doublyNode *rootNode;
    static int nodeCount;

private:
    doublyNode *upNode;
    doublyNode *downNode;
    int value;
};

#endif