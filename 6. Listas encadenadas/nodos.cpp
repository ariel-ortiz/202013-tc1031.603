#include <iostream>

using namespace std;

struct Nodo {
    char   data;
    Nodo*  next;
};


// Time complexity: O(N)
void imprime_lista(Nodo* inicio)
{
    while (inicio != nullptr) {
        cout << inicio->data << " ";
        inicio = inicio->next;
    }
    cout << endl;
}

//  Time complexity: O(N)
void imprime_reversa_lista(Nodo* inicio)
{
    if (inicio != nullptr) {
        imprime_reversa_lista(inicio->next);
        cout << inicio->data << " ";
    }
}

// Time complexity: O(N)
int longitud(Nodo* inicio)
{
    if (inicio == nullptr) {
        return 0;
    } else {
        return 1 + longitud(inicio->next);
    }
}

// Time complexity: O(1)
Nodo* inserta_inicio(Nodo* inicio, char data)
{
    Nodo* nuevo = new Nodo;
    nuevo->data = data;
    nuevo->next = inicio;
    return nuevo;
}

// Time complexity: O(N)
void libera_lista(Nodo* inicio)
{
    while (inicio != nullptr) {
        Nodo* borrar = inicio;
        inicio = inicio->next;
        delete borrar;
        borrar = nullptr;
    }
}

bool existe(Nodo* inicio, char x)
{

}

int main()
{
    Nodo* lst = nullptr;

    lst = inserta_inicio(lst, 'C');
    lst = inserta_inicio(lst, 'B');
    lst = inserta_inicio(lst, 'A');
    lst = inserta_inicio(lst, 'X');

    cout << longitud(lst) << endl;
    imprime_lista(lst);

    libera_lista(lst);
    lst = nullptr;

    return 0;
}