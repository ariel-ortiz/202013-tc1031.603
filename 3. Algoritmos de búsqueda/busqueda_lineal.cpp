#include <iostream>
#include <vector>

using namespace std;

// Algoritmo con complejidad de tiempo de ejecución O(N).
template<typename T>
int linear_search(vector<T> vec, T value)
{
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == value) {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> a {5, 7, -9, 2, 10, -5, 8, 1, 0, 2, 13, 20, -99};
    vector<double> b {3.1, 13.0, 42.5};
    vector<string> c {"enero", "febrero", "marzo", "abril", "mayo", "junio"};
    int x = linear_search(a, 2);
    cout << "El 2 está en el índice " << x << endl;
    x = linear_search(b, 13.0);
    cout << "El 13.0 está en el índice " << x << endl;
    string mes = "julio";
    x = linear_search(c, mes);
    cout << "\"julio\" está en el índice " << x << endl;
}