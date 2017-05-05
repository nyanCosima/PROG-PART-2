#include "Company.h"
#include <string>
#include <iostream>
#include "myTypes.h"

using namespace std;

/*
Pergunta ao utilizador se pretende guardar as alteraÁıes e age de acordo com a sua resposta.
*/
void savingChanges(Company company)
{
	string userChoice;
	bool validInput = false;

	while (!validInput)
	{
		cout <<  "Deseja guardar as alterações? (S/N) : ";
		getline(cin, userChoice);

		if (userChoice == "S" || userChoice == "N" || userChoice == "s" || userChoice == "n")
			validInput = true;
		else
			cout << "Opção inválida, tente novamente..." << endl << endl;
	}

	if (userChoice == "S" || userChoice == "s")
	{
		company.savingDriversData();
		company.savingLinesData();
	}
}