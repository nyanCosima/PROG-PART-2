#include "Line.h"
#include <iostream>
#include <iomanip>

int verificarLENGTHparagemMAIOR(vector<string> busStops);
void dealWITHtime(int &horas, int &minutos);
void showMIN(int time);

Line::Line(string textLine){

  // INITIALISATION CODE GOES IN HERE

  //RECOLHER O ID
  int firstPos = 0;

  int semicolonPos = textLine.find(";", firstPos);

  string ids = textLine.substr(firstPos, semicolonPos - firstPos);
  unsigned int idN = stoi(ids);

  id = idN;

  //RECOLHER A FREQUENCIA
  firstPos = semicolonPos + 2;

  semicolonPos = textLine.find(";", firstPos);

  string frequencyS = textLine.substr(firstPos, semicolonPos - firstPos);
  unsigned int freq = stoi(frequencyS);

  frequency = freq;

  // RECOLHER AS PARAGENS

  firstPos = semicolonPos + 2;
  semicolonPos = textLine.find(";", firstPos);
  int commaPos = textLine.find(",", firstPos);
  while (commaPos < semicolonPos)
  {
    string stop = textLine.substr(firstPos, commaPos - firstPos);

    busStopList.push_back(stop);

    firstPos = commaPos + 2;
    commaPos = textLine.find(",", firstPos);
  }
  //Extrai ultima paragem
  string stop = textLine.substr(firstPos, semicolonPos - firstPos);
  busStopList.push_back(stop);

  // RECOLHER AS DURACOES

  firstPos = semicolonPos + 2;
  commaPos = textLine.find(",", firstPos);
  while (commaPos < textLine.length())
  {
    string duration = textLine.substr(firstPos, commaPos - firstPos);

    int dur = stoi(duration);

    timesList.push_back(dur);

    firstPos = commaPos + 2;
    commaPos = textLine.find(",", firstPos);
  }
  //Extrai ultima duracao
  string duration = textLine.substr(firstPos, commaPos - firstPos);

  int dur = stoi(duration);
  timesList.push_back(dur);

}

Line::Line(unsigned int id, unsigned int frequency, vector<string> busStopsList, vector<int> timesList)
{
	this->id = id;
	this->frequency = frequency;
	this->busStopList = busStopsList;
	this->timesList = timesList;
}
////////////////
// get methods
////////////////

unsigned int Line::getId() const{
  return id;
}

unsigned int Line::getFrequency() const{
    return frequency;
}

vector<string> Line::getBusStops() const{
  return busStopList;
}

vector<int> Line::getTimings() const{
  return timesList;
}


//set methods

void Line::setFrequency(unsigned int newFrequency)
{
	frequency = newFrequency;
}

void Line::setBusStops(vector<string> newStopsList)
{
	busStopList = newStopsList;
}

void Line::setTimings(vector<int> newTimings)
{
	timesList = newTimings;
}


//other methods

/*
Calcula o número de autocarros necessários para cobrir o serviço de uma dada linha.
*/
int Line::numberOfBuses() const
{
	int	n = (int)((double) 2*totalDuration()/frequency + 1.0);

	return n;
}

/*
Calcula a duração total de um percurso de uma linha(apenas um sentido, para saber quanto demora até voltar ao início
basta calcular o dobro)
*/
int Line::totalDuration() const
{
	int duration = 0;

	for (int i = 0; i < timesList.size(); i++)
		duration += timesList[i];

	return duration;
}

/*
Devolve true se a paragem existir na linha, e false no caso contrário.
*/
bool Line::searchStop(string stop) const
{
	for (int i = 0; i < busStopList.size(); i++)
		if (busStopList[i] == stop)
			return true;

	return false;
}

void Line::schedule() const
{
	int s = verificarLENGTHparagemMAIOR(busStopList);
	int horas = 6, minutos = 0, minutosin = 0, horasin = 6;
	int add = frequency;
	cout << string(1000, '\n');
	cout << " HORÁRIO EM DIREÇÃO A: " << busStopList.at(busStopList.size() - 1) << endl;

	cout << string(busStopList.size()*(s + 3) + 5, '-') << endl;
	for (int i = 0; i < busStopList.size(); ++i) {
		cout << '|' << setw(s) << left << busStopList.at(i) << "   " << right;
	}
	cout << "|" << endl;
	cout << "|" << string(busStopList.size()*(s + 3) + 3, '-') << '|' << endl;

	while (horasin < 19) {
		//hora incial de saída
		cout << "|";
		if (horasin <10)
			cout << setfill(' ') << setw(s - 1) << "0" << horasin << ":";
		else
			cout << setfill(' ') << setw(s) << horasin << ":";
		showMIN(minutosin);
		cout << minutosin << "|";
		minutos = minutosin;                                                     //comeaçar da nova hora
		horas = horasin;

		//calcular horas restantes
		for (int j = 0; j < timesList.size(); ++j) {
			minutos += timesList.at(j);
			dealWITHtime(horas, minutos);
			if (horas <10) {
				cout << setfill(' ') << setw(s - 1) << "0" << horas << ":";
			}
			else {
				cout << setfill(' ') << setw(s) << horas << ":";
			}
			showMIN(minutos);
			cout << minutos << "|";
		}
		cout << endl;
		minutosin += add;                                                       //nova hora incial
		dealWITHtime(horasin, minutosin);
	}
	cout << string(busStopList.size()*(s + 3) + 5, '-') << endl;


	//de lá para cá


	int horas2 = 6, minutos2 = 0, horas2in = 6, minutos2in = 0;

	for (int i = 0; i<timesList.size(); i++)
		minutos2in += timesList.at(i);


	dealWITHtime(horas2in, minutos2in);
	horas2 = horas2in;
	minutos2 = minutos2in;

	cout << string(3, '\n');
	cout << " HORÁRIO EM DIREÇÃO A: " << busStopList.at(0) << endl;


	cout << string(busStopList.size()*(s + 3) + 5, '-') << endl;
	for (int w = busStopList.size() - 1; w >= 0; w--) {
		cout << "|" << setfill(' ') << setw(s) << left << busStopList.at(w) << "   " << right;
	}
	cout << "|" << endl;
	cout << "|" << string(busStopList.size()*(s + 3) + 3, '-') << '|' << endl;



	while (horas2 < 19) {
		//hora incial
		cout << "|";
		if (horas2 <10)
			cout << setfill(' ') << setw(s - 1) << "0" << horas2in << ":";
		else
			cout << setfill(' ') << setw(s) << horas2in << ":";
		showMIN(minutos2in);
		cout << minutos2in << "|";
		horas2 = horas2in;
		minutos2 = minutos2in;

		//calcular horas restantes
		for (int k = busStopList.size() - 2; k >= 0; k--) {
			minutos2 += timesList.at(k);
			dealWITHtime(horas2, minutos2);
			if (horas2 <10)
				cout << setfill(' ') << setw(s - 1) << "0" << horas2 << ":";
			else
				cout << setfill(' ') << setw(s) << horas2 << ":";
			showMIN(minutos2);
			cout << minutos2 << "|";
		}
		cout << endl;
		minutos2in += add;
		dealWITHtime(horas2in, minutos2in);
	}
	cout << string(busStopList.size()*(s + 3) + 5, '-') << endl;
	cin.ignore(1000, '\n');
}