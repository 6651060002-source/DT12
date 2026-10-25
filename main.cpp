#include <fstream>
#include <iostream>
#include "ContactManager.h"
#include "CallHistory.h"
#include "SearchSort.h"

void saveContactsToFile(ContactManager& cm, const std::string& filename) {
    std::ofstream outFile(filename);
    Node<Contact>* curr = cm.contacts.head;
    while (curr) {
        outFile << curr->data.name << "," << curr->data.phone << "," << curr->data.email << "\n";
        curr = curr->next;
    }
    outFile.close();
    std::cout << "-> Da luu danh ba vao file " << filename << std::endl;
}

void testSystem() {
    std::cout << "=== RUNNING SYSTEM TESTS ===\n";
    ContactManager cm;
    CallHistory ch;

    // 1. Test Them Contact
    cm.addContact("Nguyen Van A", "0901234567", "a@gmail.com");
    cm.addContact("Tran Thi B", "0987654321", "b@gmail.com");

    // 2. Test Sap xep & Tim kiem
    SearchSort::sortByName(cm);
    cm.displayAll();

    Node<Contact>* found = SearchSort::searchByName(cm, "Tran");
    if (found) {
        std::cout << "-> Tim thay: " << found->data.name << " (" << found->data.phone << ")\n";
    }

    // 3. Test Lich su cuoc goi
    ch.addLog("0901234567", "2026-03-30 10:00", 120, "Den");
    ch.displayHistory();

    // 4. Test File I/O
    saveContactsToFile(cm, "contacts_test.txt");
    std::cout << "=== TESTS COMPLETED SUCCESSFULLY ===\n";
}

int main() {
    testSystem();
    system("pause");
    return 0;
}