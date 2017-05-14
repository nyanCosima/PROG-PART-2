#include "Company.h"
#include <iostream>
#include "myTypes.h"

int verifyInput(int low, int high);
void savingChanges(Company company);
void createDriver(Company &company);
void editDriver(Company &company);
void removeDriver(Company &company);
void showShifts(Company company);
void lineSchedule(Company company);
void stopSchedule(Company company);
void searchStop(Company company);
void routeCalculator(Company company);
void clearScreen();
void mainUserInterface(Company &company);
void driversInterface(Company &company);
void infoInterface(Company &company);
void searchInterface(Company &company);
void allocateService(Company &company);
bool quitOrContinue(Company &company);


/*
Interface principal entre o programa e o utilizador. Apresenta no ecrã as funcionalidades principais, recebe
a escolha do utilizador e devolve-a ao programa.
*/
void mainUserInterface(Company &company)
{
	bool anotherOp = true;

	while (anotherOp)
	{
		int userChoice;

		cout << "Sistema de gestão de informação - SEMPRARROLAR" << endl;
		cout << "Funcionalidades disponíveis" << endl << endl;
		cout << "1 - Gestão de condutores" << endl;
		cout << "2 - Visualizar informação" << endl;
		cout << "3 - Pesquisa" << endl;
		cout << "0 - Sair" << endl << endl;

		userChoice = verifyInput(0, 3);

		clearScreen(); //Limpa a consola para melhorar o aspeto e simplicidade do programa

		if (userChoice == 1)
			driversInterface(company);
		else if (userChoice == 2)
			infoInterface(company);
		else if (userChoice == 3)
			searchInterface(company);
		else if (userChoice == 0)
		{
			savingChanges(company);
			cout << "Programa terminado! Pressione ENTER para fechar." << endl;
			exit(1);
		}

	}
}

/*
Sub-interface dedicada à gestão de condutores. Apresenta as funcionalidades disponíveis, recebe a escolha
do utilizador e inicializa a função pedida
*/
void driversInterface(Company &company)
{
	bool anotherOp = true;

	while (anotherOp)
	{

		int userChoice;

		cout << "Gestão de condutores" << endl;
		cout << "Funcionalidades disponíveis" << endl << endl;
		cout << "1 - Criar condutor" << endl;
		cout << "2 - Alterar condutor" << endl;
		cout << "3 - Remover condutor" << endl;
		cout << "4 - Atribuir serviço" << endl;
		cout << "0 - Voltar" << endl << endl;

		userChoice = verifyInput(0, 4);

		clearScreen();

		switch (userChoice)
		{
		case 1: createDriver(company);
			anotherOp = quitOrContinue(company);
			break;
		case 2: editDriver(company);
			break;
		case 3: removeDriver(company);
			anotherOp = quitOrContinue(company);
			break;
		case 4: allocateService(company);
			anotherOp = quitOrContinue(company);
			break;
		case 0: return;
			break;
		}

	}
}

/*
Sub-interface dedicada à visualizacao de informacao. Apresenta as funcionalidades disponíveis, recebe a escolha
do utilizador e inicializa a função pedida
*/
void infoInterface(Company &company)
{
	bool anotherOp = true;

	while (anotherOp)
	{

		int userChoice;

		cout << "Visualizaçao de informacao" << endl;
		cout << "Funcionalidades disponíveis" << endl << endl;
		cout << "1 - Horário de uma paragem" << endl;
		cout << "2 - Horário de uma linha " << endl;
		cout << "3 - Informação de um autocarro" << endl;
		cout << "4 - Trabalho de um condutor" << endl;
        cout << "5 - Verificar períodos de condutores sem o serviço completo atribuído" << endl;
		cout << "0 - Voltar" << endl << endl;

		userChoice = verifyInput(0, 5);

		clearScreen();

		switch (userChoice)
		{
		case 1: stopSchedule(company);
			anotherOp = quitOrContinue(company);
			break;
		case 2: lineSchedule(company);
			anotherOp = quitOrContinue(company);
			break;
		case 3: //busInfo();
			anotherOp = quitOrContinue(company);
			break;
		case 4: showShifts(company);
			anotherOp = quitOrContinue(company);
			break;
        case 5:
            //do stuff
            anotherOp = quitOrContinue(company);
            break;
		case 0: return;
			break;
		}

	}
}

/*
Sub-interface dedicada à pesquisa de informação. Apresenta as funcionalidades disponíveis, recebe a escolha
do utilizador e inicializa a função pedida
*/
void searchInterface(Company &company)
{
	bool anotherOp = true;

	while (anotherOp)
	{

		int userChoice;

		cout << "Pesquisa" << endl;
		cout << "Funcionalidades disponíveis" << endl << endl;
		cout << "1 - Procurar paragem" << endl;
		cout << "2 - Condutores disponíveis" << endl;
		cout << "3 - Percurso entre paragens" << endl;
		cout << "0 - Voltar" << endl << endl;

		userChoice = verifyInput(0, 3);

		clearScreen();

		switch (userChoice)
		{
		case 1: searchStop(company);
			anotherOp = quitOrContinue(company);
			break;
		case 2: //availableDrivers();
			anotherOp = quitOrContinue(company);
			break;
		case 3: routeCalculator(company);
			anotherOp = quitOrContinue(company);
			break;
		case 0: return;
			break;
		}

	}
}

/*
Pergunta ao utilizador se pretente efetuar outra operação ou terminar o programa.
Também assegura que este insere um valor válido.
*/
bool quitOrContinue(Company &company)
{
	string userChoice;
	bool validInput = false;

	while (!validInput)
	{
		cout << "Deseja efetuar outra operação? (S/N) : ";
		getline(cin, userChoice);

		if (userChoice == "S" || userChoice == "N" || userChoice == "s" || userChoice == "n")
			validInput = true;
		else cout << "Opção inválida, tente novamente..." << endl << endl;
	}

	if (userChoice == "S" || userChoice == "s")
	{
		clearScreen();
		return false;
	}
	else
	{
		savingChanges(company);
		cout << endl << "Programa terminado! Pressione ENTER para fechar." << endl << endl;
		exit(1);
	}
}


/*
Função simples para limpar o ecrã.
*/
void clearScreen()
{
    cout << string(100,'\n');
}