#ifndef TEXTTOLISTS_HPP
#define TEXTTOLISTS_HPP
#include "arraylist.hpp"
class TextToList
{
public:
    TextToList(int, int);
    void startProcess();
    void swapLists();
    void printEverything();

private:
    int num;
    int aValue;
    int bValue;
    ArrayList *upLists;
    ArrayList *downLists;
};

#endif