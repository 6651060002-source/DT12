#ifndef SEARCH_SORT_H
#define SEARCH_SORT_H

#include "ContactManager.h"

class SearchSort {
public:
    static Node<Contact>* searchByName(ContactManager& cm, const std::string& keyword) {
        Node<Contact>* curr = cm.contacts.head;
        while (curr) {
            if (curr->data.name.find(keyword) != std::string::npos) {
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    static void sortByName(ContactManager& cm) {
        if (!cm.contacts.head) return;
        bool swapped;
        do {
            swapped = false;
            Node<Contact>* curr = cm.contacts.head;
            while (curr->next) {
                if (curr->data.name > curr->next->data.name) {
                    std::swap(curr->data, curr->next->data);
                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped);
        std::cout << "-> Da sap xep danh ba theo ten (A-Z).\n";
    }
};

#endif