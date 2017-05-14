#include "Bus.h"
#include <iostream>
#include <algorithm>

bool shiftSortHelper(const Shift &x, const Shift &y);

Bus::Bus(unsigned int id, unsigned int driver, unsigned int line){

	lineId = line;
	driverId = driver;
	orderInLine = id;
  
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
void Bus:: showInfo(){
    cout << "Número de ordem: " << orderInLine << endl;
    cout << "ID do condutor; " << driverId << endl;
    cout << "ID da linha: " << lineId << endl;
    for(int i=0;i<schedule.size();i++)
        schedule.at(i).showInfo();
}


void Bus::addShift(Shift s)
{
	schedule.push_back(s);

	sort(schedule.begin(), schedule.end(), shiftSortHelper);
}