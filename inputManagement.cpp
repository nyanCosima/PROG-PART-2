#include "myTypes.h"

/*
Função encarregada de verificar se o input do utilizador é válido. Em caso positivo, retorna o valor introduzido à função.
Em caso negativo, avisa o utilizador que introduziu uma opção inválida e funciona até que o valor seja válido.
Desenvolvido para as interfaces.
*/
int verifyInput(int low, int high)
{
	int inputValue;
	bool validInput = false;

	while (!validInput)
	{
		cout << "Escolha uma opção (" << low << "-" << high << "): ";

		//Apenas aceita como input números entre o limite inferior e superior (inclusive)
		if (cin >> inputValue && low <= inputValue && high >= inputValue)
		{
			validInput = true;
			cin.ignore(1000, '\n');
		}
		//Qualquer outro input é recusado, e é novamente pedido ao utilizador que introduza um número.
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Opção inválida, tente novamente..." << endl << endl;
		}
	}

	return inputValue;
}