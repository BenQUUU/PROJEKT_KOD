#include "Dekoder.h"
#include "Pliki.h"
#include "Kodek.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

/**
 * \brief Dekoduje tekst z kodu Morse'a na tekst dla nas czytelny.
 *
 * Pobiera zmienną reply typu char oraz zwraca wartość typu string.
 *
 * \param[in] reply decyzja czy zapisać tekst do pliku.
 * \return Przetłumaczony tekst z kodu Morse'a na alfabet angielski.
 * \attention jeśli podana przez użytkownika litera nie znajduje się w alfabecie Morse'a
 *			  wyrzuci wyjątek runtime_error wraz z komunikatem.\n
 *            jeśli litera znajduje się w alfabecie angielskim to przekonwertuje literę z kodu Morse'a na 
 *			  normalną literę i doda ją do zmiennej tekst_odkodowany, wywoła funkcję zapis() z klasy Pliki
 *            oraz zwróci odkodowany tekst.\n
 *  
 */
string Dekoder::dekodowanie(char reply){
	Kodek::wyswietl_mape();
	cin.clear();
    vector<string> morse;

    getline(cin, tekst_zakodowany);

    morse = rozdziel(tekst_zakodowany, ' ', kod);

    for (unsigned int i = 0; i < morse.size(); i++) {
        if (mapaASCII.find(morse[i]) == mapaASCII.end()) {
            if (morse[i] != "") {
                throw runtime_error("Podana litera nie znajduje sie w kodzie Morsea!");
            	cin.clear();
            }
        }
        else {
            tekst_odkodowany += mapaASCII.find(morse[i])->second;
        }
    }
    Pliki::zapis(tekst_zakodowany, tekst_odkodowany, reply);
    return tekst_odkodowany;
}
/**
 * \brief Wprowadzony tekst przez użytkownika w kodzie Morse'a oddzielony spacjami rozdziela 
 *  na poszczególne elementy vectora.
 *
 * Pobiera zmienną napis typu string, znak typu char oraz vector typu string elementy i zwraca vector elementy.
 *
 * \param[in] napis tekst zakodowany kodem Morse'a.
 * \param[in] znak oddziela tekst spacją.
 * \param[in] elementy vector typu string.
 * \return Vector zawierający wprowadzone litery kodu Morse'a.
 *
 */
vector<string> Dekoder::rozdziel(const string& napis, char znak, vector<string> elementy){
	stringstream strumien(napis);
    string element = "";

    while (getline(strumien, element, znak)) {
        elementy.push_back(element);
    }

    return elementy;
}