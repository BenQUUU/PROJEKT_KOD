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

//konstruktor domyœlny zeruj¹cy pola
Pliki::Pliki() {
	reply = ' ';
	dane = "";
}
//funkcja zapisuj¹ca dane do plików
void Pliki::zapis(string napis_a, string napis_z) {
	cout << endl;

	do { //zapytanie czy chce zapisaæ tekst do plików
		cout << "Czy chcesz zapisaæ tekst do pliku?(t,n): ";
		fflush(stdin);
		reply = getchar();
		reply = tolower(reply);
		cin.ignore();
	} while ((reply != 't') && (reply != 'n'));

	if (reply == 'n') { //jeœli nie to koñczy dzia³anie programu
		cout << endl << "Powrót do menu g³ównego..." << endl << endl;
	}
	else {
		ofstream plik; //strumieñ do zapisu
		plik.open("zakodowane.txt", ios::app); //w trybie dopisywania danych do pliku

		if (!plik) { //jeœli nie mo¿e otworzyæ pliku do koñczy dzia³anie programu
			cout << "B³¹d otwarcia pliku!" << endl;
			exit(0);
		}
		plik << '\n';
		plik.write(napis_z.c_str(), napis_z.size() + 1); //zapis blokowy danych do pliku

		plik.close();//zamkniêcie pliku

		//to samo robi dla pliku w którym znajduj¹ siê dane odkodowane
		plik.open("odkodowane.txt", ios::app);

		if (!plik) {
			cout << "B³¹d otwarcia pliku!" << endl;
			exit(0);
		}

		plik << '\n';
		plik.write(napis_a.c_str(), napis_a.size() + 1);

		plik.close();

		cout << endl << "Pomyœlnie zapisano tekst do plików" << endl << endl;
	}
}
//funkcja odczytuj¹ca dane z plików
void Pliki::odczyt() {
	ifstream plik2; //strumieñ do odczytu
	plik2.open("zakodowane.txt");

	if (!plik2) { //jeœli nie mo¿e otworzyæ pliku do koñczy dzia³anie programu
		cout << "B³¹d odczytu danych!" << endl;
		exit(0);
	}

	while (!plik2.eof()) { //pêtla dopóki nie dojdzie do koñca pliku
		getline(plik2, dane); //wczytujê tekst linia po linii 
		cout << dane << endl; //wyœwietla zdanie
	}

	plik2.close();//zamkniêcie pliku

	cout << endl << "co oznacza: " << endl;

	//to samo robi dla pliku z danymi odkodowanymi
	plik2.open("odkodowane.txt");

	if (!plik2) {
		cout << "B³¹d odczytu danych!" << endl;
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
//funkcja usuwaj¹ca zawartoœæ z plików
void Pliki::usun() {
	fstream plik3; //strumieñ w trybie odczytu/zapisu
	plik3.open("zakodowane.txt", ios::in | ios::out | ios::trunc); //zawartoœæ jest tracona podczas otwierania

	if (!plik3) { //jeœli nie mo¿e otworzyæ pliku do koñczy dzia³anie programu
		cout << "B³¹d odczytu pliku!" << endl;
	}

	plik3.close(); //zamkniêcie pliku

	//to samo robi dla drugiego pliku
	plik3.open("odkodowane.txt", ios::in | ios::out | ios::trunc);

	if (!plik3) {
		cout << "B³¹d odczytu pliku!" << endl;
	}

	plik3.close();

	cout << "Usuniêto zawartoœæ z plików!" << endl << endl; //komunikat o powodzeniu operacji
}
