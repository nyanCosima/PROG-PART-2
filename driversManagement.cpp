#include "myTypes.h"


/*
Recebe os parâmetros do utilizador (ID, nome do condutor, número de horas de um turno, número máximo de horas
por semana e número mínimo de horas de descanso entre turnos) e guarda-os num novo Driver, que é adicionado
ao vetor criado anteriormente.
*/
void createDriver()
{
	unsigned int id, shift, numMaxHours, nminRestHours;
	int verify = -1;
	bool validInput = false;
	string name;

	cout << "Criar condutor" << endl << endl;

	//Recebe o ID do utilizador, tendo em conta o input válido/inválido.

	while (!validInput)
	{
		cout << "Identificador do condutor: ";

		if (cin >> id && id>0)
		{
			verify = searchDriverIdentifier(id);

			if (id > 1000)
			{
				cin.ignore(1000, '\n');
				cout << "Insira um ID com, no máximo, 3 dígitos." << endl;
			}

			else if (verify == -1)
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			else
			{
				cin.ignore(1000, '\n');
				cout << "Esse identificador já existe! Tente novamente..." << endl;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inválido! Tente novamente..." << endl << endl;
		}
	}


	//Recebe o nome do motorista do utilizador

	validInput = false;
	while (!validInput)
	{
		cout << "Nome do condutor: ";
		getline(cin, name);

		if (name == "")
			cout << "Input inválido! Tente novamente..." << endl << endl;
		else
			validInput = true;
	}

	//Recebe o número de horas de um turno

	validInput = false;
	while (!validInput)
	{
		cout << "Número de horas de um turno: ";
		if (cin >> shift)
		{
			if (shift > 0)
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			else if (shift == 0)
			{
				cin.ignore(1000, '\n');
				cout << "Deve inserir mais horas. Ninguém trabalha tão pouco!" << endl;
			}
			else
			{
				cin.ignore(1000, '\n');
				cout << "Input inválido! Tente novamente..." << endl << endl;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inválido! Tente novamente..." << endl << endl;
		}
	}

	// Recebe o número máximo de horas por semana

	validInput = false;
	while (!validInput)
	{
		cout << "Número máximo de horas de condução por semana: ";
		if (cin >> numMaxHours)
		{
			if (numMaxHours<0)
			{
				cin.ignore(1000, '\n');
				cout << "Input inválido! Tente novamente..." << endl << endl;
			}
			else if (numMaxHours <= shift)
			{
				cin.ignore(1000, '\n');
				cout << "Não é possível atribuir esse número! Deve inserir mais horas." << endl;
			}
			else
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}

		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inválido! Tente novamente..." << endl << endl;
		}
	}

	//Recebe o número de horas de descanso

	validInput = false;
	while (!validInput)
	{
		cout << "Número mínimo de horas de descanso: ";
		if (cin >> nminRestHours)
		{
			if (nminRestHours > 0)
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			else if (nminRestHours == 0)
			{
				cin.ignore(1000, '\n');
				cout << "Seja mais generoso! Insira mais horas." << endl;
			}
			else
			{
				cin.ignore(1000, '\n');
				cout << "Input inválido! Tente novamente..." << endl << endl;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inválido! Tente novamente..." << endl << endl;
		}

	}

	Driver newDriver(id, name, shift, numMaxHours, nminRestHours);
	driversData.push_back(newDriver);

	cout << "Condutor criado com sucesso!" << endl;
}

/*
Edita os condutores já criados. Fornece meios para: alterar o número de horas de um turno, o número máximo
de horas de trabalho por semana, e o número mínimo de horas de descanso.
*/
void editDriver()
{
	int userChoice;
	unsigned int id;
	int idN;
	int verify = -1;
	bool validInput = false;

	cout << "Alterar condutor" << endl << endl;

	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		if (cin >> idN && idN>0)
		{
			verify = searchDriverIdentifier(idN);

			if (verify != -1)
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			else
			{
				cin.ignore(1000, '\n');
				cout << "Esse identificador não existe! Tente novamente..." << endl << endl;
			}

		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inválido! Tente novamente..." << endl << endl;
		}
	}

	id = idN;

	//Apresenta uma interface com as funções que permitem alterar um condutor

	cout << endl << "Escolha o que pretende alterar" << endl << endl;
	cout << "1 - Alterar nome" << endl;
	cout << "2 - Alterar turno" << endl;
	cout << "3 - Alterar número máximo de horas de trabalho" << endl;
	cout << "4 - Alterar horas de descanso entre turnos" << endl;
	cout << "5 - Voltar" << endl << endl;

	userChoice = verifyInput(1, 5);

	clearScreen();

	if (userChoice == 1)
		changeName(id);
	else if (userChoice == 2)
		changeShift(id);
	else if (userChoice == 3)
		changeMaxHours(id);
	else if (userChoice == 4)
		changeMinRest(id);
	else if (userChoice == 5)
		driversInterface();
}

/*
Recebe do utilizador um identificador para um condutor, e caso exista apaga-o do vetor de Drivers.
*/
void removeDriver()
{
	int idN;
	int verify = -1;
	bool validInput = false;

	cout << "Remover condutor" << endl << endl;

	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		if (cin >> idN && idN>0)
		{
			verify = searchDriverIdentifier(idN);

			if (verify != -1)
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			else
			{
				cin.ignore(1000, '\n');
				cout << "Esse identificador não existe! Tente novamente..." << endl << endl;
			}

		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inválido! Tente novamente..." << endl << endl;
		}
	}

	driversData.erase(driversData.begin() + verify);

	cout << "Condutor apagado com sucesso!" << endl;
}

