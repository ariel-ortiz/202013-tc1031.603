#pragma once

#include <iostream>
#include <sstream>

template<typename T>
class LinkedList {

public:

    // O(1)
    LinkedList()
    {
        _sentinel = new Node;
        _sentinel->prev = _sentinel;
        _sentinel->next = _sentinel;
        _count = 0;
    }

    // O(N)
    LinkedList(std::initializer_list<T> args): LinkedList()
    {
        for (T data: args) {
            insert_back(data);
        }
    }

    LinkedList(const LinkedList<T>&) = delete;
    LinkedList<T>& operator=(const LinkedList<T>&) = delete;

    // O(N)
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

    // O(1)
    void insert_front(T data)
    {
        Node* new_node = new Node(data);
        new_node->prev = _sentinel;
        _sentinel->next->prev = new_node;
        new_node->next = _sentinel->next;
        _sentinel->next = new_node;
        ++_count;
    }

    // O(1)
    void insert_back(T data)
    {
        Node* new_node = new Node(data);
        new_node->next = _sentinel;
        _sentinel->prev->next = new_node;
        new_node->prev = _sentinel->prev;
        _sentinel->prev = new_node;
        ++_count;
    }

    // O(N)
    std::string to_string() const
    {
        std::ostringstream oss;
        oss << "[";
        bool first_time = true;

        for (T data: *this) {
            if (first_time) {
                first_time = false;
            } else {
                oss << ", ";
            }
            oss << data;
        }
        oss << "]";
        return oss.str();
    }

    // O(1)
    int size() const
    {
        return _count;
    }

    bool is_empty() const
    {
        return size() == 0;
    }

private:

    //---------------------------------------------------------------
    struct Node {
        Node() {}
        Node(T d): data(d) {}
        T data;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

    //---------------------------------------------------------------
    class ListIterator {

    public:

        ListIterator(Node* current)
        {
            _current = current;
        }

        T operator*() const
        {
            return _current->data;
        }

        void operator++()
        {
            _current = _current->next;
        }

        bool operator!=(const ListIterator& other)
        {
            return _current != other._current;
        }

    private:

        Node* _current;
    };

    //---------------------------------------------------------------

    Node* _sentinel;
    int _count;

public:

    ListIterator begin() const
    {
        return ListIterator(_sentinel->next);
    }

    ListIterator end() const
    {
        return ListIterator(_sentinel);
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
{
    return os << list.to_string();
}