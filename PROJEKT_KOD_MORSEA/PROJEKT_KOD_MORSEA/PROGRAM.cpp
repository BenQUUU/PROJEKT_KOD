#include "PROGRAM.hpp"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <conio.h>
#include <sstream>
using namespace std;

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
    string tempString = "";
    char tempChar = ' ';

    do {
        tempChar = _getch();

        if (tempChar == 13) {
            cout << "Zdanie w kodzie morsea: " << tempString << endl;
            exit(1);
        }

        cout << "Znak: " << tempChar << " kod: " << mapaMorsea.find(tempChar)->second << endl;

        tempString += mapaMorsea.find(tempChar)->second;

        cout << endl;
        cin.clear();
    } while (1);
}
void Program::dekoder() {
    cin.clear();
    string napis = "";
    vector<string> morse;
    
    cout << "Wprowadz zdanie w kodzie morsea: ";
    getline(cin, napis);

    cout << "Przetlumaczone z kodu morsea: ";

    morse = rozdziel(napis, ' ', kod);

    for (unsigned int i = 0; i < morse.size(); i++) {
        if (i == 0) {
            cout << char(mapaASCII.find(morse[i])->second - 32);
        }
        else {
            cout << mapaASCII.find(morse[i])->second;
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
