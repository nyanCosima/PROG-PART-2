#include "myTypes.h"

/*
Recebe os par�metros do utilizador (ID da linha, frequ�ncia de circula��o, paragens e dura��es) e guarda-os numa nova
Line, que � adicionada ao vetor criado anteriormente.
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

		if (input.size() <= 3) //S� s�o aceites IDs com, no m�ximo 3 d�gitos
		{

			if(isNumber(input)) //Se o input for um n�mero positivo
			{
				verify = searchLineIdentifier(stoi(input)); //Verifica a exist�ncia do ID

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

	//Recebe a frequ�ncia do utilizador

	validInput = false;
	while (!validInput)
	{
		cout << "Frequ�ncia: ";
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
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
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
			cout << "Input inv�lido! Tente novamente..." << endl;
	}

	frequency = stoi(input);


	/*
	Recebe as paragens do utilizador. Deteta o fim do input e tamb�m assegura que o input � v�lido, na medida
	em que n�o permite input vazio
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
			else if (stop == "") //N�o aceita input vazio.
				cout << "Input inv�lido! Tente novamente..." << endl << endl;
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

	//Recebe as dura��es do utilizador

	int numberOfIterations = stops.size() - 1;

	while (j < numberOfIterations)
	{
		int d;

		validInput = false;

		while (!validInput)
		{
			cout << "Dura��o " << (j + 1) << ": ";

			getline(cin, input);

			if (isNumber(input))
			{
				if (stoi(input) > 0 && stoi(input) <= 5 * 60)
					validInput = true;
				else
					cout << "Ajuste o valor inserido. Tente novamente..." << endl;
			}
			else
				cout << "Input inv�lido! Tente novamente..." << endl;
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
Edita as linhas j� criadas. Fornece meios para: alterar a frequ�ncia de circula�ao, adicionar paragem, remover paragem,
alterar paragem, alterar dura��es.
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

		if (input.size() <= 3) //S� s�o aceites IDs com, no m�ximo 3 d�gitos
		{

			if (isNumber(input)) //Se o input for um n�mero positivo
			{
				verify = searchLineIdentifier(stoi(input)); //Verifica a exist�ncia do ID

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

	//Apresenta uma interface com as fun��es dispon�veis para alterar uma linha

	cout << endl << "Escolha o que pretende alterar" << endl;
	cout << "1 - Alterar frequ�ncia" << endl;
	cout << "2 - Adicionar paragem" << endl;
	cout << "3 - Alterar paragem" << endl;
	cout << "4 - Remover paragem" << endl;
	cout << "5 - Alterar dura��o" << endl;
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

		if (input.size() <= 3) //S� s�o aceites IDs com, no m�ximo 3 d�gitos
		{

			if (isNumber(input)) //Se o input for um n�mero positivo
			{
				verify = searchLineIdentifier(stoi(input)); //Verifica a exist�ncia do ID

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

	linesData.erase(linesData.begin() + verify);

	cout << "Linha apagada com sucesso!" << endl;
}

/*
Muda a frequ�ncia de circula��o numa linha dada pelo utilizador.
*/
void changeFrequency(unsigned int id)
{
	int index;
	unsigned int newfreq;
	string input;
	index = searchLineIdentifier(id);
	bool validInput = false;

	cout << "Alterar frequ�ncia" << endl;

	cout << endl << "A frequ�ncia atual �: " << linesData[index].getFrequency() << endl;


	while (!validInput)
	{
		cout << "Nova frequ�ncia: ";
		getline(cin, input);

		if (isNumber(input))
		{
			if (stoi(input) > 0 && stoi(input) < 5 * 60)
				validInput = true;
			else
				cout << "Ajuste o valor inserido. Tente novamente..." << endl;
		}
		else
			cout << "Input inv�lido! Tente novamente..." << endl;

	}

	newfreq = stoi(input);

	linesData[index].setFrequency(newfreq);

	cout << "Altera��es efetuadas com sucesso!" << endl;
}

