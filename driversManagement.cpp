#include "myTypes.h"


/*
Recebe os parâmetros do utilizador (ID, nome do condutor, número de horas de um turno, número máximo de horas
por semana e número mínimo de horas de descanso entre turnos) e guarda-os num novo Driver, que é adicionado
ao vetor criado anteriormente.
*/
void createDriver(Company &company)
{
	unsigned int id, shift, numMaxHours, nminRestHours;
	int verify = -1;
	bool validInput = false;
	string name, input;

	cout << "Criar condutor" << endl << endl;

	//Recebe o ID do utilizador, tendo em conta o input válido/inválido.

	while (!validInput)
	{
		cout << "Identificador do condutor: ";
		getline(cin, input);

		if (input.size() <= 3) //Só são aceites IDs com, no máximo 3 dígitos
		{

			if (isNumber(input)) //Se o input for um número positivo
			{
				verify = company.searchDriverIdentifier(stoi(input)); //Verifica a existência do ID

				if (verify == -1)
					validInput = true;
				else
					cout << "Esse ID já existe! Tente novamente..." << endl;
			}
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}
		else
			cout << "Input inválido! Tente novamente..." << endl;
	}

	id = stoi(input);

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
			cout << "Input inválido! Tente novamente..." << endl;
	}

	// Recebe o número máximo de horas por semana

	validInput = false;
	while (!validInput)
	{
		cout << "Número máximo de horas de condução por semana: ";
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
			cout << "Input inválido! Tente novamente..." << endl;
	}

	//Recebe o número de horas de descanso

	validInput = false;
	while (!validInput)
	{
		cout << "Número mínimo de horas de descanso: ";
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
			cout << "Input inválido! Tente novamente..." << endl;
	}

	Driver newDriver(id, name, shift, numMaxHours, nminRestHours);
	company.addDriver(newDriver);

	cout << "Condutor criado com sucesso!" << endl;
}

/*
Edita os condutores já criados. Fornece meios para: alterar o número de horas de um turno, o número máximo
de horas de trabalho por semana, e o número mínimo de horas de descanso.
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

		if (input.size() <= 3) //Só são aceites IDs com, no máximo 3 dígitos
		{

			if (isNumber(input)) //Se o input for um número positivo
			{
				verify = company.searchDriverIdentifier(stoi(input)); //Verifica a existência do ID

				if (verify != -1)
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

	id = stoi(input);

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

		if (input.size() <= 3) //Só são aceites IDs com, no máximo 3 dígitos
		{
			if (isNumber(input)) //Se o input for um número positivo
			{
				verify = company.searchDriverIdentifier(stoi(input)); //Verifica a existência do ID

				if (verify != -1)
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

	company.removeDriver(verify);

	cout << "Condutor apagado com sucesso!" << endl;
}

/*
Altera o número de horas de um turno de um condutor.
*/
void changeShift(Company &company, unsigned int id)
{
	int index;
	unsigned int newShift;
	string input;
	bool validInput = false;

	index = company.searchDriverIdentifier(id);

	cout << "Alterar turno" << endl;

	cout << endl << "O número atual de horas de um turno é: " << company.getDrivers()[index].getShiftMaxDuration() << endl;

	while (!validInput)
	{
		cout << "Novo número de horas: ";
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
			cout << "Input inválido! Tente novamente..." << endl;
	}

	vector<Driver> newDrivers = company.getDrivers();
	newDrivers[index].setShiftMaxDuration(newShift);
	company.setDrivers(newDrivers);

	cout << "Alteração efetuada com sucesso!" << endl;
}

/*
Altera o número máximo de horas de trabalho por semana de um condutor.
*/
void changeMaxHours(Company &company, unsigned int id)
{
	int index;
	string input;
	unsigned int newMaxHours;
	bool validInput = false;

	index = company.searchDriverIdentifier(id);

	cout << "Alterar número máximo de horas de trabalho" << endl;

	cout << endl << "O número máximo atual de horas de trabalho é: " << company.getDrivers()[index].getMaxWeekWorkingTime() << " por semana" << endl;

	while (!validInput)
	{
		cout << "Novo número de horas: ";
		getline(cin, input);

		if (isNumber(input))
		{
			newMaxHours = stoi(input);

			if (newMaxHours <= company.getDrivers()[index].getShiftMaxDuration())
				cout << "Não é possível atribuir esse número! Deve inserir mais horas." << endl;
			else
				validInput = true;
		}
		else
			cout << "Input inválido! Tente novamente..." << endl;
		}


	vector<Driver> newDrivers = company.getDrivers();
	newDrivers[index].setMaxWeekWorkingTime(newMaxHours);
	company.setDrivers(newDrivers);

	cout << "Alteração efetuada com sucesso!" << endl;
}

/*
Altera o número mínimo de horas de descanso entre turnos de um condutor.
*/
void changeMinRest(Company &company, unsigned int id)
{
	int index;
	unsigned int newMinRest;
	string input;
	bool validInput = false;

	index = company.searchDriverIdentifier(id);

	cout << "Alterar horas de descanso entre turnos" << endl;

	cout << endl << "O número mínimo atual de horas de descanso entre turnos é: " << company.getDrivers()[index].getMinRestTime() << endl;

	while (!validInput)
	{
		cout << "Novo número de horas: ";
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
			cout << "Input inválido! Tente novamente..." << endl;
	}

	vector<Driver> newDrivers=company.getDrivers();
	newDrivers[index].setMinRestTime(newMinRest);
	company.setDrivers(newDrivers);

	cout << "Alteração efetuada com sucesso!" << endl;
}

/*
Altera o nome de um condutor. Pode ser útil, por exemplo, na eventualidade de um condutor ser substituído
e o número identificador de manter.
*/
void changeName(Company &company, unsigned int id)
{
	int index;
	string newName;
	bool validInput = false;

	index = company.searchDriverIdentifier(id);

	cout << "Alterar nome" << endl;

	cout << endl << "O nome do condutor atual é: " << company.getDrivers()[index].getName() << endl;

	while (!validInput)
	{
		cout << "Novo nome: ";
		getline(cin, newName);

		if (newName == "")
			cout << "Input inválido! Tente novamente..." << endl << endl;
		else
			validInput = true;
	}

	vector<Driver> newDrivers=company.getDrivers();
	newDrivers[index].setName(newName);
	company.setDrivers(newDrivers);

	cout << "As alterações foram efetuadas com sucesso!" << endl;
}

/*
Apresenta informação relativa ao trabalho atribuído a um condutor especificado pelo utilizador, que é traduzida nos
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

		if (input.size() <= 3) //Só são aceites IDs com, no máximo 3 dígitos
		{

			if (isNumber(input)) //Se o input for um número positivo
			{
				verify = company.searchDriverIdentifier(stoi(input)); //Verifica a existência do ID

				if (verify != -1)
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

	if (company.getDrivers()[verify].getShifts().size() == 0)
		cout << "De momento, o condutor não tem qualquer trabalho atribuído." << endl;
	else
		for (int i = 0; i < company.getDrivers()[verify].getShifts().size(); i++)
		{
			cout << "Turno " << i + 1 << endl;
			company.getDrivers()[verify].getShifts()[i].showInfo();
			cout << endl;
		}
}