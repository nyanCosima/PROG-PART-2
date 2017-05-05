#include <string>
#include "Company.h"
#include <iostream>
#include "myTypes.h"

using namespace std;

/*
Recebe uma paragem do utilizador, e devolve as linhas em que se encontra, funcionando tamb�m para o caso de n�o existir.
*/
void searchStop(Company company)
{
	string stop;
	vector<int> lines;

	cout << "Procurar paragem" << endl << endl;

	cout << "Paragem: ";
	getline(cin, stop);

	company.searchStop(stop);
}

/*
Semelhante � fun��o acima, mas com uma pequena diferen�a. Devolve true se a paragem existir nos registos, e false
se n�o for encontrada.
*/

/*
bool stopExists(string stop)
{
	vector<int> lines;

	//Guarda num vetor os identificadores das linhas que contiverem a paragem indicada
	for (int i = 0; i < linesData.size(); i++)
		if(linesData[i].searchStop(stop))
			lines.push_back(linesData[i].getId());

	if (lines.size() == 0)
		return false; //Se o vetor for vazio, quer dizer que a paragem n�o se encontra em qualquer linha.
	else
		return true; //Caso contr�rio, quer dizer que existe em pelo menos uma linha.
}

*/
//PODE NAO SER NECESSARIO


/*
Recebe duas paragens do utilizador e procura-as nas linhas existentes. Caso exista alguma linha que as contenha,
calcula o percurso a efetuar e a dura��o total. Caso exista mais do que uma linha, apenas devolve a que tiver
menor dura��o. Tamb�m funciona para o caso de n�o existir.
*/
void routeCalculator(Company company)
{
	string stop1, stop2;

	cout << "Percurso entre paragens" << endl << endl;

	cout << "Paragem inicial: ";
	getline(cin, stop1);

	cout << "Paragem final: ";
	getline(cin, stop2);

	company.routeCalculator(stop1, stop2);
}

int searchStopIndex(vector<string> busStops, string STOP){

    for (int i = 0; i < busStops.size(); ++i) {
        if (busStops.at(i)==STOP)
            return i;
    }
    return -1;
}
