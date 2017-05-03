#include "myTypes.h"

/*
Interface principal entre o programa e o utilizador. Apresenta no ecrã as funcionalidades principais, recebe
a escolha do utilizador e devolve-a ao programa.
*/
void mainUserInterface()
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
		driversInterface();
	else if (userChoice == 2)
		infoInterface();
	else if (userChoice == 3)
		searchInterface();
	else if (userChoice == 0)
	{
		savingChanges();
		cout << "Programa terminado! Pressione ENTER para fechar." << endl;
		exit(1);
	}
}


/*
Sub-interface dedicada à gestão de condutores. Apresenta as funcionalidades disponíveis, recebe a escolha
do utilizador e inicializa a função pedida
*/
void driversInterface()
{
	int userChoice;

	cout << "Gestão de condutores" << endl;
	cout << "Funcionalidades disponíveis" << endl << endl;
	cout << "1 - Criar condutor" << endl;
	cout << "2 - Alterar condutor" << endl;
	cout << "3 - Remover condutor" << endl;
	cout << "4 - Estado do condutor" << endl;
	cout << "0 - Voltar" << endl << endl;

	userChoice = verifyInput(0, 4);

	clearScreen();

	switch (userChoice)
	{
	case 1: createDriver();
		quitOrContinue();
		break;
	case 2: editDriver();
		quitOrContinue();
		break;
	case 3: removeDriver();
		quitOrContinue();
		break;
	case 4: cout << "calmex" << endl;
		quitOrContinue();
		break;
	case 0: mainUserInterface();
		break;
	}
}

/*
Sub-interface dedicada à visualizacao de informacao. Apresenta as funcionalidades disponíveis, recebe a escolha
do utilizador e inicializa a função pedida
*/
void infoInterface()
{
	int userChoice;

	cout << "Visualizaçao de informacao" << endl;
	cout << "Funcionalidades disponíveis" << endl << endl;
	cout << "1 - Horário de uma paragem" << endl;
	cout << "2 - Horário de uma linha " << endl;
	cout << "3 - Informação de um autocarro" << endl;
	cout << "4 - Trabalho de um condutor" << endl;
	cout << "0 - Voltar" << endl << endl;

	userChoice = verifyInput(0, 4);

	clearScreen();

	switch (userChoice)
	{
	case 1:// stopSchedule(linesData);
		quitOrContinue();
		break;
	case 2: lineSchedule();
		quitOrContinue();
		break;
		case 3: //busInfo();
			quitOrContinue;
			break;
		case 4: showShifts();
			quitOrContinue;
			break;
	case 0: mainUserInterface();
		break;
	}
}

/*
Sub-interface dedicada à pesquisa de informação. Apresenta as funcionalidades disponíveis, recebe a escolha
do utilizador e inicializa a função pedida
*/
void searchInterface()
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
	case 1: searchStop();
		quitOrContinue();
		break;
	case 2: //availableDrivers();
		quitOrContinue();
		break;
	case 3:routeCalculator();
		quitOrContinue();
		break;
	case 0: mainUserInterface();
		break;
	}
}

/*
Pergunta ao utilizador se pretente efetuar outra operação ou terminar o programa.
Também assegura que este insere um valor válido.
*/
void quitOrContinue()
{
	string userChoice;
	bool validInput = false;

	while (!validInput)
	{
		cout << "Deseja efetuar outra operação? (S/N) : ";
		getline(cin, userChoice);

		if (userChoice == "S" || userChoice == "N" || userChoice == "s" || userChoice == "n")
			validInput = true;
		cout << "Opção inválida, tente novamente..." << endl << endl;
	}

	if (userChoice == "S" || userChoice == "s")
	{
		clearScreen();
		mainUserInterface();
	}
	else
	{
		savingChanges();
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