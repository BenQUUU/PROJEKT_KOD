#ifndef KODEK_H
#define KODEK_H
#include <map>
#include <string>
using namespace std;

class Kodek {
protected:
	string tekst_odkodowany;
	string tekst_zakodowany;
	map<char, string> mapaMorsea;
	map<string, char> mapaASCII;
public:
	Kodek();
	void wczytaj_morsea();
	void wczytaj_ascii();
	void wyswietl_mape();
};

#endif