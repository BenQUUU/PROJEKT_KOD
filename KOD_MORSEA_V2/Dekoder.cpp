#include "Dekoder.h"
#include "Pliki.h"
#include "Kodek.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

string Dekoder::dekodowanie(char reply){
	Kodek::wyswietl_mape();
	cin.clear();
    vector<string> morse;

    getline(cin, tekst_zakodowany); //użytkownik wprowadza tekst

    morse = rozdziel(tekst_zakodowany, ' ', kod); //wynik działania funkcji rozdziel jest zapisywany do zmiennej morse

    for (unsigned int i = 0; i < morse.size(); i++) {
        //jeżeli komputer nie znajdzie w mapie podanej litery zapisuje ją to vectora 'nieznalezione'
        if (mapaASCII.find(morse[i]) == mapaASCII.end()) {
            if (morse[i] != "") {
                throw runtime_error("Podana litera nie znajduje sie w kodzie Morsea!");
            	cin.clear();
            }
        }
        else {
            //pierwsza litera zostaje zamieniona na dużą
            if (i == 0) {
                tekst_odkodowany += char(mapaASCII.find(morse[i])->second - 32); //zapisuje literę do zmiennej napis
            }
            else { 
                tekst_odkodowany += mapaASCII.find(morse[i])->second;
            }
        }
    }
    Pliki::zapis(tekst_zakodowany, tekst_odkodowany, reply);
    return tekst_odkodowany;
}
vector<string> Dekoder::rozdziel(const string& napis, char znak, vector<string> elementy){
	stringstream strumien(napis);
    string element = "";

    while (getline(strumien, element, znak)) {
        elementy.push_back(element);
    }

    return elementy;
}