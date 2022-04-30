#include "PROGRAM.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;

int main()
{
    try {
        Program a;
        a.wczytaj_morsea();
        a.wczytaj_ascii();
        //a.koder();
        a.dekoder();
    }
    catch (...) {
        cout << "Obsluzono nieznany wyjatek!" << endl;
    }

    return 0;
}


