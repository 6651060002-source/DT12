#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "ContactManager.h"
#include "CallHistory.h"
#include "SearchSort.h"

// 1. Hàm lưu danh bạ vào file TXT
void saveContactsToFile(ContactManager& cm, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "-> Loi: Khong the mo file de ghi!\n";
        return;
    }

    Node<Contact>* curr = cm.contacts.head;
    while (curr) {
        outFile << curr->data.name << "," 
                << curr->data.phone << "," 
                << curr->data.email << "\n";
        curr = curr->next;
    }
    outFile.close();
    std::cout << "-> Da luu danh ba vao file: " << filename << std::endl;
}

// 2. Hàm đọc danh bạ từ file TXT khi mở ứng dụng
void loadContactsFromFile(ContactManager& cm, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) return;

    std::string line;
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;
        std::stringstream ss(line);
        std::string name, phone, email;

        if (std::getline(ss, name, ',') &&
            std::getline(ss, phone, ',') &&
            std::getline(ss, email)) {
            cm.contacts.pushBack({name, phone, email});
        }
    }
    inFile.close();
}

// 3. Hàm hiển thị Menu giao diện
void showMenu() {
    std::cout << "\n=========================================\n";
    std::cout << "   QUAN LY DANH BA & LICH SU CUOC GOI   \n";
    std::cout << "=========================================\n";
    std::cout << "1. Them lien he moi\n";
    std::cout << "2. Xem danh sach lien he (A-Z)\n";
    std::cout << "3. Xem danh sach lien he (Z-A)\n";
    std::cout << "4. Xoa lien he theo So dien thoai\n";
    std::cout << "5. Tim kiem lien he theo tien to (Prefix)\n";
    std::cout << "6. Sap xep danh ba theo ten (A-Z)\n";
    std::cout << "7. Ghi nhan cuoc goi moi\n";
    std::cout << "8. Xem lich su cuoc goi (Moi nhat truoc)\n";
    std::cout << "9. Xem cuoc goi gan nhat\n";
    std::cout << "0. Luu va Thoat\n";
    std::cout << "=========================================\n";
    std::cout << "Nhap lua chon cua ban: ";
}

int main() {
    ContactManager cm;
    CallHistory ch;
    std::string filename = "contacts.txt";

    // Tự động tải danh bạ từ file cũ lên bộ nhớ khi khởi động
    loadContactsFromFile(cm, filename);

    int choice = -1;
    while (choice != 0) {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // Xóa bộ nhớ đệm bàn phím

        switch (choice) {
            case 1: {
                std::string name, phone, email;
                std::cout << "\n--- THEM LIEN HE MOI ---\n";
                std::cout << "Nhap Ho va Ten: ";
                std::getline(std::cin, name);
                std::cout << "Nhap So dien thoai: ";
                std::getline(std::cin, phone);
                std::cout << "Nhap Email: ";
std::getline(std::cin, email);

                cm.addContact(name, phone, email);
                break;
            }
            case 2:
                cm.displayAll();
                break;
            case 3:
                cm.displayReverse();
                break;
            case 4: {
                std::string phone;
                std::cout << "\n--- XOA LIEN HE ---\n";
                std::cout << "Nhap So dien thoai can xoa: ";
                std::getline(std::cin, phone);
                cm.deleteContactByPhone(phone);
                break;
            }
            case 5: {
                std::string prefix;
                std::cout << "\n--- TIM KIEM THEO TIEN TO ---\n";
                std::cout << "Nhap chu cai bat dau: ";
                std::getline(std::cin, prefix);
                SearchSort::searchByPrefix(cm, prefix);
                break;
            }
            case 6:
                SearchSort::sortByName(cm);
                cm.displayAll();
                break;
            case 7: {
                std::string phone, time, type;
                int duration;
                std::cout << "\n--- GHI NHAN CUOC GOI ---\n";
                std::cout << "Nhap So dien thoai: ";
                std::getline(std::cin, phone);
                std::cout << "Nhap Thoi gian (vi du: 2026-03-30 14:30): ";
                std::getline(std::cin, time);
                std::cout << "Nhap Loai cuoc goi (Den/Di/Nho): ";
                std::getline(std::cin, type);
                std::cout << "Nhap Thoi luong (giay): ";
                std::cin >> duration;
                std::cin.ignore();

                ch.addLog(phone, time, duration, type);
                break;
            }
            case 8:
                ch.displayHistory();
                break;
            case 9:
                ch.displayLatestCall();
                break;
            case 0:
                saveContactsToFile(cm, filename);
                std::cout << "\n-> Da luu du lieu va thoat chuong trinh. Tam biet!\n";
                break;
            default:
                std::cout << "\n-> Lua chon khong hop le! Vui long nhap lai.\n";
                break;
        }
    }

    return 0;
}
