#include "Pliki.h"
#include "Koder.h"
#include "Dekoder.h"
#include "Menu.h"
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char** argv) {
while(1){
	try{
		Menu menu;
		menu.wywolanieMenu();
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
