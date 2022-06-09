#include "Pliki.h"
#include "Koder.h"
#include "Dekoder.h"
#include "Menu.h"
#include <iostream>
#include <map>
#include <locale.h>
using namespace std;

int main(int argc, char** argv) {
setlocale(LC_CTYPE, ""); //polskie znaki w konsoli
while(1){
	try{
		Menu menu;
		menu.wywolanie_menu();
		system("pause");
	}
	catch(runtime_error & e){
		cout << e.what() << endl;
	}
	catch(int e){
		cout << "Blad odczytu pliku!" << endl;
	}	
}

	return 0;
}
