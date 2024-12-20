#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include <algorithm>
#include <vector>

class LinkedList {

private:
    Node* head {};
    Node* tail {};
    int length {};

    // the rest is used for debugin in case the linked list
    // gets corrupted
    std::vector<Node*> debugData;
    void addNode(Node* node);
    void debugAddNode(Node* node);
    void debugRemoveNode(Node* node);

public:
    // prevent copy and assignment to avoid common mistakes
    LinkedList() {
    }
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList& other) = delete;
    ~LinkedList();

    void print() const;
    void insertEnd(int value);
    void insertFront(int value);
    void deleteNode(Node* node);
    void deleteFront();
    void deleteEnd();
    void deleteNth(int n);
    Node* getNth(int n) const;
    Node* getNthBack(int n) const;
    int search(int value) const;
    int improveSearch(int value) const;

    bool isSame(const LinkedList& other) const;

    void debugVerifyIntegrity() const;
    std::string debugToString() const;
    void debugPrintList(std::string msg = "") const;
    void debugPrintNode(Node* node, bool is_seperate = false) const;
    void debugPrintAddress() const;
};

#endif