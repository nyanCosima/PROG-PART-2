#include "Driver.h"

Driver::Driver(string textLine){

  // INITIALISATION CODE GOES IN HERE
  //RECOLHER O ID
  int firstPos = 0;

  int semicolonPos = textLine.find(";", firstPos);

  string ids = textLine.substr(firstPos, semicolonPos - firstPos);
  int idN = stoi(ids);

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
  int shiftN = stoi(shiftS);

  maxHours = shiftN;


  //RECOLHER O NUMERO MAX DE HORAS
  firstPos = semicolonPos + 2;

  semicolonPos = textLine.find(";", firstPos);

  string maxHoursW = textLine.substr(firstPos, semicolonPos - firstPos);
  int maxHoursN = stoi(maxHoursW);

  maxWeekWorkingTime = maxHoursN;

  //RECOLHER O NUMERO DE HORAS DE DESCANSO
  firstPos = semicolonPos + 2;

  string restHours = textLine.substr(firstPos);
  int restHoursN = stoi(restHours);

  minRestTime = restHoursN;




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
