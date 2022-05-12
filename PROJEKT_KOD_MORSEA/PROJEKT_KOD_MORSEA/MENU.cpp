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

//konstruktor domyœlny zeruj¹cy pola
Menu::Menu() {
	wybor = ' ';
}
//funkcja wyœwietlaj¹ca menu
void Menu::menu() {
	cout << "Wczytywanie";
	for (unsigned short i = 0; i < 3; i++) {
		cout << ".";
		Sleep(400); //wyœwietla kropkê co 400 milisekund
	}
	system("cls");

	cout << "1. Kodowanie na kod morse'a" << endl;
	cout << "2. Dekodowanie kodu morse'a" << endl;
	cout << "3. Odczyt danych z pliku" << endl;
	cout << "4. Usuñ zawartoœæ z plików" << endl;
	cout << "5. Koniec programu" << endl << endl;
	cout << "Wybór: ";
	wybor = _getch(); //pobiera od u¿ytkowanika co chce zrobiæ

	system("cls"); //czyszczenie ekranu
}
//funkcja która wywo³ujê potrzebne metody zale¿nie od wyboru
void Menu::wywolanie_menu() {
	wczytaj_morsea(); //wczytanie mapy morse'a
	wczytaj_ascii(); //wczytanie mapy ASCII
	menu(); //wyœwietlenie menu

	switch (wybor) { //switche zale¿ne od zmiennej wybor
	case '1': //koder
		koder();
		zapis(napis, napis_zakodowany);
		break;
	case '2': //dekoder
		wyswietl_mape();
		dekoder();
		zapis(napis, napis_zakodowany);
		break;
	case '3': //odczyt
		cout << "Zapisany tekst w pliku: " << endl;
		odczyt();
		break;
	case '4': //usuwanie zawartoœci plików
		usun();
		break;
	case '5': //zakoñczenie programu
		cout << endl << "Zakoñczono dzia³anie programu!" << endl;
		exit(0);
		break;
	default: //u¿ytkownik poda³ coœ innego
		cout << "Niepoprawny wybór!" << endl;
		break;
	}
}
