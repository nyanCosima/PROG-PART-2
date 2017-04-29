#include "myTypes.h"

void lineSchedule(){

    int linha;

    //receber input do user
    cout << "Indique o id da linha: ";
    cin >>linha;
    int indice = searchLineIdentifier(linha);

    int s=verificarLENGTHparagemMAIOR(linesData.at(indice).getBusStops());
    int horas = 6, minutos = 0, minutosin = 0, horasin =6;
    int add = linesData.at(indice).getFrequency();
    cout << string(1000, '\n');
    cout << " HORÁRIO EM DIREÇÃO A: " << linesData.at(indice).getBusStops().at(linesData.at(indice).getBusStops().size() - 1) << endl;

    cout << string(linesData.at(indice).getBusStops().size()*(s+3)+5, '-')<< endl;
    for (int i = 0; i < linesData.at(indice).getBusStops().size(); ++i) {
        cout <<'|' << setw(s) <<left<< linesData.at(indice).getBusStops().at(i) << "   " << right;
    }
    cout << "|" << endl;
    cout <<"|"<< string(linesData.at(indice).getBusStops().size()*(s+3)+3, '-') << '|' << endl;

    while (horas < 19) {
        //hora incial de saída
        cout <<"|";
        if(horasin <10)
            cout<< setfill(' ') <<setw(s-1)<<  "0" <<  horasin <<":";
        else
            cout << setfill(' ') <<setw(s)<< horasin <<":";
        showMIN(minutosin);
        cout << minutosin << "|";
        minutos = minutosin;                                                     //comeaçar da nova hora
        horas = horasin;

        //calcular horas restantes
        for (int j = 0; j < linesData.at(indice).getTimings().size(); ++j) {
            minutos += linesData.at(indice).getTimings().at(j);
            dealWITHtime(horas, minutos);
            if(horas <10) {
                cout << setfill(' ') << setw(s - 1) << "0" << horas << ":";
            }else{
                cout << setfill(' ') <<setw(s)<< horas <<":";}
            showMIN(minutos);
            cout << minutos << "|";
        }
        cout << endl;
        minutosin += add;                                                       //nova hora incial
        dealWITHtime(horasin, minutosin);
    }
    cout << string(linesData.at(indice).getBusStops().size()*(s+3)+5, '-')<< endl;


    //de lá para cá
    int horas2 = 6, minutos2 = 0, horas2in=6, minutos2in =0;
    cout << string(3, '\n');
    cout << " HORÁRIO EM DIREÇÃO A: " << linesData.at(indice).getBusStops().at(0) << endl;


    cout << string(linesData.at(indice).getBusStops().size()*(s+3)+5, '-')<< endl;
    for (int w = linesData.at(indice).getBusStops().size()-1; w >=0; w--) {
        cout <<"|"  << setfill(' ')<< setw(s) <<left <<  linesData.at(indice).getBusStops().at(w) << "   "  <<right;
    }
    cout << "|" << endl;
    cout <<"|"<< string(linesData.at(indice).getBusStops().size()*(s+3)+3, '-') << '|' << endl;



    while (horas2 < 19) {
        //hora incial
        cout <<"|";
        if(horas2 <10)
            cout<< setfill(' ') <<setw(s-1)<<  "0" <<  horas2 <<":";
        else
            cout << setfill(' ') <<setw(s)<< horas2 <<":";
        showMIN(minutos2);
        cout << minutos2 << "|";
        horas2 = horas2in;
        minutos2 = minutos2in;

        //calcular horas restantes
        for (int k = linesData.at(indice).getBusStops().size()-2; k >= 0; k--) {
            minutos2 += linesData.at(indice).getTimings().at(k);
            dealWITHtime(horas2, minutos2);
            if(horas2 <10)
                cout<< setfill(' ') <<setw(s-1)<<  "0" <<  horas2 <<":";
            else
                cout << setfill(' ') <<setw(s)<< horas2 <<":";
            showMIN(minutos2);
            cout <<  minutos2 << "|";
        }
        cout << endl;
        minutos2in += add;
        dealWITHtime(horas2in, minutos2in);
    }
    cout << string(linesData.at(indice).getBusStops().size()*(s+3)+5, '-')<< endl;
    cin.ignore(1000,'\n');

}