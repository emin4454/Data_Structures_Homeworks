#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP
#include "treenode.hpp"

class BinarySearchTree
{
private:
    TreeNode *rootNode;
    int nodeCount;
    void deleteAllItems(TreeNode *);

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void addNode(TreeNode *, int);
    void printInOrder(TreeNode *);
    TreeNode *getRootNode();
    int getNodeCount();
    int sumOfNodes(TreeNode *);
    int getHeight(TreeNode *);
    void printPostOrderChar(TreeNode *);
};

#endif