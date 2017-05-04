#include "myTypes.h"

//Definição das constantes de início e fim de serviço
int serviceStartingTime = 6 * 60, serviceEndingTime = 19 * 60;

string linesFileName, driversFileName;

int main(){

	setPTChar(); //Permite o uso de carateres portugueses no input/output

	//cout << "Ficheiro das linhas: ";
	//getline(cin, linesFileName);

	//cout << "Ficheiro dos condutores: ";
	//getline(cin, driversFileName);

	linesFileName = "linhas.txt";
	driversFileName = "condutores.txt";

	Company SRL("SEMPRAROLAR");

	mainUserInterface(SRL); //Invoca a interface principal

	return 0;
}