/*
Remove uma paragem numa linha dada pelo utilizador, assegurando que � corrigida a dura��o.
Para isso, pergunta ao utilizador qual a dura��o entre as duas paragens adjacentes � paragem removida.
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
			cout << "A paragem especificada n�o existe! Tente novamente..." << endl;
	}

	newBusList.erase(newBusList.begin() + stopIndex);
	linesData[index].setBusStops(newBusList);

	//Corrige as dura��es

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
			cout << "Dura��o entre " << newBusList[indexStop1] << " e " << newBusList[indexStop2] << ": ";

			if (isNumber(input))
			{
				if (stoi(input) > 0 && stoi(input) <= 5 * 60)
					validInput = true;
				else
					cout << "Ajuste o valor inserido. Tente novamente..." << endl;
			}
			else
				cout << "Input inv�lido! Tente novamente..." << endl;
		}

		newDuration = stoi(input);

		newTimings.erase(newTimings.begin() + indexStop1);
		newTimings[indexStop1] = newDuration;

		linesData[index].setTimings(newTimings);

		cout << "Paragem removida com sucesso!" << endl;
	}
}

/*
Adiciona uma paragem a uma linha indicada pelo utilizador, assegurando que as dura��es s�o corrigidas.
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
			cout << "Input inv�lido! Tente novamente..." << endl;
		else if (searchStop3(index, stop))
			cout << "A paragem j� se encontra na linha! Tente novamente..." << endl;
		else
			validInput = true;
	}

	validInput = false;

	while (!validInput)
	{
		cout << "�ndice (a come�ar em 0): ";
		getline(cin, input);

		if (isNumber(input))
		{
			stopIndex = stoi(input);

			if (stopIndex >= 0 && stopIndex <= linesData[index].getBusStops().size())
				validInput = true;
			else
				cout << "Esse �ndice n�o existe! Tente novamente..." << endl;
		}
		else
			cout << "Input inv�lido! Tente novamente..." << endl;
	}

	newBusList.insert(newBusList.begin() + stopIndex, stop);
	linesData[index].setBusStops(newBusList);

	//Corrigir dura��es

	if (stopIndex == 0)
	{
		int duration;

		validInput = false;

		while (!validInput)
		{
			cout << "Dura��o entre " << stop << " e " << newBusList[stopIndex + 1] << ": ";
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
				cout << "Input inv�lido! Tente novamente..." << endl;
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
			cout << "Dura��o entre " << newBusList[stopIndex - 1] << " e " << stop << ": ";
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
				cout << "Input inv�lido! Tente novamente..." << endl;
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
			cout << "Dura��o entre " << newBusList[stopIndex - 1] << " e " << stop << ": ";
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
				cout << "Input inv�lido! Tente novamente..." << endl;
		}

		validInput = false;
		while (!validInput)
		{
			cout << "Dura��o entre " << stop << " e " << newBusList[stopIndex + 1] << ": ";
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
				cout << "Input inv�lido! Tente novamente..." << endl;
		}

		newTimings[stopIndex - 1] = duration1;
		newTimings.insert(newTimings.begin() + stopIndex, duration2);

		linesData[index].setTimings(newTimings);

	}

	cout << "Paragem adicionada com sucesso!" << endl;

}

/*
Altera uma paragem numa linha dada pelo utilizador, assegurando que as dura��es s�o corrigidas.
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
			cout << "A paragem especificada n�o existe! Tente novamente..." << endl;
	}

	validInput = false;
	while (!validInput)
	{
		cout << "Nova paragem: ";
		getline(cin, newStop);

		if (stop == "")
			cout << "Input inv�lido! Tente novamente..." << endl << endl;
		else
			validInput = true;
	}

	newBusList[stopIndex] = newStop;
	linesData[index].setBusStops(newBusList);

	//Corrigir as dura��es

	if (stopIndex == 0)
	{
		int duration;

		validInput = false;

		while (!validInput)
		{
			cout << "Dura��o entre " << newStop << " e " << newBusList[stopIndex + 1] << ": ";
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
				cout << "Input inv�lido! Tente novamente..." << endl;
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
			cout << "Dura��o entre " << newBusList[stopIndex - 1] << " e " << newStop << ": ";
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
				cout << "Input inv�lido! Tente novamente..." << endl;
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
			cout << "Dura��o entre " << newBusList[stopIndex - 1] << " e " << newStop << ": ";

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
				cout << "Input inv�lido! Tente novamente..." << endl;
		}

		validInput = false;
		while (!validInput)
		{
			cout << "Dura��o entre " << newStop << " e " << newBusList[stopIndex + 1] << ": ";

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
				cout << "Input inv�lido! Tente novamente..." << endl;
		}

		newTimings[stopIndex - 1] = duration1;
		newTimings[stopIndex] = duration2;

		linesData[index].setTimings(newTimings);
	}

	cout << "Paragem alterada com sucesso!" << endl;
}

/*
Altera a dura��o de um percurso especificado pelo utilizador. � �til para casos em que, por exemplo, um dos percursos se
encontre em obras e seja necess�rio efetuar uma altera��o.
*/
void changeDuration(unsigned int id)
{
	bool validInput = false;
	int index, index1 = -1, index2 = -1, oldDuration, newDuration;
	string stop1, stop2;
	string input;

	index = searchLineIdentifier(id);

	vector<int> newTimings = linesData[index].getTimings();

	cout << "Alterar dura��o" << endl << endl;

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
			cout << "As paragens n�o foram encontradas! Tente novamente..." << endl;
	}

	cout << "Atualmente, a dura��o entre " << stop1 << " e " << stop2 << " �: ";

	oldDuration = newTimings[min(index1, index2)];
	cout << oldDuration << endl;

	validInput = false;

	while (!validInput)
	{
		cout << "Nova dura��o: ";

		getline(cin, input);

		if (isNumber(input))
		{
			if(stoi(input)==oldDuration)
				cout << "A dura��o � a mesma! Tente novamente...";
			else if (stoi(input) > 0 && stoi(input) <= 5 * 60)
				validInput = true;
			else
				cout << "Ajuste o valor inserido. Tente novamente..." << endl;
		}
		else
			cout << "Input inv�lido! Tente novamente...";

	}

	newDuration = stoi(input);

	newTimings[min(index1, index2)] = newDuration;
	linesData[index].setTimings(newTimings);

	cout << "Altera��es efetuadas com sucesso!" << endl;
}
