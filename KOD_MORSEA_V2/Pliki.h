#ifndef PLIKI_H
#define PLIKI_H
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Pliki {
private:
	string dane;
public:
	Pliki();
	void zapis(string tekst_z, string tekst_o, char reply);
	void odczyt();
};

#endif