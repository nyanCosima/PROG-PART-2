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


Time convertMinHours(int minutes)
{
    int hours;
    double min;
    string dayOfWeek;
    Time t;
    double temp;

    if(minutes>=0 && minutes<24*60) {
        dayOfWeek = "Segunda";
		min = minutes;
    }
    else if(minutes<2*24*60) {
        dayOfWeek = "Terça";
		min = minutes - 24*60;
    }
    else if(minutes<3*24*60){
        dayOfWeek="Quarta";
		min = minutes - 2*24*60;
	}
    else if(minutes<4*24*60){
        dayOfWeek="Quinta";
		min = minutes - 3*24*60;
	}
    else if(minutes<5*24*60){
        dayOfWeek="Sexta";
		min = minutes - 4*24*60;
	}
    else if(minutes<6*24*60){
        dayOfWeek="Sábado";
		min = minutes - 5*24*60;
	}
    else if(minutes<7*24*60){
        dayOfWeek="Domingo";
		min=minutes-6*24*60;
    }

	temp = (double)min / 60;
	hours = min / 60;
	min = round((temp - min / 60) * 60);

    t.hours=hours;
    t.minutes=min;
    t.dayOfWeek=dayOfWeek;

	return t;
}

void showTime(Time t){
    cout << setprecision(0);

    cout << setfill('0') << setw(2) << t.hours;
    cout << ":";
    cout << setfill('0') << setw(2) << t.minutes;
    cout << " - ";
    cout << t.dayOfWeek << endl;
}