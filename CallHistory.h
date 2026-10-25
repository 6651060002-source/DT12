#ifndef CALL_HISTORY_H
#define CALL_HISTORY_H

#include <string>
#include <iostream>
#include "DoublyLinkedList.h"

struct CallLog {
    std::string phoneNumber;
    std::string timestamp;
    int durationSeconds;
    std::string callType; // "Den", "Di", "Nho"
};

class CallHistory {
private:
    DoublyLinkedList<CallLog> history;

public:
    void addLog(const std::string& phone, const std::string& time, int duration, const std::string& type) {
        history.pushBack({phone, time, duration, type});
        std::cout << "-> Da ghi nhan cuoc goi " << type << " tu/den so: " << phone << std::endl;
    }

    // Hiển thị lịch sử cuộc gọi (Ưu tiên cuộc gọi mới nhất lên đầu: Tail -> Head)
    void displayHistory() {
        Node<CallLog>* curr = history.tail;
        std::cout << "\n=== LICH SU CUOC GOI (MOI NHAT TRUOC) ===\n";
        if (!curr) {
            std::cout << "Chua co lich su cuoc goi.\n";
            return;
        }
        while (curr) {
            std::cout << "[" << curr->data.timestamp << "] "
                      << curr->data.callType << ": " 
                      << curr->data.phoneNumber 
                      << " (" << curr->data.durationSeconds << "s)\n";
            curr = curr->prev;
        }
    }

    // Xem cuộc gọi gần đây nhất (Đúng theo yêu cầu đề tài)
    void displayLatestCall() {
        if (!history.tail) {
            std::cout << "\nChua co lich su cuoc goi.\n";
            return;
        }
        std::cout << "\n=== CUOC GOI GAN NHAT ===\n";
        std::cout << "[" << history.tail->data.timestamp << "] "
                  << history.tail->data.callType << ": " 
                  << history.tail->data.phoneNumber 
                  << " (" << history.tail->data.durationSeconds << "s)\n";
    }
};

#endif