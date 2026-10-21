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
    }

    void displayHistory() {
        Node<CallLog>* curr = history.head;
        std::cout << "\n=== LICH SU CUOC GOI ===\n";
        if (!curr) {
            std::cout << "Chua co lich su cuoc goi.\n";
            return;
        }
        while (curr) {
            std::cout << "[" << curr->data.timestamp << "] "
                      << curr->data.callType << ": " 
                      << curr->data.phoneNumber 
                      << " (" << curr->data.durationSeconds << "s)\n";
            curr = curr->next;
        }
    }
};

#endif