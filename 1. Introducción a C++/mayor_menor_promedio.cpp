#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int mayor;
    int menor;
    double suma = 0.0;
    int n = 0;
    bool primera_vez = true;
    int dato;

    do {
        cout << "Dame un entero (-1 para terminar): ";
        cin >> dato;
        if (dato != -1) {
            if (primera_vez) {
                mayor = menor = dato;
                primera_vez = false;
            } else if (dato > mayor) {
                mayor = dato;
            } else if (dato < menor) {
                menor = dato;
            }
            suma += dato;
            ++n;
        }
    } while (dato != -1);

    if (n > 0) {
        cout << "Mayor: " << mayor << endl;
        cout << "Menor: " << menor << endl;
        cout << fixed << setprecision(2);
        cout << "Promedio: " << (suma / n) << endl;
    }
}

