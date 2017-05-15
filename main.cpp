#include "myTypes.h"
#include <string>
#include "Company.h"
#include <iostream>

using namespace std;

void mainUserInterface(Company &company);

int main(){

	setPTChar(); //Permite o uso de carateres portugueses no input/output

	//cout << "Ficheiro das linhas: ";
	//getline(cin, linesFileName);

	//cout << "Ficheiro dos condutores: ";
	//getline(cin, driversFileName);

	string lines = "linhas.txt";
	string drivers = "condutores.txt";

	Company SRL("SEMPRAROLAR", lines, drivers);


	mainUserInterface(SRL); //Invoca a interface principal

	return 0;
}
