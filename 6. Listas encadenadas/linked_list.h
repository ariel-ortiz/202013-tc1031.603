#pragma once

#include <iostream>

using namespace std;

template<typename T>
class LinkedList {

public:

    LinkedList()
    {
        _sentinel = new Node;
        _sentinel->prev = _sentinel;
        _sentinel->next = _sentinel;
        _count = 0;
    }

    void insert_front(T data)
    {
        Node* new_node = new Node(data);
        new_node->prev = _sentinel;
        _sentinel->next->prev = new_node;
        new_node->next = _sentinel->next;
        _sentinel->next = new_node;
        ++_count;
    }

    void insert_back(T data)
    {

    }

    int size() const
    {
        return _count;
    }

private:

    struct Node {
        Node() {}
        Node(T d): data(d) {}
        T data;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    Node* _sentinel;
    int _count;
};