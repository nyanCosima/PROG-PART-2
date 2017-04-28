#include "myTypes.h"

/*
Recebe os parâmetros do utilizador (ID da linha, frequência de circulação, paragens e durações) e guarda-os numa nova
Line, que é adicionada ao vetor criado anteriormente.
*/
void createLine()
{
	unsigned int id, frequency;
	int verify = -1;
	int i = 1;
	int j = 0;
	bool validInput = false;
	string input;
	string stop;
	vector<string> stops;
	vector<int> times;

	cout << "Criar linha" << endl << endl;

	//Receber o ID do utilizador

	while (!validInput)
	{
		cout << "Identificador da linha: ";
		getline(cin, input);

		if (input.size() <= 3) //Só são aceites IDs com, no máximo 3 dígitos
		{

			if(isNumber(input)) //Se o input for um número positivo
			{
				verify = searchLineIdentifier(stoi(input)); //Verifica a existência do ID

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

	//Recebe a frequência do utilizador

	validInput = false;
	while (!validInput)
	{
		cout << "Frequência: ";
		/*
		if (cin >> frequencyN && frequencyN>0)
		{
			validInput = true;
			cin.ignore(1000, '\n');
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Input inválido! Tente novamente..." << endl << endl;
		}
		*/

		getline(cin,input);

		if (isNumber(input))
		{
			if (stoi(input) > 0 && stoi(input) < 5 * 60)
				validInput = true;
			else
				cout << "Ajuste o valor inserido. Tente novamente..." << endl;
		}
		else
			cout << "Input inválido! Tente novamente..." << endl;
	}

	frequency = stoi(input);


	/*
	Recebe as paragens do utilizador. Deteta o fim do input e também assegura que o input é válido, na medida
	em que não permite input vazio
	*/

	while (!cin.eof())
	{
		validInput = false;

		while (!validInput)
		{
			cout << "Paragem " << i << " (CTRL-Z para terminar): ";
			getline(cin, stop);

			if (cin.eof() && i <= 2)
			{
				cout << "Por favor, insira mais paragens." << endl;
				cin.clear();
			}
			else if (cin.eof())
				break;
			else if (stop == "") //Não aceita input vazio.
				cout << "Input inválido! Tente novamente..." << endl << endl;
			else
				validInput = true;
		}

		if (cin.eof())
		{
			cin.clear();
			break;
		}

		stops.push_back(stop);
		i++;
	}

	//Recebe as durações do utilizador

	int numberOfIterations = stops.size() - 1;

	while (j < numberOfIterations)
	{
		int d;

		validInput = false;

		while (!validInput)
		{
			cout << "Duração " << (j + 1) << ": ";

			getline(cin, input);

			if (isNumber(input))
			{
				if (stoi(input) > 0 && stoi(input) <= 5 * 60)
					validInput = true;
				else
					cout << "Ajuste o valor inserido. Tente novamente..." << endl;
			}
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}

		d = stoi(input);
		times.push_back(d);

		j++;
	}

	Line newLine(id, frequency, stops, times); //Invoca o construtor para criar a linha
	linesData.push_back(newLine); //Coloca a nova linha no vetor das linhas

	cout << "Linha adicionada com sucesso!" << endl;
}

/*
Edita as linhas já criadas. Fornece meios para: alterar a frequência de circulaçao, adicionar paragem, remover paragem,
alterar paragem, alterar durações.
*/
void editLine()
{
	int userChoice;
	unsigned int id;
	string input;
	int verify = -1;
	bool validInput = false;

	cout << "Alterar linha" << endl << endl;

	while (!validInput)
	{
		cout << "Identificador da linha: ";
		getline(cin, input);

		if (input.size() <= 3) //Só são aceites IDs com, no máximo 3 dígitos
		{

			if (isNumber(input)) //Se o input for um número positivo
			{
				verify = searchLineIdentifier(stoi(input)); //Verifica a existência do ID

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

	//Apresenta uma interface com as funções disponíveis para alterar uma linha

	cout << endl << "Escolha o que pretende alterar" << endl;
	cout << "1 - Alterar frequência" << endl;
	cout << "2 - Adicionar paragem" << endl;
	cout << "3 - Alterar paragem" << endl;
	cout << "4 - Remover paragem" << endl;
	cout << "5 - Alterar duração" << endl;
	cout << "6 - Voltar" << endl << endl;

	userChoice = verifyInput(1, 6);

	clearScreen();

	if (userChoice == 1)
		changeFrequency(id);
	else if (userChoice == 2)
		addStop(id);
	else if (userChoice == 3)
		changeStop(id);
	else if (userChoice == 4)
		removeStop(id);
	else if (userChoice == 5)
		changeDuration(id);
	else if (userChoice == 6)
		linesInterface();
}


/*
Recebe do utilizador um identificador para uma linha, e caso ela exista remove-a do vetor de Lines.
*/
void removeLine()
{
	int verify = -1;
	bool validInput = false;
	string input;

	cout << "Remover linha" << endl << endl;

	while (!validInput)
	{
		cout << "Identificador da linha: ";
		getline(cin, input);

		if (input.size() <= 3) //Só são aceites IDs com, no máximo 3 dígitos
		{

			if (isNumber(input)) //Se o input for um número positivo
			{
				verify = searchLineIdentifier(stoi(input)); //Verifica a existência do ID

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

	linesData.erase(linesData.begin() + verify);

	cout << "Linha apagada com sucesso!" << endl;
}

/*
Muda a frequência de circulação numa linha dada pelo utilizador.
*/
void changeFrequency(unsigned int id)
{
	int index;
	unsigned int newfreq;
	string input;
	index = searchLineIdentifier(id);
	bool validInput = false;

	cout << "Alterar frequência" << endl;

	cout << endl << "A frequência atual é: " << linesData[index].getFrequency() << endl;


	while (!validInput)
	{
		cout << "Nova frequência: ";
		getline(cin, input);

		if (isNumber(input))
		{
			if (stoi(input) > 0 && stoi(input) < 5 * 60)
				validInput = true;
			else
				cout << "Ajuste o valor inserido. Tente novamente..." << endl;
		}
		else
			cout << "Input inválido! Tente novamente..." << endl;

	}

	newfreq = stoi(input);

	linesData[index].setFrequency(newfreq);

	cout << "Alterações efetuadas com sucesso!" << endl;
}

/*
Remove uma paragem numa linha dada pelo utilizador, assegurando que é corrigida a duração.
Para isso, pergunta ao utilizador qual a duração entre as duas paragens adjacentes à paragem removida.
*/
void removeStop(unsigned int id)
{
	int index;
	string stop;
	int stopIndex = -1;
	bool validInput = false;

	index = searchLineIdentifier(id);

	vector<string> newBusList = linesData[index].getBusStops();
	vector<int> newTimings = linesData[index].getTimings();

	cout << "Remover paragem" << endl;

	cout << endl << "Atualmente, a linha tem as seguintes paragens: ";
	for (int i = 0; i < newBusList.size(); i++)
	{
		if (i > 0)
			cout << " - ";
		cout << newBusList[i];
	}

	//Procura o indice da paragem e remove-a do vetor de strings da sua respetiva Line

	while (!validInput)
	{
		cout << endl << "Paragem a remover: ";
		getline(cin, stop);

		for (int i = 0; i < newBusList.size(); i++)
			if (newBusList[i] == stop)
				stopIndex = i;

		if (stopIndex > -1)
			validInput = true;
		else
			cout << "A paragem especificada não existe! Tente novamente..." << endl;
	}

	newBusList.erase(newBusList.begin() + stopIndex);
	linesData[index].setBusStops(newBusList);

	//Corrige as durações

	if (stopIndex == 0)
	{
		newTimings.erase(newTimings.begin() + stopIndex);
		linesData[index].setTimings(newTimings);
		cout << "Paragem removida com sucesso!" << endl;
	}
	else if (stopIndex == newBusList.size()-1)
	{
		newTimings.erase(newTimings.begin() + stopIndex - 1);
		linesData[index].setTimings(newTimings);
		cout << "Paragem removida com sucesso!" << endl;
	}
	else
	{
		int indexStop1, indexStop2, newDuration;
		string input;

		indexStop1 = stopIndex - 1;
		indexStop2 = stopIndex;

		validInput = false;
		while (!validInput)
		{
			cout << "Duração entre " << newBusList[indexStop1] << " e " << newBusList[indexStop2] << ": ";

			if (isNumber(input))
			{
				if (stoi(input) > 0 && stoi(input) <= 5 * 60)
					validInput = true;
				else
					cout << "Ajuste o valor inserido. Tente novamente..." << endl;
			}
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}

		newDuration = stoi(input);

		newTimings.erase(newTimings.begin() + indexStop1);
		newTimings[indexStop1] = newDuration;

		linesData[index].setTimings(newTimings);

		cout << "Paragem removida com sucesso!" << endl;
	}
}

/*
Adiciona uma paragem a uma linha indicada pelo utilizador, assegurando que as durações são corrigidas.
*/
void addStop(unsigned int id)
{
	int index, stopIndex;
	string stop, input;
	bool validInput = false;

	index = searchLineIdentifier(id);

	vector<string> newBusList=linesData[index].getBusStops();
	vector<int> newTimings = linesData[index].getTimings();

	cout << "Adicionar paragem" << endl;

	cout << endl << "Atualmente, a linha tem as seguintes paragens: ";
	for (int i = 0; i < newBusList.size(); i++)
	{
		if (i > 0)
			cout << " - ";
		cout << newBusList[i];
	}

	while (!validInput)
	{
		cout << endl << "Paragem a adicionar: ";
		getline(cin, stop);

		if (stop == "")
			cout << "Input inválido! Tente novamente..." << endl;
		else if (searchStop3(index, stop))
			cout << "A paragem já se encontra na linha! Tente novamente..." << endl;
		else
			validInput = true;
	}

	validInput = false;

	while (!validInput)
	{
		cout << "Índice (a começar em 0): ";
		getline(cin, input);

		if (isNumber(input))
		{
			stopIndex = stoi(input);

			if (stopIndex >= 0 && stopIndex <= linesData[index].getBusStops().size())
				validInput = true;
			else
				cout << "Esse índice não existe! Tente novamente..." << endl;
		}
		else
			cout << "Input inválido! Tente novamente..." << endl;
	}

	newBusList.insert(newBusList.begin() + stopIndex, stop);
	linesData[index].setBusStops(newBusList);

	//Corrigir durações

	if (stopIndex == 0)
	{
		int duration;

		validInput = false;

		while (!validInput)
		{
			cout << "Duração entre " << stop << " e " << newBusList[stopIndex + 1] << ": ";
			getline(cin, input);

			if (isNumber(input))
			{
				duration = stoi(input);

				if (duration > 0 && duration <= 5 * 60)
					validInput = true;
				else
					cout << "Ajuste o valor inserido. Tente novamente..." << endl;
			}
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}

		newTimings.insert(newTimings.begin(), duration);
		linesData[index].setTimings(newTimings);
	}
	else if (stopIndex == (newBusList.size() - 1))
	{
		int duration;

		validInput = false;
		while (!validInput)
		{
			cout << "Duração entre " << newBusList[stopIndex - 1] << " e " << stop << ": ";
			getline(cin, input);

			if (isNumber(input))
			{
				duration = stoi(input);

				if (duration > 0 && duration <= 5 * 60)
					validInput = true;
				else
					cout << "Ajuste o valor inserido. Tente novamente..." << endl;
			}
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}

		newTimings.insert(newTimings.begin() + stopIndex - 1, duration);
		linesData[index].setTimings(newTimings);
	}
	else
	{
		int duration1, duration2;

		validInput = false;
		while (!validInput)
		{
			cout << "Duração entre " << newBusList[stopIndex - 1] << " e " << stop << ": ";
			getline(cin, input);

			if (isNumber(input))
			{
				duration1 = stoi(input);

				if (duration1 > 0 && duration1 <= 5 * 60)
					validInput = true;
				else
					cout << "Ajuste o valor inserido. Tente novamente..." << endl;
			}
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}

		validInput = false;
		while (!validInput)
		{
			cout << "Duração entre " << stop << " e " << newBusList[stopIndex + 1] << ": ";
			getline(cin, input);

			if (isNumber(input))
			{
				duration2 = stoi(input);

				if (duration2 > 0 && duration2 <= 5 * 60)
					validInput = true;
				else
					cout << "Ajuste o valor inserido. Tente novamente..." << endl;
			}
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}

		newTimings[stopIndex - 1] = duration1;
		newTimings.insert(newTimings.begin() + stopIndex, duration2);

		linesData[index].setTimings(newTimings);

	}

	cout << "Paragem adicionada com sucesso!" << endl;

}

/*
Altera uma paragem numa linha dada pelo utilizador, assegurando que as durações são corrigidas.
*/
void changeStop(unsigned int id)
{
	string stop, newStop, input;
	int index, stopIndex = -1;
	bool validInput = false;

	index = searchLineIdentifier(id);

	vector<string> newBusList = linesData[index].getBusStops();
	vector<int> newTimings = linesData[index].getTimings();

	cout << "Alterar paragem" << endl;

	cout << endl << "Atualmente, a linha tem as seguintes paragens: ";
	for (int i = 0; i < newBusList.size(); i++)
	{
		if (i > 0)
			cout << " - ";
		cout << newBusList[i];
	}

	while (!validInput)
	{
		cout << endl << "Paragem a alterar: ";
		getline(cin, stop);

		for (int i = 0; i < newBusList.size(); i++)
			if (newBusList[i] == stop)
				stopIndex = i;

		if (stopIndex != -1)
			validInput = true;
		else
			cout << "A paragem especificada não existe! Tente novamente..." << endl;
	}

	validInput = false;
	while (!validInput)
	{
		cout << "Nova paragem: ";
		getline(cin, newStop);

		if (stop == "")
			cout << "Input inválido! Tente novamente..." << endl << endl;
		else
			validInput = true;
	}

	newBusList[stopIndex] = newStop;
	linesData[index].setBusStops(newBusList);

	//Corrigir as durações

	if (stopIndex == 0)
	{
		int duration;

		validInput = false;

		while (!validInput)
		{
			cout << "Duração entre " << newStop << " e " << newBusList[stopIndex + 1] << ": ";
			getline(cin, input);

			if (isNumber(input))
			{
				duration = stoi(input);

				if (duration > 0 && duration <= 5 * 60)
					validInput = true;
				else
					cout << "Ajuste o valor inserido. Tente novamente..." << endl;
			}
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}

		newTimings[stopIndex] = duration;
		linesData[index].setTimings(newTimings);
	}
	else if (stopIndex == newBusList.size() - 1)
	{
		int duration;

		validInput = false;
		while (!validInput)
		{
			cout << "Duração entre " << newBusList[stopIndex - 1] << " e " << newStop << ": ";
			getline(cin, input);

			if (isNumber(input))
			{
				duration = stoi(input);

				if (duration > 0 && duration <= 5 * 60)
					validInput = true;
				else
					cout << "Ajuste o valor inserido. Tente novamente..." << endl;
			}
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}

		newTimings[stopIndex - 1] = duration;
		linesData[index].setTimings(newTimings);
	}
	else
	{
		int duration1, duration2;

		validInput = false;
		while (!validInput)
		{
			cout << "Duração entre " << newBusList[stopIndex - 1] << " e " << newStop << ": ";

			getline(cin, input);

			if (isNumber(input))
			{
				duration1 = stoi(input);

				if (duration1 > 0 && duration1 <= 5 * 60)
					validInput = true;
				else
					cout << "Ajuste o valor inserido. Tente novamente..." << endl;
			}
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}

		validInput = false;
		while (!validInput)
		{
			cout << "Duração entre " << newStop << " e " << newBusList[stopIndex + 1] << ": ";

			getline(cin, input);

			if (isNumber(input))
			{
				duration2 = stoi(input);

				if (duration2 > 0 && duration2 <= 5 * 60)
					validInput = true;
				else
					cout << "Ajuste o valor inserido. Tente novamente..." << endl;
			}
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}

		newTimings[stopIndex - 1] = duration1;
		newTimings[stopIndex] = duration2;

		linesData[index].setTimings(newTimings);
	}

	cout << "Paragem alterada com sucesso!" << endl;
}

/*
Altera a duração de um percurso especificado pelo utilizador. É útil para casos em que, por exemplo, um dos percursos se
encontre em obras e seja necessário efetuar uma alteração.
*/
void changeDuration(unsigned int id)
{
	bool validInput = false;
	int index, index1 = -1, index2 = -1, oldDuration, newDuration;
	string stop1, stop2;
	string input;

	index = searchLineIdentifier(id);

	vector<int> newTimings = linesData[index].getTimings();

	cout << "Alterar duração" << endl << endl;

	while (!validInput)
	{
		index1 = -1;
		index2 = -1;

		cout << "Paragem 1: ";
		getline(cin, stop1);

		cout << "Paragem 2: ";
		getline(cin, stop2);

		for (int i = 0; i < linesData[index].getBusStops().size(); i++)
		{
			if (linesData[index].getBusStops()[i] == stop1)
				index1 = i;
			if (linesData[index].getBusStops()[i] == stop2)
				index2 = i;
		}

		if (index1 != -1 && index2 != -1)
		{
			if (index1 == index2 + 1 || index2 == index1 + 1)
				validInput = true;
			else
				cout << "As paragens devem ser consecutivas. Tente novamente..." << endl;
		}
		else
			cout << "As paragens não foram encontradas! Tente novamente..." << endl;
	}

	cout << "Atualmente, a duração entre " << stop1 << " e " << stop2 << " é: ";

	oldDuration = newTimings[min(index1, index2)];
	cout << oldDuration << endl;

	validInput = false;

	while (!validInput)
	{
		cout << "Nova duração: ";

		getline(cin, input);

		if (isNumber(input))
		{
			if(stoi(input)==oldDuration)
				cout << "A duração é a mesma! Tente novamente...";
			else if (stoi(input) > 0 && stoi(input) <= 5 * 60)
				validInput = true;
			else
				cout << "Ajuste o valor inserido. Tente novamente..." << endl;
		}
		else
			cout << "Input inválido! Tente novamente...";

	}

	newDuration = stoi(input);

	newTimings[min(index1, index2)] = newDuration;
	linesData[index].setTimings(newTimings);

	cout << "Alterações efetuadas com sucesso!" << endl;
}
