#include <iostream>

using namespace std;

int main()
{
    int a = 5;
    int* p = &a;  // p es un apuntador

    cout << "a = " << a << endl;
    cout << "la dirección de a = " << &a << endl;
    cout << "p = " << p << endl;
    cout << "la dirección de p = " << &p << endl;

    *p = 7;
    ++(*p);
    cout << "a = " << a << endl;
    cout << "*p = " << *p << endl;
    cout << "la dirección de a = " << &a << endl;
    cout << "&a == &(*p) = " << &(*p) << endl;

    return 0;
}