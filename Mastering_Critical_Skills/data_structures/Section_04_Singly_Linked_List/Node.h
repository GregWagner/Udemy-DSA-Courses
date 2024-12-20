#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node {
    int data {};
    Node* next {};

    Node(int data)
        : data(data) {
    }

    ~Node() {
        std::cout << "Destorying Node with value " << data
                  << " at address " << this << '\n';
    }
};

#endif