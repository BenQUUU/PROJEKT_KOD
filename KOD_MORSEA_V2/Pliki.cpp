#include "Pliki.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <windows.h>
#include <iomanip>
using namespace std;

Pliki::Pliki() {
	dane = "";
}
//funkcja zapisująca dane do plików
void Pliki::zapis(string tekst_z, string tekst_o, char reply) {
	cout << endl;

	if (reply == 'n') { //jeśli nie to kończy działanie programu
		cout << endl << "Przetlumaczony tekst: ";
	}
	else {
		ofstream plik; //strumień do zapisu
		plik.open("zakodowane.txt", ios::app); //w trybie dopisywania danych do pliku

		if (!plik) { //jeśli nie może otworzyć pliku do kończy działanie programu
			throw -1;
		}
		plik << '\n';
		plik.write(tekst_z.c_str(), tekst_z.size() + 1); //zapis blokowy danych do pliku

		plik.close();//zamknięcie pliku

		//to samo robi dla pliku w którym znajdują się dane odkodowane
		plik.open("odkodowane.txt", ios::app);

		if (!plik) {
			throw -1;
		}

		plik << '\n';
		plik.write(tekst_o.c_str(), tekst_o.size() + 1);

		plik.close();

		cout << endl << "Przetlumaczony tekst: ";
	}
}
//funkcja odczytująca dane z plików
void Pliki::odczyt() {
	ifstream plik2; //strumień do odczytu
	plik2.open("zakodowane.txt");

	if (!plik2) { //jeśli nie może otworzyć pliku do kończy działanie programu
		throw -1;
	}

	while (!plik2.eof()) { //pętla dopóki nie dojdzie do końca pliku
		getline(plik2, dane); //wczytuję tekst linia po linii 
		cout << dane << endl; //wyświetla zdanie
	}

	plik2.close();//zamknięcie pliku

	cout << endl << "co oznacza: " << endl;

	//to samo robi dla pliku z danymi odkodowanymi
	plik2.open("odkodowane.txt");

	if (!plik2) {
		throw -1;
	}

	while (!plik2.eof()) {
		getline(plik2, dane);
		cout << dane << endl;
	}

	plik2.close();
}