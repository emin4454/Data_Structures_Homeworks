#ifndef NUMBERREADER_CPP
#define NUMBERREADER_CPP
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <windows.h>
#include "stack.hpp"
#include "binarysearchtree.hpp"
#include "numberreader.hpp"
NumberReader::NumberReader(/* args */)
{
    int value = 0;
    startReading();
}

NumberReader::~NumberReader()
{
}

void NumberReader::startReading()
{
    std::string fileName = "Sayilar.txt"; // sayilar.txt okunuyor
    std::fstream file(fileName);
    std::string line;
    int value;
    while (std::getline(file, line)) // linelar okunuyor
    {
        std::stringstream valstr(line);
        std::stringstream temp(line);
        int stacklen = 0;
        int doesNothing;
        while (temp >> doesNothing)
        {
            stacklen++;
        }

        int stackIndex = 0;
        Stack **stacks = new Stack *[stacklen]; // stackler listesi olusturuluyor
        if (valstr >> value)
        {
            Stack *stack = new Stack();
            stack->push(value);
            stacks[stackIndex] = stack;
        }
        else
            throw "bos satir";

        while (valstr >> value) // linedaki her bir veri okunuyor
        {
            if (value > stacks[stackIndex]->getTopOfStack() && value % 2 == 0)
            {
                stackIndex++;
                Stack *stack = new Stack();
                stack->push(value);
                stacks[stackIndex] = stack;
            }
            else
            {
                stacks[stackIndex]->push(value);
            }
        } // Linedaki stackler olusturuldu;
        BinarySearchTree **trees = new BinarySearchTree *[stackIndex + 1];
        BinarySearchTree *maxTree = NULL;
        for (int i = 0; i < stackIndex + 1; i++)
        {
            int len = stacks[i]->getNodeCount();
            BinarySearchTree *tree = new BinarySearchTree();
            for (int j = 0; j < len; j++)
            {
                tree->addNode(tree->getRootNode(), stacks[i]->pop());
            }
            delete stacks[i];
            if (i == 0)
                maxTree = tree;
            else
            {
                if (tree->getHeight(tree->getRootNode()) > maxTree->getHeight(maxTree->getRootNode()))
                {
                    maxTree = tree;
                }
                else if (tree->getHeight(tree->getRootNode()) == maxTree->getHeight(maxTree->getRootNode()))
                {
                    if (tree->sumOfNodes(tree->getRootNode()) > maxTree->sumOfNodes(maxTree->getRootNode()))
                        maxTree = tree;
                }
            }
            trees[i] = tree;
        } // ağaçlar oluşturulur
        maxTree->printPostOrderChar(maxTree->getRootNode());
        for (int i = 0; i < stackIndex + 1; i++)
        {
            delete trees[i];
        }
        delete[] stacks;
        delete[] trees;
        std::cout << std::endl;
        Sleep(10);
    }
}
#endif