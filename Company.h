#pragma once

#include "Line.h"
#include "Driver.h"

using namespace std;

class Company{
private:
    string name;
    vector<Driver> drivers;
    vector<Line> lines;
public:
    Company(string name);
    // metodos get
    string getName() const;
	vector<Driver> getDrivers() const;
	vector<Line> getLines() const;
    // metodos set
	void setDrivers(vector<Driver> newDrivers);
	void addDriver(Driver newDriver);
	void removeDriver(int index);
    // outros metodos
    void allocateService(); // funcao que implementa a afectacao de servico
	void routeCalculator(string stop1, string stop2);
	void searchStop(string stop);
	int searchLineIdentifier(unsigned int id);
	int searchDriverIdentifier(unsigned int id);
	void savingLinesData();
	void savingDriversData();
};
