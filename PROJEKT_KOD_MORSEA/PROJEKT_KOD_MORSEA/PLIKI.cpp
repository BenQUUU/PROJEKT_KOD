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

Pliki::Pliki() {
	reply = ' ';
	dane = "";
}

void Pliki::zapis(string napis_a, string napis_z) {
	cout << endl;
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
		plik << '\n';
		plik.write(napis_z.c_str(), napis_z.size() + 1);

		plik.close();

		plik.open("odkodowane.txt", ios::app);

		if (!plik) {
			cout << "B��d otwarcia pliku!" << endl;
			exit(0);
		}

		plik << '\n';
		plik.write(napis_a.c_str(), napis_a.size() + 1);

		plik.close();
	}
	cout << endl << "Pomy�lnie zapisano tekst do plik�w" << endl;
}
void Pliki::odczyt() {
	ifstream plik2;
	plik2.open("zakodowane.txt");

	if (!plik2) {
		cout << "B��d odczytu danych!" << endl;
		exit(0);
	}

	while (!plik2.eof()) {
		getline(plik2, dane);
		cout << dane << endl;
	}

	cout << endl << "co oznacza: " << endl;

	plik2.close();

	plik2.open("odkodowane.txt");

	if (!plik2) {
		cout << "B��d odczytu danych!" << endl;
		exit(0);
	}

	while (!plik2.eof()) {
		getline(plik2, dane);
		cout << dane << endl;
	}

	plik2.close();
}

void Pliki::usun() {
	fstream plik3;
	plik3.open("zakodowane.txt", ios::in | ios::out | ios::trunc);

	if (!plik3) {
		cout << "B��d odczytu pliku!" << endl;
	}

	plik3.close();

	plik3.open("odkodowane.txt", ios::in | ios::out | ios::trunc);

	if (!plik3) {
		cout << "B��d odczytu pliku!" << endl;
	}

	plik3.close();

	cout << "Usuni�to zawarto�� z plik�w!" << endl;
}
