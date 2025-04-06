#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

class Node {
    public:
        int data;
        Node* next;
    
        Node(int data, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
};

std::string toString(int data) {
    int sign = 1;
    std::stringstream ss;
    
    if (data < 0) {
        data = data * -1;
        sign = -1;
    } else if (data == 0) {
        ss << "0";
    }

    while (data > 0) {
        int mod = data % 10;
        ss << mod;

        data = data / 10;
    }

    if (sign < 0) {
        ss << "-";
    }

    std::string finalStr = ss.str();
    std::reverse(finalStr.begin(), finalStr.end());

    return finalStr;
}

std::string stringify(Node* node) {
    if (!node) {
        return "nullptr";
    }

    std::stringstream ss;
    Node* curr = node;
    
    while (curr) {
        ss << toString(curr->data);

        if (curr->next) {
            ss << " -> ";
        } else {
            ss << " -> nullptr";
            break;
        }

        curr = curr->next;
    }

    return ss.str();
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    std::cout << stringify(head) << std::endl;

    return 0;
}