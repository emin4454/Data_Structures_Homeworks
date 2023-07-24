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
    downLists = new ArrayList();          // üst ve alt arraylist objeleri oluşturuluyor
    std::string fileName = "Sayilar.txt"; // sayilar.txt okunuyor
    std::fstream file(fileName);
    std::string line;
    int value;
    while (getline(file, line)) // linelar okunuyor
    {
        std::stringstream valstr(line);
        LinkedList *upLinkedList = new LinkedList(); // her onlar ve birler b
        LinkedList *downLinkedList = new LinkedList();
        while (valstr >> value) // linedaki her bir veri okunuyor
        {
            upLinkedList->addNode(value / 10);   // onlar basamagi bagli listeye eklenecek
            downLinkedList->addNode(value % 10); // birler basamagi baska bi bagli listeye eklenecek
        }
        upLists->add(upLinkedList);
        downLists->add(downLinkedList);
    }
    // printEverything();
    swapLists();
    // printEverything();

    std::cout << std::endl;
    std::cout << "Ust: " << upLists->calculateSumOfAverages();
    std::cout << std::endl;
    std::cout << "Alt: " << downLists->calculateSumOfAverages();
}
void TextToList::swapLists()
{
    /*LinkedList *tmp = upLists->getByIndex(aValue)->copyList();
    upLists->changeValue(aValue, downLists->getByIndex(bValue));    // Yeni Liste Üretilip Yer değiştirliyor
    downLists->changeValue(bValue, tmp);*/

    Node *tmp = upLists->getByIndex(aValue)->getRootNode();
    int tmpN = upLists->getByIndex(aValue)->getNodeCount();
    upLists->getByIndex(aValue)->setRootNode(downLists->getByIndex(bValue)->getRootNode());   // Linkedlistlerin kök
    upLists->getByIndex(aValue)->setNodeCount(downLists->getByIndex(bValue)->getNodeCount()); // nodeları değiştirilerek
    downLists->getByIndex(bValue)->setRootNode(tmp);                                          // swap işlemi yapılıyor
    downLists->getByIndex(bValue)->setNodeCount(tmpN);
}
#endif

void TextToList::printEverything()
{
    std::cout << "Ust Listeler" << std::endl;
    for (int i = 0; i < upLists->getLenght(); i++)
    {
        (upLists->getByIndex(i))->printAllNodes(); // Tüm Nodeları Yazdırır
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