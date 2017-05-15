#include <string>
#include "Company.h"
#include <iostream>
#include "myTypes.h"

using namespace std;

/*
Recebe uma paragem do utilizador, e devolve as linhas em que se encontra, funcionando também para o caso de não existir.
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
Recebe duas paragens do utilizador e procura-as nas linhas existentes. Caso exista alguma linha que as contenha,
calcula o percurso a efetuar e a duração total. Caso exista mais do que uma linha, apenas devolve a que tiver
menor duração. Também funciona para o caso de não existir.
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
