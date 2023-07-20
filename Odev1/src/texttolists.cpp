#ifndef TEXTTOLISTS_CPP
#define TEXTTOLISTS_CPP
#include "texttolists.hpp"
#include "linkedlist.hpp"
#include "arraylist.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "node.hpp"

TextToList::TextToList(int aValue, int bValue)
{
    this->aValue = aValue;
    this->bValue = bValue;
    startProcess();
}

void TextToList::startProcess()
{
    upLists = new ArrayList();
    downLists = new ArrayList();
    std::string fileName = "Sayilar.txt";
    std::fstream file(fileName);
    std::string line;
    int value;
    while (getline(file, line))
    {
        std::stringstream valstr(line);
        LinkedList *upLinkedList = new LinkedList();
        LinkedList *downLinkedList = new LinkedList();
        while (valstr >> value)
        {
            upLinkedList->addNode(value / 10);   // onlar basamagi listeye eklenecek
            downLinkedList->addNode(value % 10); // birler basamagi listeye eklenecek
        }
        upLists->add(upLinkedList);
        downLists->add(downLinkedList);
    }
    printEverything();
    swapLists();
    std::cout << "listeler yer degistirdi" << std::endl;
    printEverything();

    std::cout << std::endl
              << "Ust: " << upLists->calculateSumOfAverages() << std::endl
              << "Alt: " << downLists->calculateSumOfAverages();
}
void TextToList::swapLists()
{
    /* LinkedList *tmp = upLists->getByIndex(aValue)->copyList();
    upLists->changeValue(aValue, downLists->getByIndex(bValue));
    downLists->changeValue(bValue, tmp);
    */
    Node *tmp = upLists->getByIndex(aValue)->getRootNode();
    upLists->getByIndex(aValue)->setRootNode(downLists->getByIndex(bValue)->getRootNode());
    downLists->getByIndex(bValue)->setRootNode(tmp);
}
#endif

void TextToList::printEverything()
{
    std::cout << "Ust Listeler" << std::endl;
    for (int i = 0; i < upLists->getLenght(); i++)
    {
        (upLists->getByIndex(i))->printAllNodes();
        std::cout << "|" << std::endl;
    }
    std::cout << "-----" << std::endl
              << std::endl
              << "Alt Listeler" << std::endl;

    for (int i = 0; i < downLists->getLenght(); i++)
    {
        (downLists->getByIndex(i))->printAllNodes();
        std::cout << "|" << std::endl;
    }
    std::cout << "-----";
}