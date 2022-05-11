#ifndef PROGRAM_HPP
#define PROGRAM_HPP
#include <map>
#include <string>
#include <vector>
using namespace std;

class Program {
//pola klasy Program
protected:
	string napis;
	string napis_zakodowany;
	vector<string> kod;
	vector<string> nieznalezione;
	map<char, string> mapaMorsea;
	map<string, char> mapaASCII;
	vector<string> rozdziel(const string& napis, char znak, vector<string> elementy);
//funkcje klasy Program
public:
	Program();
	void wczytaj_morsea();
	void wczytaj_ascii();
	void wyswietl_mape();
	void koder();
	void dekoder();
};
#endif // !PROGRAM.HPP

