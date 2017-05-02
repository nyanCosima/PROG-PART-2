#include "myTypes.h"

//Declaração dos nomes dos ficheiros
string driversFileName, linesFileName;

//Declaração dos vetores de informação
vector<Line> linesData;
vector<Driver> driversData;

//Definição das constantes de início e fim de serviço
int serviceStartingTime = 6 * 60, serviceEndingTime = 19 * 60;

int main(){

  vector<string> rawLinesData;
  vector<string> rawDriversData;

  setPTChar(); //Permite o uso de carateres portugueses no input/output

  rawLinesData = readLines();
  rawDriversData = readDrivers();

  linesData = storingLinesData(rawLinesData);
  driversData = storingDriversData(rawDriversData);

  mainUserInterface(); //Invoca a interface principal

  return 0;
}
