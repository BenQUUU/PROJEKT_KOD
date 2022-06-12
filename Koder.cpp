#include "Koder.h"
#include "Pliki.h"
#include "Kodek.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <map>
using namespace std;

/**
 * \brief Koduje tekst na kod Morse'a w czasie rzeczywistym.
 *
 * Pobiera zmienną reply typu char oraz zwraca wartość typu string.
 *
 * \param[in] reply decyzja czy zapisać tekst do pliku.
 * \return Przetłumaczony tekst na kod Morse'a.
 * \attention jeśli podana przez użytkownika litera nie znajduje się w alfabecie Morse'a
 *			  wyrzuci wyjątek runtime_error wraz z komunikatem.\n
 *            jeśli litera znajduje się w alfabecie Morse'a to przekonwertuje literę na 
 *			  kod Morse'a i doda ją do zmiennej tekst_zakodowany.\n
 *            jeśli użytkownik naciśnie ENTER to wywoła funkcję zapis() z klasy Pliki oraz
 *            zwróci przetłumaczony tekst przerywając pętle za pomocą break.
 */
string Koder::kodowanie(char reply){
	char tempChar = ' ';
		
	do{
        tempChar = _getch(); 

        tempChar = tolower(tempChar); 

        if (mapaMorsea.find(tempChar) == mapaMorsea.end() && tempChar != 13) {
            throw runtime_error("Podana litera nie znajduje sie w kodzie Morsea!");
            cin.clear();
        }
        else {
            tekst_odkodowany += tempChar;

            if (tempChar == 13) {
            	Pliki::zapis(tekst_zakodowany, tekst_odkodowany , reply);
            	return tekst_zakodowany;
            	break;
            }

            cout << "Znak: " << tempChar << " kod: " << mapaMorsea.find(tempChar)->second << endl;

            tekst_zakodowany += mapaMorsea.find(tempChar)->second + " ";

            cin.clear();
        }
	}while(1);
}
