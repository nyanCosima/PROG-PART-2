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
		
		cout << endl;
	}
}