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
#include <fstream>
using namespace std;
/*
void Pliki::zapis() {
	do {
		cout << "Czy chcesz zapisa� tekst do pliku?(t,n): ";
		fflush(stdin);
		reply = getchar();
		reply = tolower(reply);
	} while ((reply != 't') && (reply != 'n'));

	if (reply == 'n') {
		cout << "Zako�czono pomy�lnie dzia�anie programu" << endl;
		exit(0);
	}
	else {
		ofstream plik;
		plik.open("zakodowane.txt", ios::app);

		if (!plik) {
			cout << "B��d otwarcia pliku!" << endl;
			exit(0);
		}

		plik.write(napis_zakodowany.c_str(), napis_zakodowany.size() + 1);

		plik.close();

		plik.open("odkodowane.txt", ios::app);

		if (!plik) {
			cout << "B��d otwarcia pliku!" << endl;
			exit(0);
		}

		plik.write(napis.c_str(), napis.size() + 1);

		plik.close();
	}
}
void Pliki::odczyt() {

}
*/