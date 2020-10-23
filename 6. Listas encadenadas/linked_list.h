#pragma once

#include <iostream>
#include <sstream>

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

    ~LinkedList()
    {
        _sentinel->prev->next = nullptr;
        Node* current = _sentinel;
        while (current != nullptr) {
            Node* deleteable = current;
            current = current->next;
            delete deleteable;
            deleteable = nullptr;
        }
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
        Node* new_node = new Node(data);
        new_node->next = _sentinel;
        _sentinel->prev->next = new_node;
        new_node->prev = _sentinel->prev;
        _sentinel->prev = new_node;
        ++_count;
    }

    string to_string() const
    {
        ostringstream oss;
        oss << "[";
        bool first_time = true;
        Node* current = _sentinel->next;
        while (current != _sentinel) {
            if (first_time) {
                first_time = false;
            } else {
                oss << ", ";
            }
            oss << current->data;
            current = current->next;
        }
        oss << "]";
        return oss.str();
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

template<typename T>
ostream& operator<<(ostream& os, const LinkedList<T>& list)
{
    return os << list.to_string();
}