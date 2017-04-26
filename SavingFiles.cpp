#include "myTypes.h"

/*
Guarda a informaÁ„o contida no vetor de structs no ficheiro de linhas.
*/
void savingLinesData(const vector<Line> &data)
{
	ofstream out_stream;

	out_stream.open(linesFileName);

	for (int i = 0; i < data.size(); i++)
	{
		out_stream << data[i].getId() << " ; ";
		out_stream << data[i].getFrequency() << " ; ";

		for (int j = 0; j < (data[i].getBusStops().size() - 1); j++)
			out_stream << data[i].getBusStops()[j] << ", ";

		out_stream << data[i].getBusStops()[data[i].getBusStops().size() - 1] << "; ";

		for (int t = 0; t < (data[i].getTimings().size() - 1); t++)
			out_stream << data[i].getTimings()[t] << ", ";

		out_stream << data[i].getTimings()[(data[i].getTimings().size() - 1)] << endl;
	}
	out_stream.close();
}

/*
Guarda a informaÁ„o contida no vetor de structs no ficheiro de condutores.
*/
void savingDriversData(const vector<Driver> &data)
{
	ofstream out_stream;

	out_stream.open(driversFileName);

	for (int i = 0; i < data.size(); i++)
	{
		out_stream << data[i].getId() << " ; ";
		out_stream << data[i].getName() << " ; ";
		out_stream << data[i].getShiftMaxDuration() << " ; ";
		out_stream << data[i].getMaxWeekWorkingTime() << " ; ";
		out_stream << data[i].getMinRestTime() << endl;
	}
	out_stream.close();
}


/*
Pergunta ao utilizador se pretende guardar as alteraÁıes e age de acordo com a sua resposta.
*/
void savingChanges(vector<Line> linesData, vector<Driver> driversData)
{
	char userChoice;
	bool validInput = false;

	while (!validInput)
	{
		cout << endl << "Deseja guardar as alteraÁıes? (S/N) : ";

		if (cin >> userChoice && (userChoice == 'S' || userChoice == 'N' || userChoice == 's' || userChoice == 'n'))
		{
			validInput = true;
			cin.ignore(1000, '\n');
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "OpÁ„o inv·lida, tente novamente..." << endl << endl;
		}
	}

	if (userChoice == 'S' || userChoice == 's')
	{
		savingDriversData(driversData);
		savingLinesData(linesData);
	}
}