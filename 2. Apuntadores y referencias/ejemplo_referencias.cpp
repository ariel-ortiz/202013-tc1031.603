#include <iostream>

using namespace std;


int main()
{
    int a = 5;
    int& b = a;  // b es una referencia de a (b es un alias de a)

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    b = 42;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "&a = " << &a << endl;
    cout << "&b = " << &b << endl;

    return 0;
}