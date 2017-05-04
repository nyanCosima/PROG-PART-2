#include "myTypes.h"


/*
Recebe os par�metros do utilizador (ID, nome do condutor, n�mero de horas de um turno, n�mero m�ximo de horas
por semana e n�mero m�nimo de horas de descanso entre turnos) e guarda-os num novo Driver, que � adicionado
ao vetor criado anteriormente.
*/
void createDriver(Company &company)
{
	unsigned int id, shift, numMaxHours, nminRestHours;
	int verify = -1;
	bool validInput = false;
	string name, input;

	cout << "Criar condutor" << endl << endl;

	//Recebe o ID do utilizador, tendo em conta o input v�lido/inv�lido.

	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		getline(cin, input);

		if (input.size() <= 3) //S� s�o aceites IDs com, no m�ximo 3 d�gitos
		{

			if (isNumber(input)) //Se o input for um n�mero positivo
			{
				verify = company.searchDriverIdentifier(stoi(input)); //Verifica a exist�ncia do ID

				if (verify == -1)
					validInput = true;
				else
					cout << "Esse ID j� existe! Tente novamente..." << endl;
			}
			else
				cout << "Input inv�lido! Tente novamente..." << endl;
		}
		else
			cout << "Input inv�lido! Tente novamente..." << endl;
	}

	id = stoi(input);

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
		getline(cin, input);

		if (isNumber(input))
		{
			shift = stoi(input);

			if (shift > 0 && shift <= 7)
				validInput = true;
			else
				cout << "Ajuste o valor inserido. Tente novamente..." << endl;
		}
		else
			cout << "Input inv�lido! Tente novamente..." << endl;
	}

	// Recebe o n�mero m�ximo de horas por semana

	validInput = false;
	while (!validInput)
	{
		cout << "N�mero m�ximo de horas de condu��o por semana: ";
		getline(cin, input);

		if (isNumber(input))
		{
			numMaxHours = stoi(input);

			if (numMaxHours > shift && numMaxHours <= 40)
				validInput = true;
			else
				cout << "Ajuste o valor inserido. Tente novamente..." << endl;
		}
		else
			cout << "Input inv�lido! Tente novamente..." << endl;
	}

	//Recebe o n�mero de horas de descanso

	validInput = false;
	while (!validInput)
	{
		cout << "N�mero m�nimo de horas de descanso: ";
		getline(cin, input);

		if (isNumber(input))
		{
			nminRestHours = stoi(input);

			if (nminRestHours > 0 && nminRestHours <= 7)
				validInput = true;
			else
				cout << "Ajuste o valor inserido. Tente novamente..." << endl;
		}
		else
			cout << "Input inv�lido! Tente novamente..." << endl;
	}

	Driver newDriver(id, name, shift, numMaxHours, nminRestHours);
	company.addDriver(newDriver);

	cout << "Condutor criado com sucesso!" << endl;
}

/*
Edita os condutores j� criados. Fornece meios para: alterar o n�mero de horas de um turno, o n�mero m�ximo
de horas de trabalho por semana, e o n�mero m�nimo de horas de descanso.
*/
void editDriver(Company &company)
{
	int userChoice;
	unsigned int id;
	string input;
	int verify = -1;
	bool validInput = false;

	cout << "Alterar condutor" << endl << endl;

	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		getline(cin, input);

		if (input.size() <= 3) //S� s�o aceites IDs com, no m�ximo 3 d�gitos
		{

			if (isNumber(input)) //Se o input for um n�mero positivo
			{
				verify = company.searchDriverIdentifier(stoi(input)); //Verifica a exist�ncia do ID

				if (verify != -1)
					validInput = true;
				else
					cout << "Esse ID n�o existe! Tente novamente..." << endl;
			}
			else
				cout << "Input inv�lido! Tente novamente..." << endl;
		}
		else
			cout << "Input inv�lido! Tente novamente..." << endl;
	}

	id = stoi(input);

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
		changeName(company, id);
	else if (userChoice == 2)
		changeShift(company, id);
	else if (userChoice == 3)
		changeMaxHours(company, id);
	else if (userChoice == 4)
		changeMinRest(company, id);
	else if (userChoice == 5)
		driversInterface(company);
}

/*
Recebe do utilizador um identificador para um condutor, e caso exista apaga-o do vetor de Drivers.
*/
void removeDriver(Company &company)
{
	string input;
	int verify = -1;
	bool validInput = false;

	cout << "Remover condutor" << endl << endl;

	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		getline(cin, input);

		if (input.size() <= 3) //S� s�o aceites IDs com, no m�ximo 3 d�gitos
		{
			if (isNumber(input)) //Se o input for um n�mero positivo
			{
				verify = company.searchDriverIdentifier(stoi(input)); //Verifica a exist�ncia do ID

				if (verify != -1)
					validInput = true;
				else
					cout << "Esse ID n�o existe! Tente novamente..." << endl;
			}
			else
				cout << "Input inv�lido! Tente novamente..." << endl;
		}
		else
			cout << "Input inv�lido! Tente novamente..." << endl;
	}

	company.removeDriver(verify);

	cout << "Condutor apagado com sucesso!" << endl;
}

