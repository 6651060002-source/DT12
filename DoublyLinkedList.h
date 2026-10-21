#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
public:
    Node<T>* head;
    Node<T>* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() { clear(); }

    void pushBack(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void removeNode(Node<T>* node) {
        if (!node) return;
        if (node == head) head = head->next;
        if (node == tail) tail = tail->prev;
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        delete node;
    }

    void clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
    }
};

#endif