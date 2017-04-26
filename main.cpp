#include "myTypes.h"

//Declaração dos nomes dos ficheiros
string driversFileName, linesFileName;


int main(){

  vector<string> rawLinesData;
  vector<string> rawDriversData;
  vector<Line> storedLinesData;
  vector<Driver> storedDriversData;

  rawLinesData = readLines();
  rawDriversData = readDrivers();

  storedLinesData = storingLinesData(rawLinesData);
  storedDriversData = storingDriversData(rawDriversData);

  return 0;
}
