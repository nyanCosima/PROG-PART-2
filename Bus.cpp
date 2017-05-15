#include "Bus.h"
#include "Time.h"
#include <iostream>
#include <algorithm>

bool shiftSortHelper(const Shift &x, const Shift &y);

Bus::Bus(unsigned int order, unsigned int driver, unsigned int line){

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
unsigned int Bus::getBusOrderInLine() const{
  return orderInLine;
}

unsigned int Bus::getDriverId() const{
  return driverId;
}

unsigned int Bus::getLineId() const{
  return lineId;
}

vector<Shift> Bus::getSchedule() const{
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
			cout << "Período " << (i + 1) << endl << endl;

			cout << "Tempo inicial: ";
			showTime(convertMinHours(startingTime + i * 24 * 60));
			cout << "Tempo final: ";
			showTime(convertMinHours(endingTime + i * 24 * 60));
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
				cout << "Período " << (i + 1) << endl << endl;

				if (convertMinHours(min1).numberOfDay == i)
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(min2));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
				}
				else
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
				}
			}
		}
		else if (convertMinHours(min2).hours == convertMinHours(endingTime).hours && convertMinHours(min2).minutes == convertMinHours(endingTime).minutes)
		{
			numPeriods = 5;

			for (int i = 0; i < numPeriods; i++)
			{
				cout << "Período " << (i + 1) << endl << endl;

				if (convertMinHours(min1).numberOfDay == i)
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime+i*24*60));
					cout << "Tempo final: ";
					showTime(convertMinHours(min2));
				}
				else
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
				}
			}
		}
		else
		{
			numPeriods = 6;

			for (int i = 0; i < numPeriods; i++)
			{
				cout << "Período " << (i + 1) << endl << endl;

				if (convertMinHours(min1).numberOfDay == i)
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(min1));
				}
				else if(i>0 && convertMinHours(min1).numberOfDay == i-1)
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(min2));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
				}
				else
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
				}
			}
		}

	}
	else
	{
		//Primeiro periodo (ate o inicio do primeiro turno)

		int min1 = schedule.at(0).getStartTime();
		int min2 = schedule.at(0).getEndTime();

		if (convertMinHours(min1).hours == convertMinHours(startingTime).hours && convertMinHours(min1).minutes == convertMinHours(startingTime).minutes)
			for (int i = 0; i < convertMinHours(min1).numberOfDay; i++)
			{
				if (i == convertMinHours(min1).numberOfDay)
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(min2));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime+i*24*60));
				}
				else
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
				}
			}
		else if (convertMinHours(min2).hours == convertMinHours(endingTime).hours && convertMinHours(min2).minutes == convertMinHours(endingTime).minutes)
			for (int i = 0; i <= convertMinHours(min1).numberOfDay; i++)
			{

				if (i == convertMinHours(min1).numberOfDay)
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(min1));
				}
				else
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
				}
			}
		else
			for (int i = 0; i <= convertMinHours(min1).numberOfDay; i++)
			{
				if (i==convertMinHours(min1).numberOfDay)
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(min1));
				}
				else
				{
					cout << "Tempo inicial: ";
					showTime(convertMinHours(startingTime + i * 24 * 60));
					cout << "Tempo final: ";
					showTime(convertMinHours(endingTime + i * 24 * 60));
				}
			
		}

		cout << "Período " << endl << endl;

		//Periodos entre os turnos
		for (int i = 0; i < schedule.size()-1; i++)
		{
			cout << "Período " << (i + 2) << endl << endl;

			int min3 = schedule.at(i).getEndTime();
			int min4 = schedule.at(i).getStartTime();

			if (convertMinHours(min3).numberOfDay == convertMinHours(min4).numberOfDay)
			{
				cout << "Tempo inicial: ";
				showTime(convertMinHours(min3));
				cout << "Tempo final: ";
				showTime(convertMinHours(min4));
			}
			else
			{
				cout << "Tempo inicial: ";
				showTime(convertMinHours(min3));
				cout << "Tempo final: ";
				showTime(convertMinHours(endingTime+convertMinHours(min3).numberOfDay *24*60));

				cout << "Tempo inicial: ";
				showTime(convertMinHours(startingTime + convertMinHours(min4).numberOfDay * 24 * 60));
				cout << "Tempo final: ";
				showTime(convertMinHours(min4));
			}
		}


		//Ultimo turno (depois do fim do ultimo turno)
		
		int min5 = schedule.at(schedule.size() - 1).getStartTime();
		int min6 = schedule.at(schedule.size() - 1).getEndTime();

		
	}

}
