#pragma once

#include <string>

using namespace std;

typedef struct {
	int hours;
	double minutes;
	string dayOfWeek;
} Time;

Time convertMinHours(int minutes);
void showTime(Time t);
