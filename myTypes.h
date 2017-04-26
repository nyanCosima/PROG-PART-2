

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

vector<string> readLines();
vector<string> readDrivers();
vector<Line> storingLinesData(const vector<string> &data);
vector<Driver> storingDriversData(const vector<string> &data);



extern string driversFileName, linesFileName;




#endif //PROG_PART_2_MYTYPES_H
