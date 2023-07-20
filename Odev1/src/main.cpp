#include <iostream>
#include "arraylist.hpp"
#include "linkedList.hpp"
#include <sstream>
#include <string>
#include <fstream>
#include "texttolists.hpp"

using namespace std;

int main()
{
    int a;
    int b;
    cout << " Konum A giriniz" << endl;
    cin >> a;
    cout << " Konum B giriniz" << endl;
    cin >> b;

    TextToList *ttl = new TextToList(a, b);
    /*LinkedList *oneSidedList = new LinkedList();
    oneSidedList->addNode(5);
    oneSidedList->addNode(52);
    oneSidedList->addNode(542);
    oneSidedList->addNode(51);
    oneSidedList->printAllNodes();

    ArrayList *arraylist = new ArrayList();
    /* string fileName = "Sayilar.txt";
    fstream file(fileName);
    string line;
    int value;
    while (getline(file, line))
    {
     stringstream valstr(line);
     while (valstr >> value)
     {
         cout << value << " ";
     }
     cout << endl;
    }
    */
}