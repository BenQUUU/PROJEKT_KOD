#ifndef KODER_H
#define KODER_H
#include "Pliki.h"
#include "Kodek.h"
#include <map>
#include <iostream>
using namespace std;

class Koder: public Pliki, public Kodek {
public:
	string kodowanie(char reply);
};
#endif
