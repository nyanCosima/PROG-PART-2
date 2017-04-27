#include "myTypes.h"

/*
Recebe uma paragem do utilizador, e devolve as linhas em que se encontra, funcionando tamb�m para o caso de n�o existir.
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
		cout << "A paragem n�o se encontra em nenhuma linha!" << endl;
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
Semelhante �s outras fun��es, mas devolve true se a paragem existir na linha especificada, e false no caso contr�rio.
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
Procura a exist�ncia de uma linha no vetor de structs, dado o ID. Caso exista, devolve o �ndice da linha.
Caso contr�rio, devolve -1.
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
Procura a exist�ncia de um condutor no vetor de structs, dado o ID. Caso exista, devolve o �ndice do condutor.
Caso contr�rio, devolve -1.
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