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
    cout << int_list << endl;

    cout << int_list.size() << endl;

    LinkedList<string> str_list {"gorila", "chimpancé", "mandril"};
    cout << str_list.size() << endl;

    for (string s: str_list) {
        cout << s << endl;
    }

    cout << str_list << endl;

    LinkedList<char> char_list {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    cout << char_list << endl;
    cout << char_list.size() << endl;
    // while (!char_list.is_empty()) {
    //     char_list.remove_front();
    //     cout << char_list << endl;
    // }

    return 0;
}