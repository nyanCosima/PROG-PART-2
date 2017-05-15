#include "Driver.h"
#include "Time.h"
#include <algorithm>
#include <iostream>

Driver::Driver(string textLine){

  // INITIALISATION CODE GOES IN HERE
  //RECOLHER O ID
  int firstPos = 0;

  int semicolonPos = textLine.find(";", firstPos);

  string ids = textLine.substr(firstPos, semicolonPos - firstPos);
  unsigned int idN = stoi(ids);

  id = idN;


  //RECOLHER O NOME
  firstPos = semicolonPos + 2;

  semicolonPos = textLine.find(";", firstPos);

  string name = textLine.substr(firstPos, semicolonPos - firstPos - 1);

  this->name = name;

  // RECOLHER O TURNO
  firstPos = semicolonPos + 2;

  semicolonPos = textLine.find(";", firstPos);

  string shiftS = textLine.substr(firstPos, semicolonPos - firstPos);
  unsigned int shiftN = stoi(shiftS);

  maxHours = shiftN;


  //RECOLHER O NUMERO MAX DE HORAS
  firstPos = semicolonPos + 2;

  semicolonPos = textLine.find(";", firstPos);

  string maxHoursW = textLine.substr(firstPos, semicolonPos - firstPos);
  unsigned int maxHoursN = stoi(maxHoursW);

  maxWeekWorkingTime = maxHoursN;

  //RECOLHER O NUMERO DE HORAS DE DESCANSO
  firstPos = semicolonPos + 2;

  string restHours = textLine.substr(firstPos);
  unsigned int restHoursN = stoi(restHours);

  minRestTime = restHoursN;
}

Driver::Driver(unsigned int id, string name, unsigned int maxHours, unsigned int maxWeekWorkingTime, unsigned int minRestTime)
{
	this->id = id;
	this->name = name;
	this->maxHours = maxHours;
	this->maxWeekWorkingTime = maxWeekWorkingTime;
	this->minRestTime = minRestTime;
}

//////////////
// get methods
//////////////

unsigned int Driver::getId() const{
  return id;
}

string Driver::getName() const{
  return name;
}

unsigned int Driver::getShiftMaxDuration() const{
  return maxHours;
}

unsigned int Driver::getMaxWeekWorkingTime() const{
  return maxWeekWorkingTime;
}

unsigned int Driver::getMinRestTime() const{
  return minRestTime;
}

vector<Shift> Driver::getShifts() const{
  return shifts;
}

/////////////////
// set methods //
/////////////////
void Driver::setName(string newName)
{
	name = newName;
}
void Driver::setShiftMaxDuration(unsigned int newShiftMaxDuration)
{
	maxHours = newShiftMaxDuration;
}
void Driver::setMaxWeekWorkingTime(unsigned int newMaxWeekWorkingTime)
{
	maxWeekWorkingTime = newMaxWeekWorkingTime;
}
void Driver::setMinRestTime(unsigned int newMinRestTime)
{
	minRestTime = newMinRestTime;
}

bool shiftSortHelper(const Shift &x, const Shift &y)
{
	return x.getStartTime() < y.getStartTime();
}

void Driver::addShift(Shift s)
{
	shifts.push_back(s);

	sort(shifts.begin(), shifts.end(),shiftSortHelper); //Garantir que os turnos estao ordenados
}

/*
Verifica se o condutor atingiu o servi�o m�ximo semanal, e caso contr�rio, lista os per�odos sem trabalho atribuido.
*/
void Driver::checkCompleteService()
{
	int totalTime=0;

	for (int i = 0; i < shifts.size(); i++)
		totalTime += shifts[i].getEndTime() - shifts[i].getStartTime();

	if (totalTime < maxWeekWorkingTime)
	{
		if (totalTime == 0)
		{
			cout << "Tempo inicial: ";
			showTime(convertMinHours(6 * 60));
			cout << "Tempo final: ";
			showTime(convertMinHours(19 * 60 + 24 * 6 * 60));
		}
		else
			for (int i = 0; i < shifts.size()+1; i++)
			{
				cout << "Periodo " << i + 1 << endl;

				cout << "Tempo inicial: ";
				//showTime(convertMinHours());
				cout << "Tempo final: ";
				//showTime(convertMinHours());
			}
	}
	else
		cout << "O condutor atingiu o tempo maximo semanal!" << endl;
}