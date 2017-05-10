﻿#include "Company.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

Company::Company(string name, string linesFile, string driversFile){
	
	linesFileName = linesFile;
	driversFileName = driversFile;
	serviceStartingTime = 6 * 60;
	serviceEndingTime = 19 * 60;

	//LER DOS FICHEIROS PARA STRINGS
	ifstream in_stream;
	string line;
	vector<string> linesFileContent;

	in_stream.open(linesFileName);

	if (in_stream.fail())
	{
		cerr << "Ficheiro das linhas não encontrado. Fechando o programa..." << endl;
		exit(1);
	}

	while (!in_stream.eof())
	{
		getline(in_stream, line);
		if (line == "")
			continue;
		linesFileContent.push_back(line);
	}

	cout << "Conteudos lidos!" << endl << endl;

	in_stream.close();

	vector<string> driversFileContent;


	in_stream.open(driversFileName);

	if (in_stream.fail())
	{
		cerr << "Ficheiro dos condutores não encontrado. Fechando o programa..." << endl;
		exit(1);
	}

	while (!in_stream.eof())
	{
		getline(in_stream, line);
		if (line == "")
			continue;
		driversFileContent.push_back(line);
	}

	cout << "Conteudos lidos!" << endl << endl;

	in_stream.close();

	vector<Line> linesVector;

	for (int i = 0; i < linesFileContent.size(); i++)
	{
		Line l(linesFileContent[i]);
		linesVector.push_back(l);
	}

	vector<Driver> driversVector;

	for (int i = 0; i < driversFileContent.size(); i++)
	{
		Driver d(driversFileContent[i]);
		driversVector.push_back(d);
	}


	this->name = name;
	lines = linesVector;
	drivers = driversVector;
}

////////////////////////////////
// metodos get
///////////////////////////////
string Company::getName() const{
  return name;
}

vector<Line> Company::getLines() const
{
	return lines;
}

vector<Driver> Company::getDrivers() const
{
	return drivers;
}

unsigned int Company::getStartingTime() const
{
	return serviceStartingTime;
}

unsigned int Company::getEndingTime() const
{
	return serviceEndingTime;
}

//////////////////////////////
// metodos set
/////////////////////////////

void Company::setDrivers(vector<Driver> newDrivers)
{
	drivers = newDrivers;
}

void Company::addDriver(Driver newDriver)
{
	drivers.push_back(newDriver);
}

void Company::removeDriver(int index)
{
	drivers.erase(drivers.begin() + index);
}


////////////////////////////
// outros metodos
///////////////////////////
void Company::allocateService(){
}

