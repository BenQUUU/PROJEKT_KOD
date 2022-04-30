#ifndef PROGRAM_HPP
#define PROGRAM_HPP
#include <map>
#include <string>
#include <vector>
using namespace std;

class Program {
private:
	vector<string> kod;
	map<char, string> mapaMorsea;
	map<string, char> mapaASCII;
	vector<string> rozdziel(const string& napis, char znak, vector<string> elementy);
public:
	void wczytaj_morsea();
	void wczytaj_ascii();
	void koder();
	void dekoder();
};

#endif // !PROGRAM.HPP

