#include "myTypes.h"

/*
Interface principal entre o programa e o utilizador. Apresenta no ecr� as funcionalidades principais, recebe
a escolha do utilizador e devolve-a ao programa.
*/
void mainUserInterface()
{
	int userChoice;

	cout << "Sistema de gest�o de informa��o - SEMPRARROLAR" << endl;
	cout << "Funcionalidades dispon�veis" << endl << endl;
	cout << "1 - Gest�o de condutores" << endl;
	cout << "2 - Visualizar informa��o" << endl;
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
Sub-interface dedicada � gest�o de condutores. Apresenta as funcionalidades dispon�veis, recebe a escolha
do utilizador e inicializa a fun��o pedida
*/
void driversInterface()
{
	int userChoice;

	cout << "Gest�o de condutores" << endl;
	cout << "Funcionalidades dispon�veis" << endl << endl;
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
Sub-interface dedicada � visualizacao de informacao. Apresenta as funcionalidades dispon�veis, recebe a escolha
do utilizador e inicializa a fun��o pedida
*/
void infoInterface()
{
	int userChoice;

	cout << "Visualiza�ao de informacao" << endl;
	cout << "Funcionalidades dispon�veis" << endl << endl;
	cout << "1 - Hor�rio de uma paragem" << endl;
	cout << "2 - Hor�rio de uma linha " << endl;
	cout << "3 - Informa��o de um autocarro" << endl;
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
Sub-interface dedicada � pesquisa de informa��o. Apresenta as funcionalidades dispon�veis, recebe a escolha
do utilizador e inicializa a fun��o pedida
*/
void searchInterface()
{
	int userChoice;

	cout << "Pesquisa" << endl;
	cout << "Funcionalidades dispon�veis" << endl << endl;
	cout << "1 - Procurar paragem" << endl;
	cout << "2 - Condutores dispon�veis" << endl;
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
Pergunta ao utilizador se pretente efetuar outra opera��o ou terminar o programa.
Tamb�m assegura que este insere um valor v�lido.
*/
void quitOrContinue()
{
	string userChoice;
	bool validInput = false;

	while (!validInput)
	{
		cout << "Deseja efetuar outra opera��o? (S/N) : ";
		getline(cin, userChoice);

		if (userChoice == "S" || userChoice == "N" || userChoice == "s" || userChoice == "n")
			validInput = true;
		cout << "Op��o inv�lida, tente novamente..." << endl << endl;
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
Fun��o simples para limpar o ecr�.
*/
void clearScreen()
{
    cout << string(100,'\n');
}