#include "myTypes.h"

void lineSchedule(){

    int linha;
	int indice;
	string input;
	bool validInput = false;

    //receber input do user
	while (!validInput)
	{
		cout << "Indique o id da linha: ";
		getline(cin, input);

		if (input.size() <= 3) //Só são aceites IDs com, no máximo 3 dígitos
		{
			if (isNumber(input)) //Se o input for um número positivo
			{
				indice = searchLineIdentifier(stoi(input)); //Verifica a existência do ID

				if (indice != -1)
					validInput = true;
				else
					cout << "Esse ID não existe! Tente novamente..." << endl;
			}
			else
				cout << "Input inválido! Tente novamente..." << endl;
		}
		else
			cout << "Input inválido! Tente novamente..." << endl;
	}

	linha = stoi(input);

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

    while (horasin < 19) {
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

    for(int i=0;i<linesData.at(indice).getTimings().size();i++)
        minutos2in+=linesData.at(indice).getTimings().at(i);


    dealWITHtime(horas2in,minutos2in);
    horas2=horas2in;
    minutos2=minutos2in;

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
            cout<< setfill(' ') <<setw(s-1)<<  "0" <<  horas2in <<":";
        else
            cout << setfill(' ') <<setw(s)<< horas2in <<":";
        showMIN(minutos2in);
        cout << minutos2in << "|";
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


/*void verHORARIOparagem(string nome) {
    int s;
    int horas = 6, minutos = 0, horasin = 6, minutosin = 0;
    int horas2 = 6, minutos2 = 0, horasin2 = 6, minutosin2 = 0;
    bool validInput=false;
    string input;

    while(!validInput)




    for (int i = 0; i < linesData.size(); ++i) {

        int add = linesData.at(i).getFrequency();
        s = verificarLENGTHparagemMAIOR(linesData.at(i).getBusStops());


        if (searchStopIndex(linesData.at(), i) != -1) {

            cout << "LINHA " << linesData.at(i).id << endl;


            //se for a primeira ou ultima paragem

            if (lalala(nome, i) == 0 || lalala(nome, i) == linesData.at(i).getBusStops().size() - 1)
                //horarioPARAGEMlilhelper(nome, i);


            else {
                cout << string(-1 + (s + 5) * 2, '-') << endl;
                cout << "|-> " << setw(s) << linesData.at(i).getBusStops().at(linesData.at(i).getBusStops().size() - 1) << "|-> "
                     << setw(s) << linesData.at(i).getBusStops().at(0) << "|" << endl;
                cout << "|" << string(1 + (s + 3) * 2, '-') << "|" << endl;

                while (horasin < 19 && horasin2 < 19) {

                    //HORA MAX
                    // horas = horasin;
                    // minutos = minutosin;

                    // /obter a que horas passa sentido 1
                    for (int j = 0; j < lalala(nome, i); ++j) {
                        minutos += linesData.at(i).getTimings().at(j);
                    }
                    dealWITHtime(horas, minutos);
                    if (horas < 10)
                        cout << "|" << setfill(' ') << setw(s - 1) << "0" << horas << ":";
                    else
                        cout << "|" << setfill(' ') << setw(s) << horas << ":";
                    showMIN(minutos);
                    cout << minutos << "|";
                    minutosin += add;
                    dealWITHtime(horasin, minutosin);

                    //de lá para cá
                    horas2 = horasin2;
                    minutos2 = minutosin2;

                    for (int f = linesData.at(i).getTimings().size() - 1; f >= lalala(nome, i); f--) {
                        minutos2 += linesData.at(i).getTimings().at(f);
                    }

                    dealWITHtime(horas2, minutos2);
                    if (horas2 < 10)
                        cout << setfill(' ') << setw(s - 1) << "0" << horas2 << ":";
                    else
                        cout << setfill(' ') << setw(s) << horas2 << ":";
                    showMIN(minutos2);
                    cout << minutos2 << "|" << endl;
                    minutosin2 += add;
                    dealWITHtime(horasin2, minutosin2);
                }
            }
        }
    }
}*/