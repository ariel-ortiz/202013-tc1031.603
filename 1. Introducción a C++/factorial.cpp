#include <iostream>

using namespace std;

int factorial(int n)
{
    int resultado = 1;
    int i = 1;
    while (i <= n) {
        resultado *= i;
        ++i;
    }
    return resultado;
}

int main()
{
    int dato;
    cout << "Dame un entero positivo: ";
    cin >> dato;

    int resultado = factorial(dato);
    cout << "El resultado del factorial de "
        << dato
        << " es: "
        << resultado << endl;
    return 0;
}
