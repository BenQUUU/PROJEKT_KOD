#ifndef PLIKI_H
#define PLIKI_H
#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
 * \brief Klasa Pliki
 *
 * Klasa odpowiadająca za zapis i odczyt tekstu do/z pliku. 
 *
 * \version wersja 1.0
 */
class Pliki {
private:
	string dane; /**< Przechowuje linijkę z pliku podczas odczytywania */
public:
	Pliki();
	void zapis(string tekst_z, string tekst_o, char reply);
	void odczyt();
};

#endif