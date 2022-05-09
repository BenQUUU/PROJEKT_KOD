#include "MENU.hpp"
#include "PROGRAM.hpp"
#include "PLIKI.hpp"
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
	cout << "4. Usuñ zawartoœæ z plików" << endl;
	cout << "5. Koniec programu" << endl << endl;
	cout << "Wybór: ";
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
		zapis(napis, napis_zakodowany);
		break;
	case '2':
		wyswietl_mape();
		dekoder();
		zapis(napis, napis_zakodowany);
		break;
	case '3':
		cout << "Zapisany tekst w pliku: " << endl;
		odczyt();
		break;
	case '4':
		usun();
		break;
	case '5':
		cout << endl << "Zakoñczono dzia³anie programu!" << endl;
		exit(0);
		break;
	default:
		cout << "Niepoprawny wybór!" << endl;
		break;
	}
}
