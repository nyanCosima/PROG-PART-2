#include "myTypes.h"


/*
Recebe os par�metros do utilizador (ID, nome do condutor, n�mero de horas de um turno, n�mero m�ximo de horas
por semana e n�mero m�nimo de horas de descanso entre turnos) e guarda-os num novo Driver, que � adicionado
ao vetor criado anteriormente.
*/
void createDriver()
{
	unsigned int id, shift, numMaxHours, nminRestHours;
	int verify = -1;
	bool validInput = false;
	string name;

	cout << "Criar condutor" << endl << endl;

	//Recebe o ID do utilizador, tendo em conta o input v�lido/inv�lido.

	while (!validInput)
	{
		cout << "Identificador do condutor: ";

		if (cin >> id && id>0)
		{
			verify = searchDriverIdentifier(id);

			if (id > 1000)
			{
				cin.ignore(1000, '\n');
				cout << "Insira um ID com, no m�ximo, 3 d�gitos." << endl;
			}

			else if (verify == -1)
			{
				validInput = true;
				cin.ignore(1000, '\n');
			}
			else
			{
				cin.ignore(1000, '\n');
				cout << "Esse identificador j� existe! Tente novamente..." << endl;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		}
	}


	//Recebe o nome do motorista do utilizador

	validInput = false;
	while (!validInput)
	{
		cout << "Nome do condutor: ";
		getline(cin, name);

		if (name == "")
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		else
			validInput = true;
	}

	//Recebe o n�mero de horas de um turno

	validInput = false;
	while (!validInput)
	{
		cout << "N�mero de horas de um turno: ";
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
				cout << "Deve inserir mais horas. Ningu�m trabalha t�o pouco!" << endl;
			}
			else
			{
				cin.ignore(1000, '\n');
				cout << "Input inv�lido! Tente novamente..." << endl << endl;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		}
	}

	// Recebe o n�mero m�ximo de horas por semana

	validInput = false;
	while (!validInput)
	{
		cout << "N�mero m�ximo de horas de condu��o por semana: ";
		if (cin >> numMaxHours)
		{
			if (numMaxHours<0)
			{
				cin.ignore(1000, '\n');
				cout << "Input inv�lido! Tente novamente..." << endl << endl;
			}
			else if (numMaxHours <= shift)
			{
				cin.ignore(1000, '\n');
				cout << "N�o � poss�vel atribuir esse n�mero! Deve inserir mais horas." << endl;
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
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		}
	}

	//Recebe o n�mero de horas de descanso

	validInput = false;
	while (!validInput)
	{
		cout << "N�mero m�nimo de horas de descanso: ";
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
				cout << "Input inv�lido! Tente novamente..." << endl << endl;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		}

	}

	Driver newDriver(id, name, shift, numMaxHours, nminRestHours);
	driversData.push_back(newDriver);

	cout << "Condutor criado com sucesso!" << endl;
}

