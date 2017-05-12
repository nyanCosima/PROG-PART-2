#include "myTypes.h"
#include "Company.h"
#include <string>
#include <iostream>

using namespace std;

bool isNumber(string input);

void lineSchedule(Company company){

	int indice;
	string input;
	bool validInput = false;

    //receber input do user
	while (!validInput)
	{
		cout << "Indique o ID da linha: ";
		getline(cin, input);

		if (input.size() <= 3) //Só são aceites IDs com, no máximo 3 dígitos
		{
			if (isNumber(input)) //Se o input for um número positivo
			{
				indice = company.searchLineIdentifier(stoi(input)); //Verifica a existência do ID

				if (indice != -1)
					validInput = true;
				else
					cout << "Esse ID não existe! Tente novamente..." << endl;
			}
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}
		else
			cout << "Input inválido! Tente novamente..." << endl;
	}

	company.getLines()[indice].schedule();
}


void stopSchedule(Company company) {

	bool validInput = false;
	string input;

	while (!validInput)
	{
		cout << "Indique o nome da paragem: ";
		getline(cin, input);

		if(company.searchStop2(input).size()> 0)
			validInput = true;
		else
			cout << "Essa paragem não existe! Tente novamente..." << endl;
		}

    for (int i = 0; i < company.searchStop2(input).size(); ++i) {

   company.getLines()[company.searchStop2(input).at(i)].stopsSchedule(input);
        }
}


