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

Nodo* inserta_inicio(Nodo* inicio, char data)
{
    Nodo* nuevo = new Nodo;
    nuevo->data = data;
    nuevo->next = inicio;
    return nuevo;
}

int main()
{
    Nodo* a = new Nodo;
    Nodo* b = new Nodo;
    Nodo* c = new Nodo;

    a->data = 'A';
    b->data = 'B';
    c->data = 'C';

    a->next = b;
    b->next = c;
    c->next = nullptr;

    // imprime_lista(a);
    // imprime_lista(a->next->next);

    // cout << longitud(a) << endl;

    // imprime_reversa_lista(a);
    // cout << endl;

    a = inserta_inicio(a, 'X');
    cout << longitud(a) << endl;
    imprime_lista(a);

    delete a;
    a = nullptr;
    delete b;
    b = nullptr;
    delete c;
    c = nullptr;
    return 0;
}