/*
Edita os condutores j� criados. Fornece meios para: alterar o n�mero de horas de um turno, o n�mero m�ximo
de horas de trabalho por semana, e o n�mero m�nimo de horas de descanso.
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
				cout << "Esse identificador n�o existe! Tente novamente..." << endl << endl;
			}

		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		}
	}

	id = idN;

	//Apresenta uma interface com as fun��es que permitem alterar um condutor

	cout << endl << "Escolha o que pretende alterar" << endl << endl;
	cout << "1 - Alterar nome" << endl;
	cout << "2 - Alterar turno" << endl;
	cout << "3 - Alterar n�mero m�ximo de horas de trabalho" << endl;
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
				cout << "Esse identificador n�o existe! Tente novamente..." << endl << endl;
			}

		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		}
	}

	driversData.erase(driversData.begin() + verify);

	cout << "Condutor apagado com sucesso!" << endl;
}

/*
Altera o n�mero de horas de um turno de um condutor.
*/
void changeShift(unsigned int id)
{
	int index;
	unsigned int newShift;
	int newShiftN;
	bool validInput = false;

	index = searchDriverIdentifier(id);

	cout << "Alterar turno" << endl;

	cout << endl << "O n�mero atual de horas de um turno �: " << driversData[index].getShiftMaxDuration() << endl;

	while (!validInput)
	{
		cout << "Novo n�mero de horas: ";

		if (cin >> newShiftN)
		{
			if (newShiftN < 0)
			{
				cin.ignore(1000, '\n');
				cout << "Input inv�lido! Tente novamente..." << endl;
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
			cout << "Input inv�lido! Tente novamente..." << endl;
		}
	}

	newShift = newShiftN;

	driversData[index].setShiftMaxDuration(newShift);

	cout << "Altera��o efetuada com sucesso!" << endl;
}

/*
Altera o n�mero m�ximo de horas de trabalho por semana de um condutor.
*/
void changeMaxHours(unsigned int id)
{
	int index;
	unsigned int newMaxHours;
	int newMaxHoursN;
	bool validInput = false;

	index = searchDriverIdentifier(id);

	cout << "Alterar n�mero m�ximo de horas de trabalho" << endl;

	cout << endl << "O n�mero m�ximo atual de horas de trabalho �: " << driversData[index].getMaxWeekWorkingTime() << " por semana" << endl;

	while (!validInput)
	{
		cout << "Novo n�mero de horas: ";

		if (cin >> newMaxHoursN)
		{
			if (newMaxHoursN<0)
			{
				cin.ignore(1000, '\n');
				cout << "Input inv�lido! Tente novamente..." << endl << endl;
			}
			else if (newMaxHoursN <= driversData[index].getShiftMaxDuration())
			{
				cin.ignore(1000, '\n');
				cout << "N�o � poss�vel atribuir esse n�mero! Deve inserir mais horas." << endl;
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
			cout << "Input inv�lido! Tente novamente..." << endl;
		}
	}

	newMaxHours = newMaxHoursN;

	driversData[index].setMaxWeekWorkingTime(newMaxHours);

	cout << "Altera��o efetuada com sucesso!" << endl;
}

/*
Altera o n�mero m�nimo de horas de descanso entre turnos de um condutor.
*/
void changeMinRest(unsigned int id)
{
	int index;
	unsigned int newMinRest;
	int newMinRestN;
	bool validInput = false;

	index = searchDriverIdentifier(id);

	cout << "Alterar horas de descanso entre turnos" << endl;

	cout << endl << "O n�mero m�nimo atual de horas de descanso entre turnos �: " << driversData[index].getMinRestTime() << endl;

	while (!validInput)
	{
		cout << "Novo n�mero de horas: ";

		if (cin >> newMinRestN)
		{
			if (newMinRestN < 0)
			{
				cin.ignore(1000, '\n');
				cout << "Input inv�lido! Tente novamente..." << endl;
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
			cout << "Input inv�lido! Tente novamente..." << endl;
		}
	}

	newMinRest = newMinRestN;

	driversData[index].setMinRestTime(newMinRest);

	cout << "Altera��o efetuada com sucesso!" << endl;
}

/*
Altera o nome de um condutor. Pode ser �til, por exemplo, na eventualidade de um condutor ser substitu�do
e o n�mero identificador de manter.
*/
void changeName(unsigned int id)
{
	int index;
	string newName;
	bool validInput = false;

	index = searchDriverIdentifier(id);

	cout << "Alterar nome" << endl;

	cout << endl << "O nome do condutor atual �: " << driversData[index].getName() << endl;

	while (!validInput)
	{
		cout << "Novo nome: ";
		getline(cin, newName);

		if (newName == "")
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		else
			validInput = true;
	}

	driversData[index].setName(newName);

	cout << "As altera��es foram efetuadas com sucesso!" << endl;
}