/*
Altera o número de horas de um turno de um condutor.
*/
void changeShift(unsigned int id)
{
	int index;
	unsigned int newShift;
	int newShiftN;
	bool validInput = false;

	index = searchDriverIdentifier(id);

	cout << "Alterar turno" << endl;

	cout << endl << "O número atual de horas de um turno é: " << driversData[index].getShiftMaxDuration() << endl;

	while (!validInput)
	{
		cout << "Novo número de horas: ";

		if (cin >> newShiftN)
		{
			if (newShiftN < 0)
			{
				cin.ignore(1000, '\n');
				cout << "Input inválido! Tente novamente..." << endl;
			}
			else if (newShiftN == 0)
			{
				cin.ignore(1000, '\n');
				cout << "Deve inserir mais horas!" << endl;
			}
			else if (newShiftN >= 24)
			{
				cin.ignore(1000, '\n');
				cout << "Deve inserir um valor mais baixo!" << endl;	
			}
			else
			{
				cin.ignore(1000, '\n');
				validInput = true;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inválido! Tente novamente..." << endl;
		}
	}

	newShift = newShiftN;

	driversData[index].setShiftMaxDuration(newShift);

	cout << "Alteração efetuada com sucesso!" << endl;
}

/*
Altera o número máximo de horas de trabalho por semana de um condutor.
*/
void changeMaxHours(unsigned int id)
{
	int index;
	unsigned int newMaxHours;
	int newMaxHoursN;
	bool validInput = false;

	index = searchDriverIdentifier(id);

	cout << "Alterar número máximo de horas de trabalho" << endl;

	cout << endl << "O número máximo atual de horas de trabalho é: " << driversData[index].getMaxWeekWorkingTime() << " por semana" << endl;

	while (!validInput)
	{
		cout << "Novo número de horas: ";

		if (cin >> newMaxHoursN)
		{
			if (newMaxHoursN<0)
			{
				cin.ignore(1000, '\n');
				cout << "Input inválido! Tente novamente..." << endl << endl;
			}
			else if (newMaxHoursN <= driversData[index].getShiftMaxDuration())
			{
				cin.ignore(1000, '\n');
				cout << "Não é possível atribuir esse número! Deve inserir mais horas." << endl;
			}
			else
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inválido! Tente novamente..." << endl;
		}
	}

	newMaxHours = newMaxHoursN;

	driversData[index].setMaxWeekWorkingTime(newMaxHours);

	cout << "Alteração efetuada com sucesso!" << endl;
}

/*
Altera o número mínimo de horas de descanso entre turnos de um condutor.
*/
void changeMinRest(unsigned int id)
{
	int index;
	unsigned int newMinRest;
	int newMinRestN;
	bool validInput = false;

	index = searchDriverIdentifier(id);

	cout << "Alterar horas de descanso entre turnos" << endl;

	cout << endl << "O número mínimo atual de horas de descanso entre turnos é: " << driversData[index].getMinRestTime() << endl;

	while (!validInput)
	{
		cout << "Novo número de horas: ";

		if (cin >> newMinRestN)
		{
			if (newMinRestN < 0)
			{
				cin.ignore(1000, '\n');
				cout << "Input inválido! Tente novamente..." << endl;
			}
			else if (newMinRestN == 0)
			{
				cin.ignore(1000, '\n');
				cout << "Deve inserir mais horas!" << endl;
			}
			else
			{
				cin.ignore(1000, '\n');
				validInput = true;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inválido! Tente novamente..." << endl;
		}
	}

	newMinRest = newMinRestN;

	driversData[index].setMinRestTime(newMinRest);

	cout << "Alteração efetuada com sucesso!" << endl;
}

/*
Altera o nome de um condutor. Pode ser útil, por exemplo, na eventualidade de um condutor ser substituído
e o número identificador de manter.
*/
void changeName(unsigned int id)
{
	int index;
	string newName;
	bool validInput = false;

	index = searchDriverIdentifier(id);

	cout << "Alterar nome" << endl;

	cout << endl << "O nome do condutor atual é: " << driversData[index].getName() << endl;

	while (!validInput)
	{
		cout << "Novo nome: ";
		getline(cin, newName);

		if (newName == "")
			cout << "Input inválido! Tente novamente..." << endl << endl;
		else
			validInput = true;
	}

	driversData[index].setName(newName);

	cout << "As alterações foram efetuadas com sucesso!" << endl;
}