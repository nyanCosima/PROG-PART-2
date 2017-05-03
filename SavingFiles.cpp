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

		for (int j = 0; j < linesData[i].getBusStops().size(); j++)
		{
			if (i > 0)
				cout << "; ";
			out_stream << linesData[i].getBusStops()[j];
		}

		for (int t = 0; t < linesData[i].getTimings().size(); t++)
		{
			if (i > 0)
				cout << "; ";
			out_stream << linesData[i].getTimings()[t];
		}
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
	string userChoice;
	bool validInput = false;

	while (!validInput)
	{
		cout <<  "Deseja guardar as alterações? (S/N) : ";
		getline(cin, userChoice);

		if (userChoice == "S" || userChoice == "N" || userChoice == "s" || userChoice == "n")
			validInput = true;
		else
			cout << "Opção inválida, tente novamente..." << endl << endl;
	}

	if (userChoice == "S" || userChoice == "s")
	{
		savingDriversData();
		savingLinesData();
	}
}