#include "LinkedList.h"

class LinkedListNoTail {
private:
    Node* head {};

public:
    void print() {
        for (Node* currentNode = head; currentNode != nullptr; currentNode = currentNode->next) {
            std::cout << currentNode->data << ' ';
        }
        std::cout << '\n';
    }

    void addElement(int value) {
        Node* newNode = new Node(value);
        newNode = head->next;
        head = newNode;
    }

    Node* getTail() {
        Node* node = head;
        while (node->next != nullptr) {
            node = node->next;
        }
        return node;
    }
};