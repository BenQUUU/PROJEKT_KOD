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

/**
 * \brief Konstruktor domyślny.
 *
 * Tworzy obiekt klasy Menu, automatycznie zerując pola klasy.
 */
Menu::Menu() {
	wybor = ' ';
	reply = ' ';
}
/**
 * \brief Wyświetla interfejs dla użytkownika.
 *
 * Wyświetla nazwę programu oraz w formie podpunktów cztery możliwe opcje do wykonania przez program.
 *
 */
void Menu::menu() {
	cout << "Wczytywanie";
	for (unsigned short i = 0; i < 3; i++) {
		cout << ".";
		Sleep(400); 
	}
	system("cls");

	cout << "KODOWANIE/DEKODOWANIE KODU MORSE'A" << endl;
	cout << "==================================" << endl << endl;

	cout << "1. Kodowanie na kod morse'a" << endl;
	cout << "2. Dekodowanie kodu morse'a" << endl;
	cout << "3. Odczyt danych z plikow" << endl;
	cout << "4. Koniec programu" << endl << endl;
	cout << "Wybor: ";
	wybor = _getch(); 

	system("cls"); 
}
/**
 * \brief Odpowiada za obsługę interfejsu.
 *
 * Wywołuje funkcję menu() i w zależności od wyboru użytkownika, tworzy obiekty i wywołuję funkcje 
 * z poszczególnych klas.
 *
 * \attention jeśli użytkownik wybierze opcję pierwszą to wykona się operacja kodowania za pomocą 
 * 			  funkcji Koder::kodowanie() z klasy Koder.\n
 *            jeśli użytkownik wybierze opcję drugą to wykona się operacja dekodowania za pomocą
 *            funkcji Dekoder::dekodowanie() z klasy Dekoder.\n
 *            jeśli użytkownik wybierze opcję trzecią to program wyświetli zawartość plików gdzie 
 *            znajduje się tekst odkodowany i zakodowany przy pomocy funkcji Pliki::odczyt() z klasy Pliki.\n
 *            jeśli użytkownik wybierze opcję czwartą to zakończy działania programu wyświetlając komunikat.\n
 *            jeśli użytkownik wprowadzi z klawiatury jakąkolwiek inną cyfrę to wyświetli informację to błednym wyborze.\n
 */
void Menu::wywolanieMenu() {
	menu(); 

	switch (wybor) { 
	case '1':
	{ 
		zapytanieZapis();
		system("cls");
		cout << "Kodowanie[ENTER konczy dzialanie programu]: " << endl << endl;
		Koder code;
		cout << code.kodowanie(reply) << endl;
		break;
	}
	case '2': 
	{
		zapytanieZapis();
		system("cls");
		Dekoder decode;
		cout << decode.dekodowanie(reply) << endl;
		cout << endl << "Pomyslnie zapisano tekst do plikow" << endl;
		break;
	}
	case '3': 
	{
		Pliki file;
		cout << "Zapisany tekst w pliku: " << endl; 
		file.odczyt();
		cout << endl;
		break;
	}
	case '4': 
	{
		cout << endl << "Zakonczono dzialanie programu!" << endl;
		exit(0);
		break;
	}
	default: 
	{
		cout << "Niepoprawny wybor!" << endl;
		break;
	}
	}
}
/**
 * \brief Pyta użytkownika czy zapisać tekst do plików.
 *
 * W pętli pyta użytkownika czy chciałby zapisać tekst do plików, musi wprowadzić 't' lub 'n'.
 *
 * \return Zwraca literę podaną przez użytkownika.
 * \attention powtarza zapytanie dopóki użytkownik nie wprowadzi 't' lub 'n'.
 *  
 */
char Menu::zapytanieZapis(){
	do { 
		cout << "Czy bedziesz chcial zapisac tekst do pliku?(t,n): ";
		fflush(stdin);
		reply = getchar();
		reply = tolower(reply);
		cin.ignore();
	} while ((reply != 't') && (reply != 'n'));
	
	return reply;
}