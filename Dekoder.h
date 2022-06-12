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

/**
 * \brief Klasa Dekoder
 *
 * Klasa dziedziczona po klasach Pliki oraz Kodek, odpowiadająca za zdekodowanie 
 * tekstu w kodzie Morse'a na tekst dla nas zrozumiały. 
 *
 * \version wersja 1.0
 */
class Dekoder: public Pliki, public Kodek {
private:
	vector<string> kod; /**< Vector typu string przechowujący odzielone litery w kodzie Morse'a */
public:
	string dekodowanie(char reply);
	vector<string> rozdziel(const string& napis, char znak, vector<string> elementy);
};

#endif