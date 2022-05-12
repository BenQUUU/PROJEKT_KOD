#include "PROGRAM.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <conio.h>
#include <sstream>
#include <cctype>
#include <fstream>
#include <iomanip>
using namespace std;

//konstruktor domyœlny zeruj¹cy pola
Program::Program() {
    napis = "";
    napis_zakodowany = "";
}
//funkcja tworz¹ca mapê kodu Morse'a
void Program::wczytaj_morsea() {
    //spacja
    mapaMorsea[' '] = "/";
    //cyfry
    mapaMorsea['0'] = "-----";
    mapaMorsea['1'] = ".----";
    mapaMorsea['2'] = "..---";
    mapaMorsea['3'] = "...--";
    mapaMorsea['4'] = "....-";
    mapaMorsea['5'] = ".....";
    mapaMorsea['6'] = "-....";
    mapaMorsea['7'] = "--...";
    mapaMorsea['8'] = "---..";
    mapaMorsea['9'] = "----.";
    //litery
    mapaMorsea['a'] = ".-";
    mapaMorsea['b'] = "-...";
    mapaMorsea['c'] = "-.-.";
    mapaMorsea['d'] = "-..";
    mapaMorsea['e'] = ".";
    mapaMorsea['f'] = "..-.";
    mapaMorsea['g'] = "--.";
    mapaMorsea['h'] = "....";
    mapaMorsea['i'] = "..";
    mapaMorsea['j'] = ".---";
    mapaMorsea['k'] = "-.-";
    mapaMorsea['l'] = ".-..";
    mapaMorsea['m'] = "--";
    mapaMorsea['n'] = "-.";
    mapaMorsea['o'] = "---";
    mapaMorsea['p'] = ".--.";
    mapaMorsea['q'] = "--.-";
    mapaMorsea['r'] = ".-.";
    mapaMorsea['s'] = "...";
    mapaMorsea['t'] = "-";
    mapaMorsea['u'] = "..-";
    mapaMorsea['v'] = "...-";
    mapaMorsea['w'] = ".--";
    mapaMorsea['x'] = "-..-";
    mapaMorsea['y'] = "-.--";
    mapaMorsea['z'] = "--..";
}
//funkcja tworz¹ca mapê kodu ASCII
void Program::wczytaj_ascii() {
    for (auto& a: mapaMorsea) {
        pair<string, char> para(a.second, a.first);
        mapaASCII.insert(para); //zamienia pierwszy element z drugim mapy Morsea i wstawia do mapy ASCII
    }
}
//funkcja która wyœwietla alfabet kodu Morse'a
void Program::wyswietl_mape() {
    int licznik = 1;
    const int szerokosc = 8;

    cout << "Alfabet morse'a: " << endl << endl;

    for (auto& x : mapaMorsea) {
        if (x.first != ' ') {
            cout << x.first << " = " << setw(szerokosc) << left << x.second;
            licznik++;
            if (licznik > 6) { //sk³ada siê z szeœciu kolumn
                cout << endl;
                licznik = 1;
            }
        }
        else {
            cout << "spacja = " << x.second << endl << endl;
        }
    }
    cout << endl << endl;
}
//funkcja koduj¹ca znaki na kod morse'a w czasie rzeczywistym
void Program::koder() {
    char tempChar = ' ';

    cout << "Kodowanie[ENTER koñczy dzia³anie programu]: " << endl << endl;

    do {
        tempChar = _getch(); //getch() pobiera od u¿ytkownika znak

        tempChar = tolower(tempChar); //wszystkie wprowadzone du¿e litery s¹ zamieniane na ma³e

        //wprowadzenie niepoprawnej litery wyœwietla b³¹d
        if (mapaMorsea.find(tempChar) == mapaMorsea.end() && tempChar != 13) {
            cout << "Podana litera nie znajduje sie w kodzie Morsea!" << endl << endl;
            cin.clear();
        }
        else {
            napis += tempChar;

            //program dzia³a dopóki u¿ytkownik nie naciœnie ENTER
            if (tempChar == 13) {
                cout << "Zdanie w kodzie morsea: " << napis_zakodowany << endl;
                break;
            }

            cout << "Znak: " << tempChar << " kod: " << mapaMorsea.find(tempChar)->second << endl;

            napis_zakodowany += mapaMorsea.find(tempChar)->second + " ";

            cout << endl;
            cin.clear();
        }
    } while (1);
}
//funkcja dekoduj¹ca ci¹g kropek i kresek na kod ASCII
void Program::dekoder() {
    cin.clear();
    vector<string> morse;
    string tekst = "";
    
    cout << "WprowadŸ zdanie w kodzie morsea: ";
    //getline(cin, tekst);
    cin.ignore();
    getline(cin, tekst); //u¿ytkownik wprowadza tekst

    cout << endl << "Przet³umaczone z kodu morsea: ";

    morse = rozdziel(tekst, ' ', kod); //wynik dzia³ania funkcji rozdziel jest zapisywany do zmiennej morse

    for (unsigned int i = 0; i < morse.size(); i++) {
        //je¿eli komputer nie znajdzie w mapie podanej litery zapisuje j¹ to vectora 'nieznalezione'
        if (mapaASCII.find(morse[i]) == mapaASCII.end()) {
            if (morse[i] != "") {
                nieznalezione.push_back(morse[i]);
            }
        }
        else {
            napis_zakodowany += morse[i]; //do zmiennej napis_zakodowany zapisuje element vectora morse
            napis_zakodowany += " ";
            //pierwsza litera zostaje zamieniona na du¿¹
            if (i == 0) {
                cout << char(mapaASCII.find(morse[i])->second - 32); //wyœwietla literê
                napis += char(mapaASCII.find(morse[i])->second - 32); //zapisuje literê do zmiennej napis
            }
            else {
                cout << mapaASCII.find(morse[i])->second; 
                napis += mapaASCII.find(morse[i])->second;
            }
        }
    }
    //je¿eli w vectorze nieznalezione s¹ jakieœ elementy wyœwietli je po dekodowaniu
    if (nieznalezione.size() != 0) {
        cout << endl << "Niepoprawnie wprowadzone litery: ";
        for (unsigned int i = 0; i < nieznalezione.size(); i++) {
            cout << "'" << nieznalezione[i] << "', ";
        }
    }
    cout << endl;
}
//funkcja która która rozdziela napis na elementy vectora jak napotka spacjê
vector<string> Program::rozdziel(const string& napis, char znak, vector<string> elementy) {
    stringstream strumien(napis);
    string element = "";

    while (getline(strumien, element, znak)) {
        elementy.push_back(element);
    }

    return elementy;
}
