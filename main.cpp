#include <iostream>
#include <string>
#include <limits>
#include "DoublyLinkedList.h"
#include "ContactManager.h"
#include "CallHistory.h"
#include "SearchSort.h"

using namespace std;

// Hàm xóa bộ nhớ đệm để tránh bị nhảy dòng khi nhập dữ liệu
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    ContactManager contactMgr;
    CallHistory callHistoryMgr;

    int choice;
    do {
        cout << "\n=================================\n";
        cout << "====CHUONG TRINH QUAN LY DANH BA====\n";
        cout << "===================================\n";
        cout << "1. Them lien he moi\n";
        cout << "2. Hien thi danh ba (A - Z)\n";
        cout << "3. Hien thi danh ba (Z - A)\n";
        cout << "4. Tim kiem lien he theo tien to (Prefix)\n";
        cout << "5. Sap xep danh ba theo ten (A-Z)\n";
        cout << "6. Xoa lien he theo SDT\n";
        cout << "7. Ghi nhan cuoc goi moi\n";
        cout << "8. Xem toan bo lich su cuoc goi\n";
        cout << "9. Xem cuoc goi gan nhat\n";
        cout << "0. Thoat\n";
        cout << "------------------------------------\n";
        cout << "Chon chuc nang (0-9): ";

        if (!(cin >> choice)) {
            cout << "Lua chon khong hop le! Vui long nhap so.\n";
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        switch (choice) {
            case 1: {
                string name, phone, email;
                cout << "Nhap ten: ";
                getline(cin, name);
                cout << "Nhap SDT: ";
                getline(cin, phone);
                cout << "Nhap Email: ";
                getline(cin, email);

                contactMgr.addContact(name, phone, email);
                break;
            }
            case 2:
                contactMgr.displayAll();
                break;
            case 3:
                contactMgr.displayReverse();
                break;
            case 4: {
                string prefix;
                cout << "Nhap tien to ten can tim: ";
                getline(cin, prefix);
                SearchSort::searchByPrefix(contactMgr, prefix);
                break;
            }
            case 5:
                SearchSort::sortByName(contactMgr);
                break;
            case 6: {
                string phone;
                cout << "Nhap SDT can xoa: ";
                getline(cin, phone);
                contactMgr.deleteContactByPhone(phone);
                break;
            }
            case 7: {
                string phone, timestamp, callType;
                int duration;

                cout << "Nhap SDT cuoc goi: ";
                getline(cin, phone);
                cout << "Nhap thoi gian (vd: 10:30 25/10): ";
                getline(cin, timestamp);
                cout << "Nhap loai cuoc goi (Den/Di/Nho): ";
                getline(cin, callType);
                cout << "Nhap thoi luong (giay): ";
                while (!(cin >> duration)) {
                    cout << "Thoi luong phai la so! Nhap lai: ";
                    clearInputBuffer();
                }
                clearInputBuffer();

                callHistoryMgr.addLog(phone, timestamp, duration, callType);
                break;
            }
            case 8:
                callHistoryMgr.displayHistory();
                break;
            case 9:
                callHistoryMgr.displayLatestCall();
                break;
            case 0:
                cout << "-> Da thoat chuong trinh.\n";
                break;
            default:
                cout << "-> Lua chon khong hop le!\n";
                break;
        }
    } while (choice != 0);

    return 0;
}