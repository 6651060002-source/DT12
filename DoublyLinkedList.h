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
        if (!node) return ;

        // Cập nhật con trỏ phía trước
        if (node->prev) {
            node->prev->next = node->next;
        } else {
            head = node->next; // Nếu node bị xóa là head
        }

        // Cập nhật con trỏ phía sau
        if (node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev; // Nếu node bị xóa là tail
        }

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