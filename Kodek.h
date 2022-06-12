#ifndef KODEK_H
#define KODEK_H
#include <map>
#include <string>
using namespace std;

/**
 * \brief Klasa Kodek
 *
 * Klasa w której zawarte jest wszystko związane z mapą. 
 *
 * \version wersja 1.0
 */
class Kodek {
protected:
	string tekst_odkodowany; /**< Tekst odkodowany */
	string tekst_zakodowany; /**< Tekst zakodowany */
	map<char, string> mapaMorsea; /**< Mapa kodu Morse'a */
	map<string, char> mapaASCII; /**< Mapa kodu ASCII */
public:
	Kodek();
	void stworzMapeMorsea();
	void stworzMapeASCII();
	void wyswietl_mape();
};

#endif