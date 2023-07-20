#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP
#include "linkedlist.hpp"

class ArrayList
{
private:
    int lenght;
    int capacity;
    LinkedList *list;
    void increaseCapacity(int);

public:
    ArrayList();
    void add(LinkedList *);
    int getLenght();
    int getCapacity();
    LinkedList *getByIndex(int);
    void changeValue(int, LinkedList *);
    float calculateSumOfAverages();
};
#endif