#ifndef SEARCH_SORT_H
#define SEARCH_SORT_H

#include <iostream>
#include <algorithm>
#include "ContactManager.h"

class SearchSort {
public:
    // Tìm kiếm liên hệ bắt đầu bằng tiền tố (Prefix Search - Đúng chuẩn đề tài ĐT12)
    static void searchByPrefix(ContactManager& cm, const std::string& prefix) {
        Node<Contact>* curr = cm.contacts.head;
        bool found = false;
        std::cout << "\n=== KET QUA TIM KIEM THEO TIEN TO: \"" << prefix << "\" ===\n";

        while (curr) {
            // Kiểm tra xem tên có bắt đầu bằng prefix hay không (rfind vị trí 0)
            if (curr->data.name.rfind(prefix, 0) == 0) {
                std::cout << "Ten: " << curr->data.name 
                          << " | SDT: " << curr->data.phone 
                          << " | Email: " << curr->data.email << std::endl;
                found = true;
            }
                curr = curr->next;
        }

        if (!found) {
            std::cout << "Khong tim thay lien he nao bat dau bang: " << prefix << std::endl;
        }
    }

    // Sắp xếp nổi bọt (Bubble Sort) theo tên A-Z
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
        std::cout << "-> Da sap xep danh ba theo ten (A-Z) thanh cong.\n";
    }
};

#endif