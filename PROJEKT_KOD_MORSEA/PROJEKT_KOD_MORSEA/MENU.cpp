#include "MENU.hpp"
#include "PROGRAM.hpp"
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

Menu::Menu() {
	wybor = ' ';
}
void Menu::menu() {
	cout << "Wczytywanie";
	for (unsigned short i = 0; i < 3; i++) {
		cout << ".";
		Sleep(800);
	}
	system("cls");

	cout << "1. Kodowanie na kod morse'a" << endl;
	cout << "2. Dekodowanie kodu morse'a" << endl;
	cout << "3. Odczyt danych z pliku" << endl;
	cout << "4. Koniec programu" << endl << endl;
	cout << "Wyb�r: ";
	wybor = _getch();

	system("cls");
}
void Menu::wywolanie_menu() {
	wczytaj_morsea();
	wczytaj_ascii();
	menu();
	switch (wybor) {
	case '1':
		koder();
		zapis();
		break;
	case '2':
		dekoder();
		zapis();
		break;
	case '3':
		break;
	case '4':
		cout << endl << "Zako�czono dzia�anie programu!" << endl;
		exit(0);
		break;
	default:
		cout << "Niepoprawny wyb�r!" << endl;
		break;
	}
}
