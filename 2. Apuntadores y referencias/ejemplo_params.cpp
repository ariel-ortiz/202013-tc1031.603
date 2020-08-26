#include <iostream>

using namespace std;

void fun(int x, int* p, int& r)
{
    ++x;
    ++(*p);
    ++r;
}

int main()
{
    int a = 5;
    int b = 5;
    int c = 5;
    cout << "antes a = " << a << endl;
    cout << "antes b = " << b << endl;
    cout << "antes c = " << c << endl;

    fun(a, &b, c);
    cout << "después a = " << a << endl;
    cout << "después b = " << b << endl;
    cout << "después c = " << c << endl;
    return 0;
}