#include "Menu.h"
#include "Dekoder.h"
#include "Pliki.h"
#include "Koder.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

//konstruktor domyślny zerujący pola
Menu::Menu() {
	wybor = ' ';
	znak = ' ';
	reply = ' ';
}
//funkcja wyświetlająca menu
void Menu::menu() {
	cout << "Wczytywanie";
	for (unsigned short i = 0; i < 3; i++) {
		cout << ".";
		Sleep(400); //wyświetla kropkę co 400 milisekund
	}
	system("cls");

	cout << "KODOWANIE/DEKODOWANIE KODU MORSE'A" << endl;
	cout << "==================================" << endl << endl;

	cout << "1. Kodowanie na kod morse'a" << endl;
	cout << "2. Dekodowanie kodu morse'a" << endl;
	cout << "3. Odczyt danych z plikow" << endl;
	cout << "4. Koniec programu" << endl << endl;
	cout << "Wybor: ";
	wybor = _getch(); //pobiera od użytkowanika co chce zrobić

	system("cls"); //czyszczenie ekranu
}
//funkcja która wywołuję potrzebne metody zależnie od wyboru
void Menu::wywolanie_menu() {
	menu(); //wyświetlenie menu

	switch (wybor) { //switche zależne od zmiennej wybor
	case '1':
	{ //koder
		zapytanie_o_zapisanie();
		system("cls");
		cout << "Kodowanie[ENTER konczy dzialanie programu]: " << endl << endl;
		Koder code;
		cout << code.kodowanie(reply) << endl;
		break;
	}
	case '2': //dekoder
	{
		zapytanie_o_zapisanie();
		system("cls");
		Dekoder decode;
		cout << decode.dekodowanie(reply) << endl;
		cout << endl << "Pomyslnie zapisano tekst do plikow" << endl;
		break;
	}
	case '3': //odczyt
	{
		Pliki file;
		cout << "Zapisany tekst w pliku: " << endl; 
		file.odczyt();
		cout << endl;
		break;
	}
	case '4': //zakończenie programu
	{
		cout << endl << "Zakonczono dzialanie programu!" << endl;
		exit(0);
		break;
	}
	default: //użytkownik podał coś innego
	{
		cout << "Niepoprawny wybor!" << endl;
		break;
	}
	}
}
char Menu::zapytanie_o_zapisanie(){
	do { //zapytanie czy chce zapisać tekst do plików
		cout << "Czy bedziesz chcial zapisac tekst do pliku?(t,n): ";
		fflush(stdin);
		reply = getchar();
		reply = tolower(reply);
		cin.ignore();
	} while ((reply != 't') && (reply != 'n'));
	
	return reply;
}