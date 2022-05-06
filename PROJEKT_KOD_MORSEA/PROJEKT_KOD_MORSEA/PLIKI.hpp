#ifndef PLIKI_HPP
#define PLIKI_HPP
#include <iostream>
#include <string>
#include "PROGRAM.hpp"
using namespace std;

class Pliki: public Program {
public:
	void zapis();
	void odczyt();
};

#endif // !PLIKI_HPP

