#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <string>
#include "PROGRAM.hpp"
using namespace std;

class Menu: public Program {
private:
	char wybor;
public:
	Menu();
	void menu();
	void wywolanie_menu();
};
#endif // !MENU_HPP
