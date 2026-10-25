#ifndef CONTACT_MANAGER_H
#define CONTACT_MANAGER_H

#include <string>
#include <iostream>
#include "DoublyLinkedList.h"

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

class ContactManager {
public:
    DoublyLinkedList<Contact> contacts;

    void addContact(const std::string& name, const std::string& phone, const std::string& email) {
        contacts.pushBack({name, phone, email});
        std::cout << "-> Da them lien he: " << name << std::endl;
    }

    // Duyệt xuôi A-Z (Head -> Tail)
    void displayAll() {
        Node<Contact>* curr = contacts.head;
        if (!curr) {
            std::cout << "Danh ba rong!\n";
            return;
        }
        std::cout << "\n=== DANH SACH LIEN HE (A-Z) ===\n";
        while (curr) {
            std::cout << "Ten: " << curr->data.name 
                      << " | SDT: " << curr->data.phone 
                      << " | Email: " << curr->data.email << std::endl;
            curr = curr->next;
        }
    }

    // Duyệt ngược Z-A (Tail -> Head)
    void displayReverse() {
        Node<Contact>* curr = contacts.tail;
        if (!curr) {
            std::cout << "Danh ba rong!\n";
            return;
        }
        std::cout << "\n=== DANH SACH LIEN HE (Z-A) ===\n";
        while (curr) {
            std::cout << "Ten: " << curr->data.name 
                      << " | SDT: " << curr->data.phone 
                      << " | Email: " << curr->data.email << std::endl;
            curr = curr->prev;
        }
    }

    bool deleteContactByPhone(const std::string& phone) {
        Node<Contact>* curr = contacts.head;
        while (curr) {
            if (curr->data.phone == phone) {
                contacts.removeNode(curr);
                std::cout << "-> Da xoa lien he co SDT: " << phone << std::endl;
                return true;
            }
            curr = curr->next;
        }
        std::cout << "-> Khong tim thay SDT: " << phone << std::endl;
        return false;
    }
};

#endif