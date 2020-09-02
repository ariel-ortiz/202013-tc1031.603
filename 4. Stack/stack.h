/*
 * Archivo de encabezado para el TDA (tipo de dato abstracto)
 * que representa una pila LIFO (last-in first-out).
 */

 #pragma once

 #include <iostream>

 using namespace std;

 const int max_stack = 10;

 template<typename T>
 class Stack {

 public:

    void push(T obj)
    {
        if (_level == max_stack) {
            throw overflow_error("Stack overflow.");
        }
        _info[_level] = obj;
        ++_level;
    }

    T pop()
    {
        if (is_empty()) {
            throw underflow_error("Stack underflow.");
        }
        --_level;
        return _info[_level];
    }

    int size() const
    {
        return _level;
    }

    bool is_empty() const
    {
        return size() == 0;
    }

 private:
    T _info[max_stack] {};
    int _level {};
 };
