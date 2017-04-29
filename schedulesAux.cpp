#include "myTypes.h"
//associado aos horários
void showMIN(int time) {
    if (time < 10)
        cout <<  setfill('0') << setw(2);}


void dealWITHtime(int &horas, int &minutos){
    while (minutos >= 60){
        horas++;
        minutos -= 60;
    }
}
//util para formaração dos horarios
int verificarLENGTHparagemMAIOR(vector<string> busStops){
    int i=0;
    for (int j = 0; j < busStops.size(); ++j) {
        if(busStops.at(j).length()>i)
            i=busStops.at(j).length();
    }
    return i;
}