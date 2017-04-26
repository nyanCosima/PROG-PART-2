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


//Fun��o para limpar a consola, independentemente do sistema operativo
#ifdef _WIN32
#define clearScreen() system("cls");
#else
#define clearScreen() system("clear");
#endif


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

//Interfaces
void mainUserInterface();
void linesInterface();
void driversInterface();
void schedulesInterface();
void searchInterface();
void quitOrContinue();

//Pesquisa
void searchStop();



#endif //PROG_PART_2_MYTYPES_H
