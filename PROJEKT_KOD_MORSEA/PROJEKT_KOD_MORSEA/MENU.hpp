#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <string>
using namespace std;

class Menu {
private:
	int wybor;
	enum dzialanie;
public:
	Menu();
	void wywolanie_menu();
};

#endif // !MENU_HPP
