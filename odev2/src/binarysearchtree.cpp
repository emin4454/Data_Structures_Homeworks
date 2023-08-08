#ifndef BINARYSEARCHTREE_CPP
#define BINARYSEARCHTREE_CPP
#include <iostream>
#include "binarysearchtree.hpp"

BinarySearchTree::BinarySearchTree()
{
    rootNode = NULL;
    nodeCount = 0;
}

void BinarySearchTree::addNode(TreeNode *treeNode, int value)
{
    if (nodeCount == 0)
    {
        rootNode = new TreeNode(value);
        nodeCount++;
    }
    else
    {
        if (value > treeNode->value)
        {
            if (treeNode->rightNode == NULL)
            {
                treeNode->rightNode = new TreeNode(value);
                nodeCount++;
                return;
            }
            else
            {
                addNode(treeNode->rightNode, value);
            }
        }
        else if (value < treeNode->value)
        {
            if (treeNode->leftNode == NULL)
            {
                treeNode->leftNode = new TreeNode(value);
                nodeCount++;
                return;
            }
            else
            {
                addNode(treeNode->leftNode, value);
            }
        }
        else
            return;
    }
}

void BinarySearchTree::printInOrder(TreeNode *treeNode)
{
    if (treeNode == NULL)
    {
        return;
    }
    printInOrder(treeNode->leftNode);
    std::cout << treeNode->value << std::endl;
    printInOrder(treeNode->rightNode);
}

void BinarySearchTree::printPostOrderChar(TreeNode *treeNode)
{
    if (treeNode == NULL)
    {
        return;
    }
    printPostOrderChar(treeNode->leftNode);
    printPostOrderChar(treeNode->rightNode);
    std::cout << char(treeNode->value) << " ";
}

int BinarySearchTree::sumOfNodes(TreeNode *treeNode)
{
    if (treeNode == NULL)
    {
        return 0;
    }
    /*toplam = toplam + treeNode->value;
    sumOfNodes(treeNode->leftNode, toplam);
    sumOfNodes(treeNode->rightNode, toplam);*/
    return treeNode->value + sumOfNodes(treeNode->rightNode) + sumOfNodes(treeNode->leftNode);
}

int BinarySearchTree::getHeight(TreeNode *TreeNode)
{
    if (TreeNode == NULL)
    {
        return -1;
    }
    return 1 + std::max(getHeight(TreeNode->leftNode), getHeight(TreeNode->rightNode));
}
TreeNode *BinarySearchTree::getRootNode()
{
    return rootNode;
}
int BinarySearchTree::getNodeCount()
{
    return nodeCount;
}
void BinarySearchTree::deleteAllItems(TreeNode *treenode)
{
    if (treenode == NULL)
    {
        return;
    }
    deleteAllItems(treenode->leftNode);
    deleteAllItems(treenode->rightNode);
    delete treenode;
}
BinarySearchTree::~BinarySearchTree()
{
    deleteAllItems(rootNode);
}

#endif
