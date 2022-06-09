#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
using namespace std;

class Menu {
private:
	char wybor;
	char znak;
	char reply;
public:
	Menu();
	void menu();
	void wywolanie_menu();
	char zapytanie_o_zapisanie();
};

#endif