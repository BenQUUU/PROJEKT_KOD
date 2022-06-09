#include "Kodek.h"
#include <map>
#include <iostream>
#include <string>
#include <iomanip>

Kodek::Kodek(){
	tekst_odkodowany = "";
	tekst_zakodowany = "";
	wczytaj_morsea();
	wczytaj_ascii();
}

void Kodek::wczytaj_morsea() {
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
//funkcja tworząca mapę kodu ASCII
void Kodek::wczytaj_ascii() {
    for (auto& a: mapaMorsea) {
        pair<string, char> para(a.second, a.first);
        mapaASCII.insert(para); //zamienia pierwszy element z drugim mapy Morsea i wstawia do mapy ASCII
    }
}
//funkcja która wyświetla alfabet kodu Morse'a
void Kodek::wyswietl_mape() {
    int licznik = 1;
    const int szerokosc = 8;

    cout << "Alfabet morse'a: " << endl << endl;

    for (auto& x : mapaMorsea) {
        if (x.first != ' ') {
            cout << x.first << " = " << setw(szerokosc) << left << x.second;
            licznik++;
            if (licznik > 6) { //składa się z sześciu kolumn
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