/*
Procura a existência de uma linha no vetor de classes, dado o ID. Caso exista, devolve o índice da linha.
Caso contrário, devolve -1.
*/
int Company::searchLineIdentifier(unsigned int id)
{
	int found = -1;

	for (int i = 0; i < lines.size(); i++)
		if (lines[i].getId() == id)
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
int Company::searchDriverIdentifier(unsigned int id)
{
	int found = -1;

	for (int i = 0; i < drivers.size(); i++)
		if (drivers[i].getId() == id)
		{
			found = i;
			break;
		}

	return found;
}

/*
Guarda a informaÁ„o contida no vetor de structs no ficheiro de linhas.
*/
void Company::savingLinesData()
{
	ofstream out_stream;

	out_stream.open(linesFileName);

	for (int i = 0; i < lines.size(); i++)
	{
		out_stream << lines[i].getId() << " ; ";
		out_stream << lines[i].getFrequency() << " ; ";

		for (int j = 0; j < lines[i].getBusStops().size(); j++)
		{
			if (j > 0)
				out_stream << ", ";
			out_stream << lines[i].getBusStops()[j];
		}

		out_stream << "; ";

		for (int t = 0; t < lines[i].getTimings().size(); t++)
		{
			if (t > 0)
				out_stream << ", ";
			out_stream << lines[i].getTimings()[t];
		}

		out_stream << endl;
	}

	out_stream.close();
}

/*
Guarda a informaÁ„o contida no vetor de structs no ficheiro de condutores.
*/
void Company::savingDriversData()
{
	ofstream out_stream;

	out_stream.open(driversFileName);

	for (int i = 0; i < drivers.size(); i++)
	{
		out_stream << drivers[i].getId() << " ; ";
		out_stream << drivers[i].getName() << " ; ";
		out_stream << drivers[i].getShiftMaxDuration() << " ; ";
		out_stream << drivers[i].getMaxWeekWorkingTime() << " ; ";
		out_stream << drivers[i].getMinRestTime() << endl;
	}
	out_stream.close();
}

/*
Esta struct e a função a seguir são úteis para, na função de calcular um percurso, se poder ordenar os vários percursos
por duração.
*/

typedef struct {
	int ID; //Identifica o percurso
	int duration;
}durationHelper;

bool sortHelper(const durationHelper& x, const durationHelper& y)
{
	return x.duration < y.duration;
}

/*
Recebe duas paragens do utilizador e procura-as nas linhas existentes. Devolve todos os percursos possíveis,
sendo que se admite que há, no máximo, um transbordo. Também funciona para o caso de não existir.
*/
void Company::routeCalculator(string stop1, string stop2)
{
	typedef struct {
		int lineIndex;
		int stopIndex;
	} stopInfo;

	typedef struct {
		vector<string> stops;
		int ID; //Identifica o percurso, útil para coordenar com a struct durationHelper
		int lineID;
		int duration;
	}sameLineRoute;

	typedef struct {
		string commonStop;
		int ID; //Identifica o percurso, útil para coordenar com a struct durationHelper
		int line1ID;
		vector<string> line1stops;
		vector<string> line2stops;
		int line2ID;
		int duration;
	}difLineRoute;

	typedef struct {
		int line1StopIndex;
		int line2StopIndex;
		string stop;
	}commonStopInfo;

	vector<durationHelper> durHelper;
	vector<difLineRoute> difLineRoutes;
	vector<sameLineRoute> sameLineRoutes;
	vector<stopInfo> info; //Para guardar informações sobre a paragem inicial

	//Procurar a paragem inicial
	for (int i = 0; i < lines.size(); i++)
		for (int j = 0; j < lines[i].getBusStops().size(); j++)
			if (lines[i].getBusStops()[j] == stop1)
			{
				stopInfo stopI;
				stopI.lineIndex = i;
				stopI.stopIndex = j;

				info.push_back(stopI);
			}


	//Procurar a paragem final
	for (int i = 0; i < lines.size(); i++)
		for (int j = 0; j < lines[i].getBusStops().size(); j++)
			if (lines[i].getBusStops()[j] == stop2)
				for (int c = 0; c < info.size(); c++)
					if (info[c].lineIndex == i) //Paragens estão na mesma linha
					{
						sameLineRoute route;
						durationHelper dH;
						route.duration = 0;

						if (j > info[c].stopIndex)
						{
							for (int c1 = 0; c1 <= (j - info[c].stopIndex); c1++)
								route.stops.push_back(lines[i].getBusStops()[info[c].stopIndex + c1]);

							for (int c2 = 0; c2 < (j - info[c].stopIndex); c2++)
								route.duration += lines[i].getTimings()[info[c].stopIndex + c2];
						}
						else
						{
							for (int c1 = 0; c1 <= (info[c].stopIndex - j); c1++)
								route.stops.push_back(lines[i].getBusStops()[info[c].stopIndex - c1]);

							for (int c2 = 0; c2 < (info[c].stopIndex - j); c2++)
								route.duration += lines[i].getTimings()[j + c2];
						}

						route.ID = c;
						route.lineID = lines[i].getId();
						sameLineRoutes.push_back(route);
						dH.duration = route.duration;
						dH.ID = c;
						durHelper.push_back(dH);
					}
					else //Paragens estão em linhas diferentes
					{
						vector<commonStopInfo> commonStopsInfo;

						//Procurar paragens comuns
						for (int c1 = 0; c1 < lines[info[c].lineIndex].getBusStops().size(); c1++)
							for (int c2 = 0; c2 < lines[i].getBusStops().size(); c2++)
							{
								if (lines[info[c].lineIndex].getBusStops()[c1] == lines[i].getBusStops()[c2])
								{
									commonStopInfo cSI;

									string common = lines[info[c].lineIndex].getBusStops()[c1];

									if (common != stop1 && common != stop2)
									{
										cSI.line1StopIndex = c1;
										cSI.line2StopIndex = c2;
										cSI.stop = common;

										commonStopsInfo.push_back(cSI);
									}
								}

							}

						for (int c3 = 0; c3 < commonStopsInfo.size(); c3++)
						{
							difLineRoute dLR;
							durationHelper dH;

							dLR.commonStop = commonStopsInfo[c3].stop;
							dLR.line1ID = lines[info[c].lineIndex].getId();
							dLR.duration = 0;
							dLR.line2ID = lines[i].getId();

							if (commonStopsInfo[c3].line1StopIndex > info[c].stopIndex)
							{
								for (int c4 = 0; c4 <= (commonStopsInfo[c3].line1StopIndex - info[c].stopIndex); c4++)
									dLR.line1stops.push_back(lines[info[c].lineIndex].getBusStops()[info[c].stopIndex + c4]);

								for (int c5 = 0; c5 < (commonStopsInfo[c3].line1StopIndex - info[c].stopIndex); c5++)
									dLR.duration += lines[info[c].lineIndex].getTimings()[info[c].stopIndex + c5];
							}
							else
							{
								for (int c4 = 0; c4 <= (info[c].stopIndex - commonStopsInfo[c3].line1StopIndex); c4++)
									dLR.line1stops.push_back(lines[info[c].lineIndex].getBusStops()[info[c].stopIndex - c4]);

								for (int c5 = 0; c5 < (info[c].stopIndex - commonStopsInfo[c3].line1StopIndex); c5++)
									dLR.duration += lines[info[c].lineIndex].getTimings()[commonStopsInfo[c3].line1StopIndex + c5];
							}

							if (j > commonStopsInfo[c3].line2StopIndex)
							{
								for (int c4 = 0; c4 <= (j - commonStopsInfo[c3].line2StopIndex); c4++)
									dLR.line2stops.push_back(lines[i].getBusStops()[commonStopsInfo[c3].line2StopIndex + c4]);

								for (int c5 = 0; c5 < (j - commonStopsInfo[c3].line2StopIndex); c5++)
									dLR.duration += lines[i].getTimings()[commonStopsInfo[c3].line2StopIndex + c5];
							}
							else
							{
								for (int c4 = 0; c4 <= (commonStopsInfo[c3].line2StopIndex - j); c4++)
									dLR.line2stops.push_back(lines[i].getBusStops()[commonStopsInfo[c3].line2StopIndex - c4]);

								for (int c5 = 0; c5 < (commonStopsInfo[c3].line2StopIndex - j); c5++)
									dLR.duration += lines[i].getTimings()[j + c5];
							}

							dLR.ID = info.size() + 1 + c3;
							dH.duration = dLR.duration;
							dH.ID = dLR.ID;
							durHelper.push_back(dH);
							difLineRoutes.push_back(dLR);
						}

					}


	sort(durHelper.begin(), durHelper.end(), sortHelper); //Ordenar o vetor por ordem de duração

	//Mostrar os percursos

	if (durHelper.size() == 0)
		cout << "Não foi encontrado qualquer percurso!" << endl;
	else
	{
		if (durHelper.size() > 1)
			cout << endl << "Foram encontrados " << durHelper.size() << " percursos" << endl;
		else
			cout << endl << "Existe um único percurso" << endl;

		for (int i = 0; i < durHelper.size(); i++)
		{
			if (durHelper.size() > 1)
				cout << endl << "Percurso " << i + 1 << endl;
			
			//Procurar o tipo de percurso e mostrá-lo

			for (int c = 0; c < sameLineRoutes.size(); c++)
			{
				if (durHelper[i].ID == sameLineRoutes[c].ID)
				{
					cout << "Linha: " << sameLineRoutes[c].lineID << endl;
					cout << "Paragens: ";

					for (int c1 = 0; c1 < sameLineRoutes[c].stops.size(); c1++)
					{
						if (c1 > 0)
							cout << " - ";
						cout << sameLineRoutes[c].stops[c1];
					}

					cout << endl << "Duração: " << sameLineRoutes[c].duration << " minutos" << endl;
				}
			}

			for (int c = 0; c < difLineRoutes.size(); c++)
			{
				if (durHelper[i].ID == difLineRoutes[c].ID)
				{
					cout << "Linha 1: " << difLineRoutes[c].line1ID << endl;
					cout << "Paragens: ";

					for (int c1 = 0; c1 < difLineRoutes[c].line1stops.size(); c1++)
					{
						if (c1 > 0)
							cout << " - ";
						cout << difLineRoutes[c].line1stops[c1];
					}

					cout << endl << "Transbordo em: " << difLineRoutes[c].commonStop << endl;
					cout << "Linha 2: " << difLineRoutes[c].line2ID << endl; 
					cout << "Paragens: ";


					for (int c1 = 0; c1 < difLineRoutes[c].line2stops.size(); c1++)
					{
						if (c1 > 0)
							cout << " - ";
						cout << difLineRoutes[c].line2stops[c1];
					}

					cout << endl << "Duração: " << difLineRoutes[c].duration << " minutos" << endl;
				}
			}
		}
	}

}

/*
Recebe uma paragem, e devolve as linhas em que se encontra, funcionando também para o caso de não existir.
*/
void Company::searchStop(string stop)
{
	vector<int> foundLines;

	//Guarda num vetor os identificadores das linhas que contiverem a paragem indicada
	for (int i = 0; i < lines.size(); i++)
		if (lines[i].searchStop(stop))
			foundLines.push_back(lines[i].getId());

	if (foundLines.size() == 0)
		cout << "A paragem não se encontra em nenhuma linha!" << endl;
	else
	{
		cout << "A paragem encontra-se na(s) linha(s): ";

		for (int c = 0; c < foundLines.size(); c++)
		{
			if (c > 0)
				cout << ", ";
			cout << foundLines[c];
		}
		cout << endl;
	}
}