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
#include <map>
#include "Line.h"
#include "Driver.h"
#include "Bus.h"
#include "Company.h"
#include "Shift.h"

using namespace std;

//Declara��o das constantes de in�cio e fim do servi�o
extern int serviceStartingTime, serviceEndingTime;

extern string linesFileName, driversFileName;

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

//Guardar informa��o
void savingChanges(Company company);

//Gest�o de input
int verifyInput(int low, int high);
bool isNumber(string input);

//Interfaces
void mainUserInterface(Company &company);
void driversInterface(Company &company);
void infoInterface(Company &company);
void searchInterface(Company &company);
void quitOrContinue(Company &company);
void clearScreen();

//Gest�o de condutores
void createDriver(Company &company);
void editDriver(Company &company);
void removeDriver(Company &company);
void changeShift(Company &company, unsigned int id);
void changeMaxHours(Company &company, unsigned int id);
void changeMinRest(Company &company, unsigned int id);
void changeName(Company &company, unsigned int id);

//Pesquisa
void searchStop(Company company);
bool stopExists(string stop);
void routeCalculator(Company company);
int searchStopIndex(vector<string> busStops, string STOP);

//Visualizar informa��o
void stopSchedule(string stop);
void lineSchedule(Company company);
void showMIN(int time);
void dealWITHtime(int &horas, int &minutos);
int verificarLENGTHparagemMAIOR(vector<string> busStops);
Time convertMinHours(int minutes);
void showTime(Time t);
void showShifts(Company company);

#endif //PROG_PART_2_MYTYPES_H
