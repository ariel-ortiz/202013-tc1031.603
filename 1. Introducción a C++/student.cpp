#include <iostream>

using namespace std;

class Student {

public:
    Student(int id, string name, string major, int age)
    {
        _id = id;
        _name = name;
        _major = major;
        _age = age;
    }

    int get_id()
    {
        return _id;
    }

    string get_name()
    {
        return _name;
    }

    string get_major()
    {
        return _major;
    }

    int get_age()
    {
        return _age;
    }

    void print()
    {
        cout << "Hello, my name is " << _name << ". I study "
            << _major << " and I'm " << _age << ".\n";
    }

private:
    int _id;
    string _name;
    string _major;
    int _age;
};

int main()
{
    Student s1 {123, "Juan", "ITC", 19};
    Student s2 {199, "María", "IRS", 18};
    Student s3 {201, "Penelope", "ITD", 20};

    cout << s1.get_name() << endl;
    cout << s2.get_major() << endl;
    cout << s3.get_age() << endl;
    s1.print();
    s2.print();
    s3.print();
}
