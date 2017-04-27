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
	cout << "1 - Gest�o de linhas" << endl;
	cout << "2 - Gest�o de condutores" << endl;
	cout << "3 - Visualiza��o de hor�rios" << endl;
	cout << "4 - Pesquisa" << endl;
	cout << "5 - Sair" << endl << endl;

	userChoice = verifyInput(1, 5);

	clearScreen(); //Limpa a consola para melhorar o aspeto e simplicidade do programa

	if (userChoice == 1)
		linesInterface();
	else if (userChoice == 2)
		driversInterface();
	else if (userChoice == 3)
		schedulesInterface();
	else if (userChoice == 4)
		searchInterface();
	else if (userChoice == 5)
	{
		savingChanges();
		cout << "Programa terminado! Pressione ENTER para fechar." << endl;
		exit(1);
	}
}

/*
Sub-interface dedicada � gest�o de linhas. Apresenta as funcionalidades dispon�veis, recebe a escolha
do utilizador e inicializa a fun��o pedida
*/
void linesInterface()
{
	int userChoice;

	cout << "Gest�o de linhas" << endl;
	cout << "Funcionalidades dispon�veis" << endl << endl;
	cout << "1 - Criar linha" << endl;
	cout << "2 - Alterar linha" << endl;
	cout << "3 - Remover linha" << endl;
	cout << "4 - Voltar" << endl << endl;

	userChoice = verifyInput(1, 4);

	clearScreen();

	switch (userChoice)
	{
	case 1: createLine();
		quitOrContinue();
		break;
	case 2: editLine();
		quitOrContinue();
		break;
	case 3: removeLine();
		quitOrContinue();
		break;
	case 4: mainUserInterface();
		break;
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
	cout << "5 - Voltar" << endl << endl;

	userChoice = verifyInput(1, 5);

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
	case 5: mainUserInterface();
		break;
	}
}

/*
Sub-interface dedicada � gest�o de hor�rios. Apresenta as funcionalidades dispon�veis, recebe a escolha
do utilizador e inicializa a fun��o pedida
*/
void schedulesInterface()
{
	int userChoice;

	cout << "Gest�o de horarios" << endl;
	cout << "Funcionalidades dispon�veis" << endl << endl;
	cout << "1 - Hor�rio de uma paragem" << endl;
	cout << "2 - Hor�rio de uma linha " << endl;
	cout << "3 - Voltar" << endl << endl;

	userChoice = verifyInput(1, 3);

	clearScreen();

	switch (userChoice)
	{
	case 1:// stopSchedule(linesData);
		quitOrContinue();
		break;
	case 2:// lineSchedule(linesData);
		quitOrContinue();
		break;
	case 3: mainUserInterface();
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
	cout << "4 - Voltar" << endl << endl;

	userChoice = verifyInput(1, 4);

	clearScreen();

	switch (userChoice)
	{
	case 1: searchStop();
		quitOrContinue();
		break;
	case 2:// availableDrivers(driversData);
		quitOrContinue();
		break;
	case 3:// routeCalculator(linesData);
		quitOrContinue();
		break;
	case 4: mainUserInterface();
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
		if (cin >> userChoice && (userChoice == "S" || userChoice == "N" || userChoice == "s" || userChoice == "n"))
			validInput = true;
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Op��o inv�lida, tente novamente..." << endl << endl;
		}
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
	for (int i = 0; i < 50; i++)
		cout << '\n';
}