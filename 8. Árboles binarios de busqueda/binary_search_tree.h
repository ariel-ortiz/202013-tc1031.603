#pragma once

#include <iostream>
#include <vector>

template<typename T>
class BinarySearchTree {

public:

    BinarySearchTree() {}

    BinarySearchTree(std::initializer_list<T> args)
    {
        for (T data: args) {
            insert(data);
        }
    }

    // O(N)
    ~BinarySearchTree()
    {
        _destroy(_root);
    }

    // O(log N)
    bool insert(T data)
    {
        if (_root == nullptr) {
            _root = new Node(data);
            ++_count;
            return true;
        } else {
            Node* current = _root;
            while (true) {
                if (data == current->data) {
                    return false;
                } else if (data < current->data) {
                    if (current->left == nullptr) {
                        current->left = new Node(data);
                        ++_count;
                        return true;
                    } else {
                        current = current->left;
                    }
                } else { // data > current->data
                    if (current->right == nullptr) {
                        current->right = new Node(data);
                        ++_count;
                        return true;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    // O(1)
    int size()
    {
        return _count;
    }

    // Time complexity: O(N)
    // Space complexity: O(N)
    void in_order(std::vector<T>& result)
    {
        _in_order(_root, result);
    }

    void pre_order(std::vector<T>& result)
    {
        _pre_order(_root, result);
    }

    void post_order(std::vector<T>& result)
    {
        _post_order(_root, result);
    }

private:

    struct Node {
        Node() {}
        Node(T d): data(d) {}
        T data;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    void _destroy(Node* current)
    {
        if (current != nullptr) {
            _destroy(current->left);
            _destroy(current->right);
            delete current;
            current = nullptr;
        }
    }

    void _in_order(Node* current, std::vector<T>& result)
    {
        if (current != nullptr)
        {
            _in_order(current->left, result);
            result.push_back(current->data);
            _in_order(current->right, result);
        }
    }

    void _pre_order(Node* current, std::vector<T>& result)
    {
        if (current != nullptr)
        {
            result.push_back(current->data);
            _pre_order(current->left, result);
            _pre_order(current->right, result);
        }
    }

    void _post_order(Node* current, std::vector<T>& result)
    {
        if (current != nullptr)
        {
            _post_order(current->left, result);
            _post_order(current->right, result);
            result.push_back(current->data);
        }
    }

    Node* _root = nullptr;
    int _count = 0;
};