#pragma once

#include <iostream>
#include <string>
#include <vector>



using namespace std;

class Line{
 private:
  unsigned int id;
  unsigned int frequency;
  vector<string> busStopList;
  vector<int> timesList;
 public:
  Line(string textLine);
  Line(unsigned int id, unsigned int frequency, vector<string> busStopsList, vector<int> timesList);
  // metodos get
  unsigned int getId() const;
  unsigned int getFrequency() const;
  vector<string> getBusStops() const;
  vector<int> getTimings() const;
  // set methods
  void setFrequency(unsigned int newFrequency);
  void setBusStops(vector<string> newStopsList);
  void setTimings(vector<int> newTimings);
  // other methods
  int numberOfBuses() const;
  int totalDuration() const;

};
