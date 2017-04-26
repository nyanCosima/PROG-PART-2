#include "myTypes.h"

/*
Guarda a informaÁ„o contida no vetor de structs no ficheiro de linhas.
*/
void savingLinesData()
{
	ofstream out_stream;

	out_stream.open(linesFileName);

	for (int i = 0; i < linesData.size(); i++)
	{
		out_stream << linesData[i].getId() << " ; ";
		out_stream << linesData[i].getFrequency() << " ; ";

		for (int j = 0; j < (linesData[i].getBusStops().size() - 1); j++)
			out_stream << linesData[i].getBusStops()[j] << ", ";

		out_stream << linesData[i].getBusStops()[linesData[i].getBusStops().size() - 1] << "; ";

		for (int t = 0; t < (linesData[i].getTimings().size() - 1); t++)
			out_stream << linesData[i].getTimings()[t] << ", ";

		out_stream << linesData[i].getTimings()[(linesData[i].getTimings().size() - 1)] << endl;
	}
	out_stream.close();
}

/*
Guarda a informaÁ„o contida no vetor de structs no ficheiro de condutores.
*/
void savingDriversData()
{
	ofstream out_stream;

	out_stream.open(driversFileName);

	for (int i = 0; i < driversData.size(); i++)
	{
		out_stream << driversData[i].getId() << " ; ";
		out_stream << driversData[i].getName() << " ; ";
		out_stream << driversData[i].getShiftMaxDuration() << " ; ";
		out_stream << driversData[i].getMaxWeekWorkingTime() << " ; ";
		out_stream << driversData[i].getMinRestTime() << endl;
	}
	out_stream.close();
}


/*
Pergunta ao utilizador se pretende guardar as alteraÁıes e age de acordo com a sua resposta.
*/
void savingChanges()
{
	char userChoice;
	bool validInput = false;

	while (!validInput)
	{
		cout <<  "Deseja guardar as alterações? (S/N) : ";

		if (cin >> userChoice && (userChoice == 'S' || userChoice == 'N' || userChoice == 's' || userChoice == 'n'))
		{
			validInput = true;
			cin.ignore(1000, '\n');
		}
		else
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Opção inválida, tente novamente..." << endl << endl;
		}
	}

	if (userChoice == 'S' || userChoice == 's')
	{
		savingDriversData();
		savingLinesData();
	}
}