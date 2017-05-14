#include "myTypes.h"
#include <string>
#include "Company.h"
#include "Time.h"
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

	showTime(convertMinHours(1379));

	mainUserInterface(SRL); //Invoca a interface principal

	return 0;
}
