#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Pais {
    string nombre;
    int oro;
    int plata;
    int bronce;
};

bool compa(const Pais& a, const Pais& b)
{
    return a.oro > b.oro;
}

int main(int argc, const char* argv[])
{
    if (argc != 2) {
        cerr << "Favor de indicar el nombre del archivo de entrada.\n";
        exit(1);
    }

    string nombre_archivo = argv[1];
    ifstream entrada(nombre_archivo);
    if (entrada.fail()) {
        cerr << "Error al intentar abrir archivo.\n";
        exit(1);
    }

    string linea;
    vector<Pais> info;
    while (getline(entrada, linea)) {
        istringstream iss(linea);
        Pais p;
        iss >> p.nombre;
        iss >> p.oro;
        iss >> p.plata;
        iss >> p.bronce;
        info.push_back(p);
    }
    entrada.close();

    sort(info.begin(), info.end(), compa);

    for (Pais p: info) {
        cout << p.nombre << " "
            << p.oro << " "
            << p.plata << " "
            << p.bronce << endl;
    }

    return 0;
}
