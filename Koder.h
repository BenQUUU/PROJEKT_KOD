#ifndef KODER_H
#define KODER_H
#include "Pliki.h"
#include "Kodek.h"
#include <map>
#include <iostream>
using namespace std;

/**
 * \brief Klasa Koder
 *
 * Klasa dziedziczona po klasach Pliki oraz Kodek, odpowiadająca za zakodowanie 
 * tekstu dla nas czytelnego na tekst w kodzie Morse'a. 
 *
 * \version wersja 1.0
 */
class Koder: public Pliki, public Kodek {
public:
	string kodowanie(char reply);
};
#endif
