#include "Pliki.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <windows.h>
#include <iomanip>
using namespace std;

/**
 * \brief Konstruktor domyślny.
 *
 * Tworzy obiekt klasy Pliki, automatycznie zerując pola klasy.
 */
Pliki::Pliki() {
	dane = "";
}
/**
 * \brief Zapisuje wynik kodowania lub dekodowania do plików.
 *
 * Pobiera tekst zakodowany, tekst odkodowany oraz decyzję czy zapisać dane do plików.
 *
 * \param[in] tekst_z tekst zakodowany.
 * \param[in] tekst_o tekst odkodowany.
 * \param[in] reply decyzja czy zapisać tekst do pliku.
 * \attention jeśli reply wynosi 'n' to nie zapisuje danych do plików.\n
 *            jeśli reply wynosi 't' to otwiera dwa pliki w trybie do zapisu i zapisuje
 *            do nich tekst blokowo.\n
 *            jeśli program nie będzie w stanie otworzyć plików to wyrzuci wyjątek int.\n
 */
void Pliki::zapis(string tekst_z, string tekst_o, char reply) {
	cout << endl;

	if (reply == 'n') { 
		cout << endl << "Przetlumaczony tekst: ";
	}
	else {
		ofstream plik; 
		plik.open("zakodowane.txt", ios::app); 

		if (!plik) { 
			throw -1;
		}
		plik << '\n';
		plik.write(tekst_z.c_str(), tekst_z.size() + 1); 

		plik.close();

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
/**
 * \brief Odczytuje tekst linijka po linicje z plików.
 *
 * Otwiera dwa pliki w trybie do odczytu i pobiera z nich zawartość.
 *
 * \attention jeśli program nie będzie w stanie otworzyć plików to wyrzuci wyjątek int.\n
 */
void Pliki::odczyt() {
	ifstream plik2; 
	plik2.open("zakodowane.txt");

	if (!plik2) { 
		throw -1;
	}

	while (!plik2.eof()) { 
		getline(plik2, dane);  
		cout << dane << endl; 
	}

	plik2.close();

	cout << endl << "co oznacza: " << endl;

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