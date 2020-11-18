#include <iostream>
#include <vector>
#include "binary_search_tree.h"

using namespace std;

int main()
{
    BinarySearchTree<char> t1;

    t1.insert('F');
    t1.insert('L');
    t1.insert('D');

    BinarySearchTree<int> t2 {5, 7, 3, 1, 4, 10, 9, 8, 6};

    cout << t1.size() << endl;
    cout << t2.size() << endl;

    vector<char> v1;
    vector<int> v2;

    t1.in_order(v1);
    t2.in_order(v2);

    for (char c: v1) {
        cout << c << " ";
    }
    cout << endl;

    for (int i: v2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}