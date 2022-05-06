#ifndef PROGRAM_HPP
#define PROGRAM_HPP
#include <map>
#include <string>
#include <vector>
using namespace std;

class Program {
	string napis;
	vector<string> kod;
	vector<string> nieznalezione;
	map<char, string> mapaMorsea;
	map<string, char> mapaASCII;
	vector<string> rozdziel(const string& napis, char znak, vector<string> elementy);
public:
	Program();
	void wczytaj_morsea();
	void wczytaj_ascii();
	void koder();
	void dekoder();
};

#endif // !PROGRAM.HPP

