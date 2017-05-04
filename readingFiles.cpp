#include "myTypes.h"



/*
Lê o ficheiro das linhas e guarda cada fila de informação numa string, adicionando-a num vetor de strings.
*/
vector<string> readLines()
{
    ifstream in_stream;
    string line;
    vector<string> fileContent;

   /* cout << "Insira o nome do ficheiro das linhas: ";
    cin >> linesFileName;*/

    linesFileName = "linhas.txt";

    in_stream.open(linesFileName);

    if (in_stream.fail())
    {
        cerr << "Ficheiro não encontrado. Fechando o programa..." << endl;
        exit(1);
    }

    while (!in_stream.eof())
    {
        getline(in_stream, line);
        if (line == "")
            continue;
        fileContent.push_back(line);
    }

    cout << "Conteudos lidos!" << endl << endl;

    in_stream.close();

    return fileContent;
}

/*
Lê o ficheiro dos condutores e guarda cada fila de informação numa string, adicionando-a num vetor de strings.
*/
vector<string> readDrivers()
{
    ifstream in_stream;
    string line;
    vector<string> fileContent;

    /*cout << "Insira o nome do ficheiro dos condutores: ";
    cin >> driversFileName;*/

    driversFileName="condutores.txt";

    in_stream.open(driversFileName);

    if (in_stream.fail())
    {
        cerr << "Ficheiro não encontrado. Fechando o programa..." << endl;
        exit(1);
    }

    while (!in_stream.eof())
    {
        getline(in_stream, line);
        if (line == "")
            continue;
        fileContent.push_back(line);
    }

    cout << "Conteudos lidos!" << endl << endl;

    in_stream.close();

    return fileContent;
}

/*
Lê o vetor de strings e guarda a informação num vetor de Lines, sendo que cada Line representa uma linha.
*/
vector<Line> storingLinesData(const vector<string> &data)
{
    vector<Line> linesVector;

    for (int i = 0; i < data.size(); i++)
    {
        Line l(data[i]);
        linesVector.push_back(l);
    }

    return linesVector;
}


/*
Lê o vetor de strings e guarda a informação num vetor de Drivers, sendo que cada Driver representa um condutor.
*/
vector<Driver> storingDriversData(const vector<string> &data)
{
    vector<Driver> driversVector;

    for (int i = 0; i < data.size(); i++)
    {
        Driver d(data[i]);
        driversVector.push_back(d);
    }

    return driversVector;
}



