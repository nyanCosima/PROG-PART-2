#include "myTypes.h"

/*
Função encarregada de verificar se o input do utilizador é válido. Em caso positivo, retorna o valor introduzido à função.
Em caso negativo, avisa o utilizador que introduziu uma opção inválida e funciona até que o valor seja válido.
Desenvolvido para as interfaces.
*/
int verifyInput(int low, int high)
{
	int inputValue;
	string input;
	bool validInput = false;

	while (!validInput)
	{
		cout << "Escolha uma opção (" << low << "-" << high << "): ";

		getline(cin, input);

		if (isdigit(input[0]))
		{
			//Apenas aceita como input números entre o limite inferior e superior (inclusive)
			if (stoi(input) >= low && stoi(input) <= high &&input.size()<2)
				validInput = true;
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}
		//Qualquer outro input é recusado, e é novamente pedido ao utilizador que introduza um número.
		else
			cout << "Input inválido! Tente novamente..." << endl;
	}

	inputValue = stoi(input);

	return inputValue;
}


/*
Verifica se o input do utilizador é um número positivo.
*/
bool isNumber(string input)
{
	bool isNumber;

	if (input == "")
		return false;
	else
	{
		for (int i = 0; i < input.size(); i++)
			if (isdigit(input[i]))
				isNumber = true;
			else
			{
				isNumber = false;
				break;
			}
	}
	return isNumber;

}