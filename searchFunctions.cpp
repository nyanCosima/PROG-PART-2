#include "myTypes.h"

/*
Recebe uma paragem do utilizador, e devolve as linhas em que se encontra, funcionando também para o caso de não existir.
*/
void searchStop()
{
	string stop;
	bool validInput = false;
	vector<int> lines;

	cout << "Procurar paragem" << endl << endl;

	cout << "Paragem: ";
	getline(cin, stop);

	//Guarda num vetor os identificadores das linhas que contiverem a paragem indicada
	for (int i = 0; i < linesData.size(); i++)
	{
		for (int j = 0; j < linesData[i].getBusStops().size(); j++)
		{
			if (linesData[i].getBusStops()[j] == stop)
				lines.push_back(linesData[i].getId());
		}
	}

	if (lines.size() == 0)
		cout << "A paragem não se encontra em nenhuma linha!" << endl;
	else
	{
		cout << "A paragem encontra-se na(s) linha(s): ";

		for (int c = 0; c < lines.size(); c++)
		{
			if (c > 0)
				cout << ", ";
			cout << lines[c];
		}
	}
}

/*
Semelhante à função acima, mas com uma pequena diferença. Devolve true se a paragem existir nos registos, e false
se não for encontrada.
*/
bool searchStop2(string stop)
{
	vector<int> lines;

	//Guarda num vetor os identificadores das linhas que contiverem a paragem indicada
	for (int i = 0; i < linesData.size(); i++)
	{
		for (int j = 0; j < linesData[i].getBusStops().size(); j++)
		{
			if (linesData[i].getBusStops()[j] == stop)
				lines.push_back(linesData[i].getId());
		}
	}

	if (lines.size() == 0)
		return false; //Se o vetor for vazio, quer dizer que a paragem não se encontra em qualquer linha.
	else
		return true; //Caso contrário, quer dizer que existe em pelo menos uma linha.
}



/*
Semelhante às outras funções, mas devolve true se a paragem existir na linha especificada, e false no caso contrário.
*/
bool searchStop3(int lineIndex, string stop)
{
	for (int i = 0; i < linesData[lineIndex].getBusStops().size(); i++)
	{
		if (linesData[lineIndex].getBusStops()[i] == stop)
			return true;
	}

	return false;
}

/*
Procura a existência de uma linha no vetor de classes, dado o ID. Caso exista, devolve o índice da linha.
Caso contrário, devolve -1.
*/
int searchLineIdentifier(unsigned int id)
{
	int found = -1;

	for (int i = 0; i < linesData.size(); i++)
		if (linesData[i].getId() == id)
		{
			found = i;
			break;
		}

	return found;
}

/*
Procura a existência de um condutor no vetor de classes, dado o ID. Caso exista, devolve o índice do condutor.
Caso contrário, devolve -1.
*/
int searchDriverIdentifier(unsigned int id)
{
	int found = -1;

	for (int i = 0; i < driversData.size(); i++)
		if (driversData[i].getId() == id)
		{
			found = i;
			break;
		}

	return found;
}

/*
Recebe duas paragens do utilizador e procura-as nas linhas existentes. Caso exista alguma linha que as contenha,
calcula o percurso a efetuar e a duração total. Caso exista mais do que uma linha, apenas devolve a que tiver
menor duração. Também funciona para o caso de não existir.
*/
void routeCalculator()
{
	string stop1, stop2;
	vector<int> foundLines;

	cout << "Percurso entre paragens" << endl << endl;

	cout << "Paragem inicial: ";
	getline(cin, stop1);

	cout << "Paragem final: ";
	getline(cin, stop2);

	//Começar por procurar se existe alguma linha com ambas as paragens especificadas, ou se existem várias

	for (int i = 0; i < linesData.size(); i++)
	{
		bool found1 = false, found2 = false;

		for (int j = 0; j < linesData[i].getBusStops().size(); j++)
		{

			if (linesData[i].getBusStops()[j] == stop1)
				found1 = true; //Ativa o booleano se encontrar a primeira paragem
			if (linesData[i].getBusStops()[j] == stop2)
				found2 = true; //Ativa o booleano se encontrar a segunda paragem
		}

		if (found1 && found2)
			foundLines.push_back(i); //Se encontrar ambas as paragens na mesma linha, coloca o seu indíce num vetor
	}

	if (foundLines.size() == 0)
		cout << "Não foi encontrado qualquer percurso!" << endl;

	else
	{
		/*
		Um ciclo semelhante, mas agora guarda os índices de ambas as paragens, e com base nisso calcula
		a duração do percurso
		*/

		vector<int> durations;
		vector<vector<string>> route;

		for (int i = 0; i < foundLines.size(); i++)
		{
			int index1, index2, totalDuration = 0;

			for (int j = 0; j < linesData[foundLines[i]].getBusStops().size(); j++)
			{
				if (linesData[foundLines[i]].getBusStops()[j] == stop1)
					index1 = j;

				if (linesData[foundLines[i]].getBusStops()[j] == stop2)
					index2 = j;
			}

			//Colocar num vetor as paragens pertencentes ao percurso
			//Como é necessário ter em conta o facto das linhas serem bidirecionais, é preciso verificar os índices.

			if (index2 > index1)
			{
				vector<string> route1;
				for (int c = 0; c <= (index2 - index1); c++)
					route1.push_back(linesData[foundLines[i]].getBusStops()[index1 + c]);

				route.push_back(route1);

				for (int c1 = 0; c1 < (index2 - index1); c1++)
					totalDuration = totalDuration + linesData[foundLines[i]].getTimings()[index1 + c1];

				durations.push_back(totalDuration);
			}
			else
			{
				vector<string> route2;
				for (int c = 0; c <= (index1 - index2); c++)
					route2.push_back(linesData[foundLines[i]].getBusStops()[index1 - c]);

				route.push_back(route2);

				for (int c1 = 0; c1 < (index1 - index2); c1++)
					totalDuration = totalDuration + linesData[foundLines[i]].getTimings()[index2 + c1];

				durations.push_back(totalDuration);
			}

		}

		//Determinar o percurso mais rápido

		int comp = durations[0];
		int fasterRoute = 0;
		int lineIdentifier = foundLines[0];

		for (int i = 0; i < durations.size(); i++)
		{
			if (durations[i] < comp)
			{
				fasterRoute = i;
				lineIdentifier = foundLines[i];
			}
		}

		//Imprimir no ecrã o percurso e a sua duração

		cout << endl << "O percurso entre as paragens " << stop1 << " e " << stop2 << " poderá ser:" << endl << endl;
		cout << "|"  <<  setw(12) << " LINHA | " <<  linesData[lineIdentifier].getId() << endl;

		cout << "|" << setw(12)<< " PARAGENS | ";

		for (int i = 0; i < route[fasterRoute].size(); i++)
		{
			if (i > 0)
				cout << " -> ";
			cout << route[fasterRoute][i];
		}

		cout << endl << "|" << setw(12)<<  " DURAÇAO | " << durations[fasterRoute] << " minutos" << endl<< endl;
	}
}


