#ifndef PLIKI_HPP
#define PLIKI_HPP
#include <iostream>
#include <string>
using namespace std;

class Pliki {
protected:
	char reply;
	string dane;
public:
	Pliki();
	void zapis(string napis_a, string napis_z);
	void odczyt();
	void usun();
};

#endif // !PLIKI_HPP

