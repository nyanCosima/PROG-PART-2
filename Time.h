#pragma once

#include <string>

using namespace std;


typedef struct {
	int hours;
	double minutes;
	string dayOfWeek;
} Time;

Time convertMinHours(int minutes);
int convertHoursMin(Time t);
void showTime(Time t);
