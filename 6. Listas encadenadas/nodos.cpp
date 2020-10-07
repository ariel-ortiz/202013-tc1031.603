#include <iostream>

using namespace std;

struct Nodo {
    char   data;
    Nodo*  next;
};

void imprime_lista(Nodo* inicio)
{
    while (inicio != nullptr) {
        cout << inicio->data << " ";
        inicio = inicio->next;
    }
    cout << endl;
}

void imprime_reversa_lista(Nodo* inicio)
{
    if (inicio != nullptr) {
        imprime_reversa_lista(inicio->next);
        cout << inicio->data << " ";
    }
}

int longitud(Nodo* inicio)
{
    int resultado = 0;
    while (inicio != nullptr) {
        ++resultado;
        inicio = inicio->next;
    }
    return resultado;
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

    imprime_lista(a);
    imprime_lista(a->next->next);

    cout << longitud(a) << endl;

    imprime_reversa_lista(a);
    cout << endl;

    delete a;
    delete b;
    delete c;
    return 0;
}