/*
Altera o n�mero de horas de um turno de um condutor.
*/
void changeShift(Company &company, unsigned int id)
{
	int index;
	unsigned int newShift;
	string input;
	bool validInput = false;

	index = company.searchDriverIdentifier(id);

	cout << "Alterar turno" << endl;

	cout << endl << "O n�mero atual de horas de um turno �: " << company.getDrivers()[index].getShiftMaxDuration() << endl;

	while (!validInput)
	{
		cout << "Novo n�mero de horas: ";
		getline(cin, input);

		if (isNumber(input))
		{
			newShift = stoi(input);

			if (newShift == 0)
				cout << "Deve inserir mais horas!" << endl;
			else if (newShift >= 24)
				cout << "Deve inserir um valor mais baixo!" << endl;	
			else
				validInput = true;
		}
		else
			cout << "Input inv�lido! Tente novamente..." << endl;
	}

	vector<Driver> newDrivers = company.getDrivers();
	newDrivers[index].setShiftMaxDuration(newShift);
	company.setDrivers(newDrivers);

	cout << "Altera��o efetuada com sucesso!" << endl;
}

/*
Altera o n�mero m�ximo de horas de trabalho por semana de um condutor.
*/
void changeMaxHours(Company &company, unsigned int id)
{
	int index;
	string input;
	unsigned int newMaxHours;
	bool validInput = false;

	index = company.searchDriverIdentifier(id);

	cout << "Alterar n�mero m�ximo de horas de trabalho" << endl;

	cout << endl << "O n�mero m�ximo atual de horas de trabalho �: " << company.getDrivers()[index].getMaxWeekWorkingTime() << " por semana" << endl;

	while (!validInput)
	{
		cout << "Novo n�mero de horas: ";
		getline(cin, input);

		if (isNumber(input))
		{
			newMaxHours = stoi(input);

			if (newMaxHours <= company.getDrivers()[index].getShiftMaxDuration())
				cout << "N�o � poss�vel atribuir esse n�mero! Deve inserir mais horas." << endl;
			else
				validInput = true;
		}
		else
			cout << "Input inv�lido! Tente novamente..." << endl;
		}


	vector<Driver> newDrivers = company.getDrivers();
	newDrivers[index].setMaxWeekWorkingTime(newMaxHours);
	company.setDrivers(newDrivers);

	cout << "Altera��o efetuada com sucesso!" << endl;
}

/*
Altera o n�mero m�nimo de horas de descanso entre turnos de um condutor.
*/
void changeMinRest(Company &company, unsigned int id)
{
	int index;
	unsigned int newMinRest;
	string input;
	bool validInput = false;

	index = company.searchDriverIdentifier(id);

	cout << "Alterar horas de descanso entre turnos" << endl;

	cout << endl << "O n�mero m�nimo atual de horas de descanso entre turnos �: " << company.getDrivers()[index].getMinRestTime() << endl;

	while (!validInput)
	{
		cout << "Novo n�mero de horas: ";
		getline(cin, input);

		if (isNumber(input))
		{
			newMinRest = stoi(input);

			if (newMinRest == 0)
				cout << "Deve inserir mais horas!" << endl;
			else
				validInput = true;
		}
		else
			cout << "Input inv�lido! Tente novamente..." << endl;
	}

	vector<Driver> newDrivers=company.getDrivers();
	newDrivers[index].setMinRestTime(newMinRest);
	company.setDrivers(newDrivers);

	cout << "Altera��o efetuada com sucesso!" << endl;
}

/*
Altera o nome de um condutor. Pode ser �til, por exemplo, na eventualidade de um condutor ser substitu�do
e o n�mero identificador de manter.
*/
void changeName(Company &company, unsigned int id)
{
	int index;
	string newName;
	bool validInput = false;

	index = company.searchDriverIdentifier(id);

	cout << "Alterar nome" << endl;

	cout << endl << "O nome do condutor atual �: " << company.getDrivers()[index].getName() << endl;

	while (!validInput)
	{
		cout << "Novo nome: ";
		getline(cin, newName);

		if (newName == "")
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		else
			validInput = true;
	}

	vector<Driver> newDrivers=company.getDrivers();
	newDrivers[index].setName(newName);
	company.setDrivers(newDrivers);

	cout << "As altera��es foram efetuadas com sucesso!" << endl;
}

/*
Apresenta informa��o relativa ao trabalho atribu�do a um condutor especificado pelo utilizador, que � traduzida nos
turnos que tem que realizar.
*/
void showShifts(Company company)
{
	bool validInput = false;
	string input;
	int verify = -1;

	cout << "Visualizar trabalho do condutor" << endl << endl;

	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		getline(cin, input);

		if (input.size() <= 3) //S� s�o aceites IDs com, no m�ximo 3 d�gitos
		{

			if (isNumber(input)) //Se o input for um n�mero positivo
			{
				verify = company.searchDriverIdentifier(stoi(input)); //Verifica a exist�ncia do ID

				if (verify != -1)
					validInput = true;
				else
					cout << "Esse ID n�o existe! Tente novamente..." << endl;
			}
			else
				cout << "Input inv�lido! Tente novamente..." << endl;
		}
		else
			cout << "Input inv�lido! Tente novamente..." << endl;
	}

	if (company.getDrivers()[verify].getShifts().size() == 0)
		cout << "De momento, o condutor n�o tem qualquer trabalho atribu�do." << endl;
	else
		for (int i = 0; i < company.getDrivers()[verify].getShifts().size(); i++)
		{
			cout << "Turno " << i + 1 << endl;
			company.getDrivers()[verify].getShifts()[i].showInfo();
			cout << endl;
		}
}