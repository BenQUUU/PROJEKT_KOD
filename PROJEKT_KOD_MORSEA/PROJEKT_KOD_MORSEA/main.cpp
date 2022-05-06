#include "PROGRAM.hpp"
#include "MENU.hpp"
#include "PLIKI.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <conio.h>
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Polish");

    Menu b;
    b.wywolanie_menu();

    return 0;
}


