#include <iostream>
#include "Akcja.h"

int main()
{
    cout << "Automat.";
    Akcja a;
    while (a.get_stan())
    {
        a.akcja();
    }
}
