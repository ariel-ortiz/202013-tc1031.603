#include <iostream>
#include "linked_list.h"

using namespace std;

int main()
{
    LinkedList<int> int_list;
    cout << int_list.size() << endl;

    int_list.insert_front(1);
    int_list.insert_front(2);
    int_list.insert_front(3);
    int_list.insert_back(4);
    int_list.insert_back(5);
    int_list.insert_back(6); // 3 2 1 4 5 6

    cout << int_list.size() << endl;

    return 0;
}