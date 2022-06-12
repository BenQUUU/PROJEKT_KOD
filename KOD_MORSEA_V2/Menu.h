#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
using namespace std;

/**
 * \brief Klasa Menu
 *
 * Klasa odpowiadająca za obsługę interfejsu. 
 *
 * \version wersja 1.0
 */
class Menu {
private:
	char wybor; /**< Wybór który określa co użytkownik chce zrobić */
	char reply; /**< Decyzja czy zapisać tekst do pliku */
public:
	Menu();
	void menu();
	void wywolanieMenu();
	char zapytanieZapis();
};

#endif