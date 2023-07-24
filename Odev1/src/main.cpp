
#include <iostream>
#include <string>
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

    return 0;
}