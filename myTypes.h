#ifndef PROG_PART_2_MYTYPES_H
#define PROG_PART_2_MYTYPES_H

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <sstream>
#include "Line.h"
#include "Driver.h"
#include "Bus.h"
#include "Company.h"
#include "Shift.h"

using namespace std;

//Declara��o das vari�veis para os nomes dos ficheiros das linhas e dos condutores
extern string driversFileName, linesFileName;

//Declara��o das vari�veis para os vetores de informa��o *EXPERIMENT*
extern vector<Line> linesData;
extern vector<Driver> driversData;

//Declara��o das constantes de in�cio e fim do servi�o
extern int serviceStartingTime, serviceEndingTime;


typedef struct{
    int hours;
    double minutes;
    string dayOfWeek;
} Time;

//Fun��o para possibilitar o uso de carateres portugueses caso o sistema operativo seja o windows
#ifdef _WIN32
#include <windows.h>
#define setPTChar() SetConsoleCP(1252); SetConsoleOutputCP(1252);
#else
#define setPTChar() void
#endif

//Declara��o das fun��es

//Leitura de ficheiros
vector<string> readLines();
vector<string> readDrivers();
vector<Line> storingLinesData(const vector<string> &data);
vector<Driver> storingDriversData(const vector<string> &data);

//Guardar informa��o
void savingLinesData();
void savingDriversData();
void savingChanges();

//Gest�o de input
int verifyInput(int low, int high);
bool isNumber(string input);

//Interfaces
void mainUserInterface();
void driversInterface();
void infoInterface();
void searchInterface();
void quitOrContinue();
void clearScreen();

//Gest�o de condutores
void createDriver();
void editDriver();
void removeDriver();
void changeShift(unsigned int id);
void changeMaxHours(unsigned int id);
void changeMinRest(unsigned int id);
void changeName(unsigned int id);

//Pesquisa
void searchStop();
bool searchStop2(string stop);
bool searchStop3(int lineIndex, string stop);
int searchLineIdentifier(unsigned int id);
int searchDriverIdentifier(unsigned int id);
void routeCalculator();
int searchStopIndex(vector<string> busStops, string STOP);

//Visualizar informa��o
void stopSchedule(string stop);
void lineSchedule();
void showMIN(int time);
void dealWITHtime(int &horas, int &minutos);
int verificarLENGTHparagemMAIOR(vector<string> busStops);
Time convertMinHours(int minutes);
void showTime(Time t);
void showShifts();

#endif //PROG_PART_2_MYTYPES_H
