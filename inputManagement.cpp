#include "myTypes.h"

/*
Fun��o encarregada de verificar se o input do utilizador � v�lido. Em caso positivo, retorna o valor introduzido � fun��o.
Em caso negativo, avisa o utilizador que introduziu uma op��o inv�lida e funciona at� que o valor seja v�lido.
Desenvolvido para as interfaces.
*/
int verifyInput(int low, int high)
{
	int inputValue;
	string input;
	bool validInput = false;

	while (!validInput)
	{
		cout << "Escolha uma op��o (" << low << "-" << high << "): ";

		getline(cin, input);

		if (isdigit(input[0]))
		{
			//Apenas aceita como input n�meros entre o limite inferior e superior (inclusive)
			if (stoi(input) >= low && stoi(input) <= high &&input.size()<2)
				validInput = true;
			else
				cout << "Input inv�lido! Tente novamente..." << endl;
		}
		//Qualquer outro input � recusado, e � novamente pedido ao utilizador que introduza um n�mero.
		else
			cout << "Input inv�lido! Tente novamente..." << endl;
	}

	inputValue = stoi(input);

	return inputValue;
}


/*
Verifica se o input do utilizador � um n�mero positivo.
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