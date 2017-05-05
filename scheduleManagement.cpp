#include "myTypes.h"
#include "Company.h"
#include <string>
#include <iostream>

using namespace std;

bool isNumber(string input);

void lineSchedule(Company company){

	int indice;
	string input;
	bool validInput = false;

    //receber input do user
	while (!validInput)
	{
		cout << "Indique o ID da linha: ";
		getline(cin, input);

		if (input.size() <= 3) //Só são aceites IDs com, no máximo 3 dígitos
		{
			if (isNumber(input)) //Se o input for um número positivo
			{
				indice = company.searchLineIdentifier(stoi(input)); //Verifica a existência do ID

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

	company.getLines()[indice].schedule();
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