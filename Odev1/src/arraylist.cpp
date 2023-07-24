#ifndef ARRAYLIST_CPP
#define ARRAYLIST_CPP
#include "arraylist.hpp"
#include "linkedlist.hpp"
#include <iostream>

ArrayList::ArrayList()
{
    lenght = 0;
    capacity = 10;
    list = new LinkedList[capacity];
}

void ArrayList::add(LinkedList *linkedlist)
{
    if (lenght >= capacity - 1)
    {
        increaseCapacity(capacity * 2);
    }
    list[lenght] = *linkedlist;
    lenght++;
}

void ArrayList::increaseCapacity(int newCapacity)
{
    LinkedList *tmp = new LinkedList[newCapacity];
    for (int i = 0; i < lenght; i++)
    {
        tmp[i] = list[i];
    }
    list = tmp;
    capacity = newCapacity;
}

int ArrayList::getLenght()
{
    return lenght;
}

int ArrayList::getCapacity()
{
    return capacity;
}

LinkedList *ArrayList::getByIndex(int index)
{
    return &list[index];
}

void ArrayList::changeValue(int index, LinkedList *ll)
{

    list[index] = *ll;
}

float ArrayList::calculateSumOfAverages()
{
    int i = 0;
    float sumOfAverages = 0;
    while (true)
    {
        float average = 0;
        float sumOfLine = 0;
        float divideCounter = 0;
        for (int j = 0; j < lenght; j++)
        {
            int value = this->getByIndex(j)->getValueByIndex(i);
            if (value != -557)
            {
                sumOfLine += value; // bagli listenin sonuncu elemaninda degilsek bolunecek sayiya 1 ekliyoruz
                divideCounter++;
            }
        }
        if (divideCounter == 0)
        {
            return sumOfAverages;
        }
        average = sumOfLine / divideCounter;
        int twodigitnum = int(average * 10);  // virgulden sonra 1 basamak alinmasi icin sayi 10 ile carpilip inte cevrilecek
        average = float(twodigitnum / 10.0f); // inte cevrildikten sonra tekrar 10a bolunuyor
        sumOfAverages += average;
        i++;
    }
}

ArrayList::~ArrayList()
{
    delete[] list;
}
#endif