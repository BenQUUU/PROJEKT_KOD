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

//konstruktor domy�lny zeruj�cy pola
Menu::Menu() {
	wybor = ' ';
}
//funkcja wy�wietlaj�ca menu
void Menu::menu() {
	cout << "Wczytywanie";
	for (unsigned short i = 0; i < 3; i++) {
		cout << ".";
		Sleep(400); //wy�wietla kropk� co 400 milisekund
	}
	system("cls");

	cout << "1. Kodowanie na kod morse'a" << endl;
	cout << "2. Dekodowanie kodu morse'a" << endl;
	cout << "3. Odczyt danych z pliku" << endl;
	cout << "4. Usu� zawarto�� z plik�w" << endl;
	cout << "5. Koniec programu" << endl << endl;
	cout << "Wyb�r: ";
	wybor = _getch(); //pobiera od u�ytkowanika co chce zrobi�

	system("cls"); //czyszczenie ekranu
}
//funkcja kt�ra wywo�uj� potrzebne metody zale�nie od wyboru
void Menu::wywolanie_menu() {
	wczytaj_morsea(); //wczytanie mapy morse'a
	wczytaj_ascii(); //wczytanie mapy ASCII
	menu(); //wy�wietlenie menu

	switch (wybor) { //switche zale�ne od zmiennej wybor
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
	case '4': //usuwanie zawarto�ci plik�w
		usun();
		break;
	case '5': //zako�czenie programu
		cout << endl << "Zako�czono dzia�anie programu!" << endl;
		exit(0);
		break;
	default: //u�ytkownik poda� co� innego
		cout << "Niepoprawny wyb�r!" << endl;
		break;
	}
}
