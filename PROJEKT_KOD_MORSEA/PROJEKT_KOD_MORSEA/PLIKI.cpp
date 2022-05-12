#include "MENU.hpp"
#include "PROGRAM.hpp"
#include "PLIKI.hpp"
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

//konstruktor domy�lny zeruj�cy pola
Pliki::Pliki() {
	reply = ' ';
	dane = "";
}
//funkcja zapisuj�ca dane do plik�w
void Pliki::zapis(string napis_a, string napis_z) {
	cout << endl;

	do { //zapytanie czy chce zapisa� tekst do plik�w
		cout << "Czy chcesz zapisa� tekst do pliku?(t,n): ";
		fflush(stdin);
		reply = getchar();
		reply = tolower(reply);
		cin.ignore();
	} while ((reply != 't') && (reply != 'n'));

	if (reply == 'n') { //je�li nie to ko�czy dzia�anie programu
		cout << endl << "Powr�t do menu g��wnego..." << endl << endl;
	}
	else {
		ofstream plik; //strumie� do zapisu
		plik.open("zakodowane.txt", ios::app); //w trybie dopisywania danych do pliku

		if (!plik) { //je�li nie mo�e otworzy� pliku do ko�czy dzia�anie programu
			cout << "B��d otwarcia pliku!" << endl;
			exit(0);
		}
		plik << '\n';
		plik.write(napis_z.c_str(), napis_z.size() + 1); //zapis blokowy danych do pliku

		plik.close();//zamkni�cie pliku

		//to samo robi dla pliku w kt�rym znajduj� si� dane odkodowane
		plik.open("odkodowane.txt", ios::app);

		if (!plik) {
			cout << "B��d otwarcia pliku!" << endl;
			exit(0);
		}

		plik << '\n';
		plik.write(napis_a.c_str(), napis_a.size() + 1);

		plik.close();

		cout << endl << "Pomy�lnie zapisano tekst do plik�w" << endl << endl;
	}
}
//funkcja odczytuj�ca dane z plik�w
void Pliki::odczyt() {
	ifstream plik2; //strumie� do odczytu
	plik2.open("zakodowane.txt");

	if (!plik2) { //je�li nie mo�e otworzy� pliku do ko�czy dzia�anie programu
		cout << "B��d odczytu danych!" << endl;
		exit(0);
	}

	while (!plik2.eof()) { //p�tla dop�ki nie dojdzie do ko�ca pliku
		getline(plik2, dane); //wczytuj� tekst linia po linii 
		cout << dane << endl; //wy�wietla zdanie
	}

	plik2.close();//zamkni�cie pliku

	cout << endl << "co oznacza: " << endl;

	//to samo robi dla pliku z danymi odkodowanymi
	plik2.open("odkodowane.txt");

	if (!plik2) {
		cout << "B��d odczytu danych!" << endl;
		exit(0);
	}

	while (!plik2.eof()) {
		getline(plik2, dane);
		cout << dane << endl;
	}
	
	cout << endl;

	plik2.close();

	system("pause");
}
//funkcja usuwaj�ca zawarto�� z plik�w
void Pliki::usun() {
	fstream plik3; //strumie� w trybie odczytu/zapisu
	plik3.open("zakodowane.txt", ios::in | ios::out | ios::trunc); //zawarto�� jest tracona podczas otwierania

	if (!plik3) { //je�li nie mo�e otworzy� pliku do ko�czy dzia�anie programu
		cout << "B��d odczytu pliku!" << endl;
	}

	plik3.close(); //zamkni�cie pliku

	//to samo robi dla drugiego pliku
	plik3.open("odkodowane.txt", ios::in | ios::out | ios::trunc);

	if (!plik3) {
		cout << "B��d odczytu pliku!" << endl;
	}

	plik3.close();

	cout << "Usuni�to zawarto�� z plik�w!" << endl << endl; //komunikat o powodzeniu operacji
}
