#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Line.h"
#include "Driver.h"


using namespace std;

class Company{
private:
    string name;
    vector<Driver> drivers;
    vector<Line> lines;
public:
    Company(string name, string driversFile, string linesFile);
    // metodos get
    string getName() const;
    // metodos set
    // outros metodos
    void allocateService(); // funcao que implementa a afectacao de servico
};
