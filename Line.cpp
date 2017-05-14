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
Calcula o n�mero de autocarros necess�rios para cobrir o servi�o de uma dada linha.
*/
int Line::numberOfBuses() const
{
	int	n = (int)((double) 2*totalDuration()/frequency + 1.0);

	return n;
}

/*
Calcula a dura��o total de um percurso de uma linha(apenas um sentido, para saber quanto demora at� voltar ao in�cio
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
Devolve true se a paragem existir na linha, e false no caso contr�rio.
*/
bool Line::searchStop(string stop) const
{
	for (int i = 0; i < busStopList.size(); i++)
		if (busStopList[i] == stop)
			return true;

	return false;
}

int Line::searchStop2(string stop) const {
    for (int i = 0; i < busStopList.size(); i++)
        if (busStopList[i] == stop)
            return i;

    return -1;
}

void Line::schedule() const
{
    int count =0;
	int s = verificarLENGTHparagemMAIOR(busStopList);
	int horas = 6, minutos = 0, minutosin = 0, horasin = 6;
	int add = frequency;
	cout << string(1000, '\n');
	cout << " HORÁRIO EM DIREÇÃO A: " << busStopList.at(busStopList.size() - 1) << endl;

	cout << string(busStopList.size()*(s + 3) + 5, '-') << endl;
	for (int i = 0; i < busStopList.size(); ++i) {
		cout << '|' << setfill(' ') << setw(s) << left << busStopList.at(i) << "   " << right;
	}
	cout << "|" << endl;
	cout << "|" << string(busStopList.size()*(s + 3) + 3, '-') << '|' << endl;

	while (horasin < 19) {
		//hora incial de sa�da
		cout << "|";
		if (horasin <10)
			cout << setfill(' ') << setw(s - 1) << "0" << horasin << ":";
		else
			cout << setfill(' ') << setw(s) << horasin << ":";
		showMIN(minutosin);
		cout << minutosin << "|";
		minutos = minutosin;                                                     //comea�ar da nova hora
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
        count++;
	}
	cout << string(busStopList.size()*(s + 3) + 5, '-') << endl;


	//de l� para c�


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



	while (count>0) {
		//hora incial
		cout << "|";
		if (horas2in <10)
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
        count --;
	}
	cout << string(busStopList.size()*(s + 3) + 5, '-') << endl;
	cin.ignore(1000, '\n');
}


void Line::stopsSchedule(string stop) const
{
    int s;
    int horas = 6, minutos = 0, horasin = 6, minutosin = 0;
    int horas2 = 6, minutos2 = 0, horasin2 = 6, minutosin2 = 0;


            int add = frequency;
            s = verificarLENGTHparagemMAIOR(busStopList);


                cout << "LINHA " << id << endl;


                //se for a primeira ou ultima paragem

                if (searchStop2(stop) == 0 || searchStop2(stop) == busStopList.size() - 1) {
                    horarioPARAGEMlilhelper(stop,searchStop2(stop));
                }

                else {
                    cout << string(-1 + (s + 5) * 2, '-') << endl;
                    cout << "|-> " << setw(s) << busStopList.at(busStopList.size() - 1) << "|-> "
                         <<setfill(' ') <<  setw(s) << busStopList.at(0) << "|" << endl;
                    cout << "|" << string(1 + (s + 3) * 2, '-') << "|" << endl;

                    while (horasin < 19) {

                        horas = horasin;
                        minutos = minutosin;


                        // /obter a que horas passa sentido 1
                        for (int j = 0; j < searchStop2(stop); ++j) {
                            minutos += timesList.at(j);
                        }
                        dealWITHtime(horas, minutos);
                        if (horas < 10)
                            cout << "|" << setfill(' ') << setw(s - 1) << "0" << horas << ":";
                        else
                            cout << "|" << setfill(' ') << setw(s) << horas << ":";
                        showMIN(minutos);
                        cout << minutos << "|";
                        minutosin += add;
                        dealWITHtime(horasin, minutosin);

                        //de lá para cá
                        horas2 = horasin2;
                        minutos2 = minutosin2;

                        for (int f = timesList.size() - 1; f >= searchStop(stop); f--) {
                            minutos2 += timesList.at(f);
                        }

                        dealWITHtime(horas2, minutos2);
                        if (horas2 < 10)
                            cout << setfill(' ') << setw(s - 1) << "0" << horas2 << ":";
                        else
                            cout << setfill(' ') << setw(s) << horas2 << ":";
                        showMIN(minutos2);
                        cout << minutos2 << "|" << endl;
                        minutosin2 += add;
                        dealWITHtime(horasin2, minutosin2);

                    }
                }
            }



void Line::horarioPARAGEMlilhelper(string stop,int i) const
{

    int s;
    int horas = 6, minutos = 0, horasin = 6, minutosin = 0;
    int horas2 = 6, minutos2 = 0, horasin2 = 6, minutosin2 = 0;

    int add = frequency;

    s= stop.length();

    cout << string(s+5, '-') << endl;
    cout << "|-> " << setw(s) << busStopList.at(i)  << "|" << endl;
    cout << "|" << string(s+3, '-') << "|" << endl;

    do{

        horas = horasin;
        minutos = minutosin;

        for (int j = 0; j < searchStop(stop); ++j) {
            minutos += timesList.at(j);
        }

        dealWITHtime(horas, minutos);
        if (horas < 10)
            cout << "|" << setfill(' ') << setw(s - 1) << "0" << horas << ":";
        else
            cout << "|" << setfill(' ') << setw(s) << horas << ":";
        showMIN(minutos);
        cout << minutos << "|" << endl;
        minutosin += add;
        dealWITHtime(horasin, minutosin);}while (horasin < 19);

    if(i!=0){
        horas = horasin;
    minutos = minutosin;

    for (int j = 0; j < searchStop(stop); ++j) {
        minutos += timesList.at(j);
    }

    dealWITHtime(horas, minutos);
    if (horas < 10)
        cout << "|" << setfill(' ') << setw(s - 1) << "0" << horas << ":";
    else
        cout << "|" << setfill(' ') << setw(s) << horas << ":";
    showMIN(minutos);
    cout << minutos << "|" << endl;
    minutosin += add;
    dealWITHtime(horasin, minutosin);}




    cout  << string(s+5, '-')  << endl;
}