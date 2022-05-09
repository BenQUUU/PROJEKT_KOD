#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <string>
#include "PROGRAM.hpp"
#include "PLIKI.hpp"
using namespace std;

class Menu: public Program, public Pliki {
private:
	char wybor;
public:
	Menu();
	void menu();
	void wywolanie_menu();
};
#endif // !MENU_HPP
