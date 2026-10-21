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

    void displayAll() {
        Node<Contact>* curr = contacts.head;
        if (!curr) {
            std::cout << "Danh ba rong!\n";
            return;
        }
        std::cout << "\n=== DANH SACH LIEN HE ===\n";
        while (curr) {
            std::cout << "Ten: " << curr->data.name 
                      << " | SĐT: " << curr->data.phone 
                      << " | Email: " << curr->data.email << std::endl;
            curr = curr->next;
        }
    }

    bool deleteContactByPhone(const std::string& phone) {
        Node<Contact>* curr = contacts.head;
        while (curr) {
            if (curr->data.phone == phone) {
                contacts.removeNode(curr);
                std::cout << "-> Da xoa lien he co SĐT: " << phone << std::endl;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
};

#endif