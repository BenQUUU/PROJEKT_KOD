#include "PROGRAM.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <conio.h>
#include <sstream>
#include <cctype>
using namespace std;

Program::Program() {
    napis = "";
}

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
void Program::wczytaj_ascii() {
    for (auto& a: mapaMorsea) {
        pair<string, char> para(a.second, a.first);
        mapaASCII.insert(para);
    }
}
void Program::koder() {
    char tempChar = ' ';

    cout << "Kodowanie: " << endl << endl;

    do {
        tempChar = _getch();

        tempChar = tolower(tempChar);

        if (mapaMorsea.find(tempChar) == mapaMorsea.end() && tempChar != 13) {
            cout << "Podana litera nie znajduje sie w kodzie Morsea!" << endl;
            cin.clear();
            break;
        }

        if (tempChar == 13) {
            cout << "Zdanie w kodzie morsea: " << napis << endl;
            exit(0);
        }
      
        cout << "Znak: " << tempChar << " kod: " << mapaMorsea.find(tempChar)->second << endl;

        napis += mapaMorsea.find(tempChar)->second + " ";

        cout << endl;
        cin.clear();
        
    } while (1);
}
void Program::dekoder() {
    cin.clear();
    string napis = "";
    vector<string> morse;
    
    cout << "WprowadŸ zdanie w kodzie morsea: ";
    getline(cin, napis);

    cout << "Przet³umaczone z kodu morsea: ";

    morse = rozdziel(napis, ' ', kod);

    for (unsigned int i = 0; i < morse.size(); i++) {
        if (mapaASCII.find(morse[i]) == mapaASCII.end()) {
            if (morse[i] != "") {
                nieznalezione.push_back(morse[i]);
            }
        }
        else {
            if (i == 0) {
                cout << char(mapaASCII.find(morse[i])->second - 32);
            }
            else {
                cout << mapaASCII.find(morse[i])->second;
            }
        }
    }
    if (nieznalezione.size() != 0) {
        cout << endl << "Niepoprawnie wprowadzone litery: ";
        for (unsigned int i = 0; i < nieznalezione.size(); i++) {
            cout << "'" << nieznalezione[i] << "', ";
        }
    }
    cout << endl;
}
vector<string> Program::rozdziel(const string& napis, char znak, vector<string> elementy) {
    stringstream strumien(napis);
    string element = "";

    while (getline(strumien, element, znak)) {
        elementy.push_back(element);
    }

    return elementy;
}
