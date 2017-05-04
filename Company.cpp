#include "myTypes.h"



Company::Company(string name){
	
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
Recebe duas paragens do utilizador e procura-as nas linhas existentes. Caso exista alguma linha que as contenha,
calcula o percurso a efetuar e a duração total. Caso exista mais do que uma linha, apenas devolve a que tiver
menor duração. Também funciona para o caso de não existir.
*/
void Company::routeCalculator(string stop1, string stop2)
{
	vector<int> foundLines;

	//Começar por procurar se existe alguma linha com ambas as paragens especificadas, ou se existem várias

	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i].searchStop(stop1) && lines[i].searchStop(stop2))
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

			for (int j = 0; j < lines[foundLines[i]].getBusStops().size(); j++)
			{
				if (lines[foundLines[i]].getBusStops()[j] == stop1)
					index1 = j;

				if (lines[foundLines[i]].getBusStops()[j] == stop2)
					index2 = j;
			}

			//Colocar num vetor as paragens pertencentes ao percurso
			//Como é necessário ter em conta o facto das linhas serem bidirecionais, é preciso verificar os índices.

			if (index2 > index1)
			{
				vector<string> route1;
				for (int c = 0; c <= (index2 - index1); c++)
					route1.push_back(lines[foundLines[i]].getBusStops()[index1 + c]);

				route.push_back(route1);

				for (int c1 = 0; c1 < (index2 - index1); c1++)
					totalDuration += lines[foundLines[i]].getTimings()[index1 + c1];

				durations.push_back(totalDuration);
			}
			else
			{
				vector<string> route2;
				for (int c = 0; c <= (index1 - index2); c++)
					route2.push_back(lines[foundLines[i]].getBusStops()[index1 - c]);

				route.push_back(route2);

				for (int c1 = 0; c1 < (index1 - index2); c1++)
					totalDuration += lines[foundLines[i]].getTimings()[index2 + c1];

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
		cout << "|" << setw(12) << " LINHA | " << lines[lineIdentifier].getId() << endl;

		cout << "|" << setw(12) << " PARAGENS | ";

		for (int i = 0; i < route[fasterRoute].size(); i++)
		{
			if (i > 0)
				cout << " -> ";
			cout << route[fasterRoute][i];
		}

		cout << endl << "|" << setw(12) << " DURAÇAO | " << durations[fasterRoute] << " minutos" << endl << endl;
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