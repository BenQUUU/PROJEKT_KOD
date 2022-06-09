#ifndef DEKODER_H
#define DEKODER_H
#include "Pliki.h"
#include "Kodek.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

class Dekoder: public Pliki, public Kodek {
private:
	vector<string> kod;
public:
	string dekodowanie(char reply);
	vector<string> rozdziel(const string& napis, char znak, vector<string> elementy);
};

#endif