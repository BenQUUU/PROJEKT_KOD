#include "Kodek.h"
#include <map>
#include <iostream>
#include <string>
#include <iomanip>

/**
 * \brief Konstruktor domyślny.
 *
 * Tworzy obiekt klasy Kodek, automatycznie zerując pola klasy oraz wywołuje funkcje
 * stworzMapeMorsea() oraz stworzMapeASCII().
 */
Kodek::Kodek(){
	tekst_odkodowany = "";
	tekst_zakodowany = "";
	stworzMapeMorsea();
	stworzMapeASCII();
}
/**
 * \brief Tworzy mape kodu Morse'a
 *
 * Tworzy mape w której kluczem są litery oraz cyfry z alfabetu angielsku a wartością przechowywaną
 * jest ich odpowiednik w kodzie Morse'a.
 *
 */
void Kodek::stworzMapeMorsea() {
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
/**
 * \brief Tworzy mape kodu ASCII
 *
 * Na podstawie mapy Morse'a tworzy mape w której kluczem są litery oraz cyfry z alfabetu Morse'a a 
 * wartością przechowywaną jest ich odpowiednik w alfabecie angielskim.
 *
 */
void Kodek::stworzMapeASCII() {
    for (auto& a: mapaMorsea) {
        pair<string, char> para(a.second, a.first);
        mapaASCII.insert(para); 
    }
}
/**
 * \brief Wyświetla alfabet Morse'a
 *
 * Na podstawie mapy Morse'a w formie tabelki, wyświetla alfabet Morse'a, aby użytkownik mógł z niej skorzystać podczas
 * operacji dekodowania.
 *
 */
void Kodek::wyswietl_mape() {
    int licznik = 1;
    const int szerokosc = 8;

    cout << "Alfabet morse'a: " << endl << endl;

    for (auto& x : mapaMorsea) {
        if (x.first != ' ') {
            cout << x.first << " = " << setw(szerokosc) << left << x.second;
            licznik++;
            if (licznik > 6) { 
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