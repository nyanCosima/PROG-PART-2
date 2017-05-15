#include "Bus.h"
#include "Time.h"
#include <iostream>
#include <algorithm>

bool shiftSortHelper(const Shift &x, const Shift &y);

Bus::Bus(unsigned int order, unsigned int driver, unsigned int line) {

	lineId = line;
	driverId = driver;
	orderInLine = order;
}

Bus::Bus(unsigned int order, unsigned int line) {

	lineId = line;
	orderInLine = order;
	driverId = 0;
}

////////////////////////////////
// get methods
///////////////////////////////
unsigned int Bus::getBusOrderInLine() const {
	return orderInLine;
}

unsigned int Bus::getDriverId() const {
	return driverId;
}

unsigned int Bus::getLineId() const {
	return lineId;
}

vector<Shift> Bus::getSchedule() const {
	return schedule;
}


//////////////////////////////
// metodos set
/////////////////////////////
void Bus::setDriverId(unsigned int newDriverID)
{
	driverId = newDriverID;
}

void Bus::setLineId(unsigned int newLineID)
{
	lineId = newLineID;
}


////////////////////////////
// outher methods
///////////////////////////

/*
Mostra informacao sobre um autocarro tendo em conta se ele tem turnos atribuidos ou nao.
*/
void Bus::showInfo() const {
	if (driverId == 0)
		cout << "Ainda nao tem trabalho atribuido!" << endl;
	else
		for (int i = 0; i < schedule.size(); i++)
		{
			cout << "Turno " << i + 1 << endl << endl;
			schedule.at(i).showInfo();
		}
}

/*
Adiciona um turno ao autocarro e garante que o vetor fica ordenado.
*/
void Bus::addShift(Shift s)
{
	schedule.push_back(s);

	sort(schedule.begin(), schedule.end(), shiftSortHelper);
}

/*
Verifica os periodos em que o autocarro nao tem condutor atribuido e lista-os.
*/
void Bus::checkBus() const
{
	int const startingTime = 6 * 60;
	int const endingTime = 19 * 60;

	if (schedule.size() == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "Periodo " << (i + 1) << endl;

			cout << "Tempo inicial: ";
			showTime(convertMinHours(startingTime + i * 24 * 60));
			cout << "Tempo final: ";
			showTime(convertMinHours(endingTime + i * 24 * 60));
			cout << endl;
		}
	}
	else if (schedule.size() == 1)
	{
		int min1 = schedule.at(0).getStartTime();
		int min2 = schedule.at(0).getEndTime();
		int numPeriods;

		if (convertMinHours(min1).hours == convertMinHours(startingTime).hours && convertMinHours(min1).minutes == convertMinHours(startingTime).minutes)
		{
			numPeriods = 5;

			for (int i = 0; i < numPeriods; i++)
			{
				cout << "Periodo " << (i + 1) << endl;

				if (convertMinHours(min1).numberOfDay == i)
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(min2));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
				else
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
			}
		}
		else if (convertMinHours(min2).hours == convertMinHours(endingTime).hours && convertMinHours(min2).minutes == convertMinHours(endingTime).minutes)
		{
			numPeriods = 5;

			for (int i = 0; i < numPeriods; i++)
			{
				cout << "Periodo " << (i + 1) << endl;

				if (convertMinHours(min1).numberOfDay == i)
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(min2));
					cout << endl;
				}
				else
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
			}
		}
		else
		{
			numPeriods = 6;

			for (int i = 0; i < numPeriods; i++)
			{
				cout << "Periodo " << (i + 1) << endl;

				if (convertMinHours(min1).numberOfDay == i)
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(min1));
					cout << endl;
				}
				else if (i>0 && convertMinHours(min1).numberOfDay == i - 1)
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(min2));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + (i - 1) * 24 * 60));
					cout << endl;
				}
				else if (i>0)
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + (i - 1) * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + (i - 1) * 24 * 60));
					cout << endl;
				}
				else
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}

			}
		}

	}
	else
	{
		int counter = 1;

		//Primeiro periodo (ate o inicio do primeiro turno)

		int min1 = schedule.at(0).getStartTime();
		int min2 = schedule.at(0).getEndTime();

		

		if (convertMinHours(min1).hours == convertMinHours(startingTime).hours && convertMinHours(min1).minutes == convertMinHours(startingTime).minutes)
			for (int i = 0; i < convertMinHours(min1).numberOfDay; i++)
			{
				if (i == convertMinHours(min1).numberOfDay)
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(min2));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
				else
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
			}
		else if (convertMinHours(min2).hours == convertMinHours(endingTime).hours && convertMinHours(min2).minutes == convertMinHours(endingTime).minutes)
			for (int i = 0; i <= convertMinHours(min1).numberOfDay; i++)
			{

				if (i == convertMinHours(min1).numberOfDay)
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(min1));
					cout << endl;
				}
				else
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
			}
		else
			for (int i = 0; i <= convertMinHours(min1).numberOfDay; i++)
			{
				if (i == convertMinHours(min1).numberOfDay)
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(min1));
					cout << endl;
				}
				else
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}

			}


		//Periodos entre os turnos
		for (int i = 0; i < schedule.size() - 1; i++)
		{
			int min3 = schedule.at(i).getEndTime();
			int min4 = schedule.at(i + 1).getStartTime();

			if (convertMinHours(min3).numberOfDay == convertMinHours(min4).numberOfDay)
			{
				cout << "Periodo: " << counter << endl;
				counter++;
				cout << "Tempo inicial: ";
				showTime(convertMinHours(min3));
				cout << "Tempo final: ";
				showTime(convertMinHours(min4));
				cout << endl;
			}
			else
			{
				cout << "Periodo: " << counter << endl;
				counter++;
				cout << "Tempo inicial: ";
				showTime(convertMinHours(min3));
				cout << "Tempo final: ";
				showTime(convertMinHours(endingTime + convertMinHours(min3).numberOfDay * 24 * 60));
				cout << endl;

				cout << "Periodo: " << counter << endl;
				counter++;
				cout << "Tempo inicial: ";
				showTime(convertMinHours(startingTime + convertMinHours(min4).numberOfDay * 24 * 60));
				cout << "Tempo final: ";
				showTime(convertMinHours(min4));
				cout << endl;
			}
		}


		//Ultimo turno (depois do fim do ultimo turno)

		int min5 = schedule.at(schedule.size() - 1).getStartTime();
		int min6 = schedule.at(schedule.size() - 1).getEndTime();

	

		if (convertMinHours(min5).hours == convertMinHours(startingTime).hours && convertMinHours(min5).minutes == convertMinHours(startingTime).minutes)
			for (int i = convertMinHours(min5).numberOfDay; i <= 4; i++)
			{
				if (i == convertMinHours(min5).numberOfDay)
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(min6));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
				else
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
			}
		else if (convertMinHours(min6).hours == convertMinHours(endingTime).hours && convertMinHours(min6).minutes == convertMinHours(endingTime).minutes)
			for (int i = convertMinHours(min5).numberOfDay; i < 4; i++)
			{
				if (i == convertMinHours(min5).numberOfDay)
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(min5));
					cout << endl;
				}
				else
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
			}
		else
			for (int i = convertMinHours(min5).numberOfDay; i <= 4; i++)
			{
				if (i == convertMinHours(min5).numberOfDay)
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(min6));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}
				else
				{
					cout << "Periodo: " << counter << endl;
					counter++;

					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
					cout << endl;
				}

			}
	}

}
