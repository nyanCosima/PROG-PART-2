#include "Bus.h"
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
Mostra informação sobre um autocarro tendo em conta se ele tem turnos atribuidos ou nao.
*/
void Bus:: showInfo(){
	if (driverId == 0)
		cout << "Ainda nao tem trabalho atribuido!" << endl;
	else
		for (int i = 0; i < schedule.size(); i++)
		{
			cout << "Turno " << i + 1 << endl << endl;
			schedule.at(i).showInfo();
		}
}

void Bus::addShift(Shift s)
{
	schedule.push_back(s);
}

/*
Verifica os períodos em que o autocarro não tem condutor atribuído e lista-os.
*/
void Bus::checkBus()
{

}
