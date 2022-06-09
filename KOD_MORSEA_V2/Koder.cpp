#include "Koder.h"
#include "Pliki.h"
#include "Kodek.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <map>
using namespace std;

string Koder::kodowanie(char reply){
	char tempChar = ' ';
		
	do{
		
        tempChar = _getch(); //getch() pobiera od użytkownika znak

        tempChar = tolower(tempChar); //wszystkie wprowadzone duże litery są zamieniane na małe

        //wprowadzenie niepoprawnej litery wyświetla błąd
        if (mapaMorsea.find(tempChar) == mapaMorsea.end() && tempChar != 13) {
            throw runtime_error("Podana litera nie znajduje sie w kodzie Morsea!");
            cin.clear();
        }
        else {
            tekst_odkodowany += tempChar;

            //program działa dopóki użytkownik nie naciśnie ENTER
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
