#include "LinkedList.h"
#include "Node.h"
#include <cassert>
#include <iostream>

void printList(Node* head) {
    while (head) {
        std::cout << head->data << ' ';
        head = head->next;
    }
    std::cout << '\n';
}

void printList1(Node* head) {
    if (!head) {
        std::cout << '\n';
        return;
    }
    std::cout << head->data << ' ';
    printList1(head->next);
}

void printReverse(Node* head) {
    if (!head) {
        std::cout << '\n';
        return;
    }
    printReverse(head->next);
    std::cout << head->data << ' ';
}

void findAndPrintItem(LinkedList& list, int item) {
    Node* foundNode = list.getNth(item);
    if (foundNode) {
        std::cout << "Finding 2nd item: " << foundNode->data << '\n';
    } else {
        std::cout << "Item not found\n";
    }
}

void searchAndPrintItem(LinkedList& list, int value) {
    int location = list.improveSearch(value);
    if (location != -1) {
        std::cout << "Found value at node " << location << '\n';
    } else {
        std::cout << "Item not found\n";
    }
}

// Test initial Node class
void test1() {
    std::cout << "\n\nTest #1\n";

    Node* node1 = new Node(6);
    Node* node2 = new Node(10);
    Node* node3 = new Node(8);
    Node* node4 = new Node(15);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;

    printList(node1);
    printList1(node1);
}

// Test initial LinkedList class
void test2() {
    std::cout << "\n\nTest #2\n";

    LinkedList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    list.print();
    std::string expected = "10 20 30 40";
    std::string results = list.debugToString();
    if (expected != results) {
        std::cout << "Test failed:\nExpected: " << expected
                  << "\nResults: " << results << '\n';
        assert(false);
    }

    findAndPrintItem(list, 2);
    findAndPrintItem(list, 20);

    std::cout << "---------------\n";
    searchAndPrintItem(list, 20);
    searchAndPrintItem(list, 20);
    searchAndPrintItem(list, 99);
    list.print();
}

void test3() {
    std::cout << "\n\nTest #3\n";

    LinkedList list;
    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.insertFront(40);

    std::string expected = "40 30 20 10";
    std::string results = list.debugToString();
    if (expected != results) {
        std::cout << "Test failed:\nExpected: " << expected
                  << "\nResults: " << results << '\n';
        assert(false);
    }
}

void test4() {
    std::cout << "\n\nTest #4\n";

    LinkedList list;
    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.insertFront(40);

    list.deleteFront();
    std::string expected = "30 20 10";
    std::string results = list.debugToString();
    if (expected != results) {
        std::cout << "Test failed:\nExpected: " << expected
                  << "\nResults: " << results << '\n';
        assert(false);
    }
}

void test5() {
    std::cout << "\n\nTest #5\n";

    LinkedList list;
    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.insertFront(40);

    auto answer = list.getNthBack(2);
    if (answer->data != 30) {
        std::cout << "Test failed:\nExpected: 40"
                  << "\nResults: " << answer << '\n';
        assert(false);
    }

    std::string expected = "40 30 20 10";
    std::string results = list.debugToString();
    if (expected != results) {
        std::cout << "Test failed:\nExpected: " << expected
                  << "\nResults: " << results << '\n';
        assert(false);
    }
}

void test6() {
    std::cout << "\n\nTest #6\n";

    LinkedList list1;
    list1.insertFront(10);
    list1.insertFront(20);
    list1.insertFront(30);
    list1.insertFront(40);

    LinkedList list2;
    list2.insertFront(10);
    list2.insertFront(20);
    list2.insertFront(30);
    list2.insertFront(40);

    auto answer = list1.isSame(list2);
    if (!answer) {
        std::cout << "Test failed:\nExpected: true"
                  << "\nResults: false" << '\n';
        assert(false);
    }

    list2.deleteFront();
    answer = list1.isSame(list2);
    if (answer) {
        std::cout << "Test failed:\nExpected: false"
                  << "\nResults: true" << '\n';
        assert(false);
    }
}

int main() {
    test1();
    test2();
    test3(); // test insert front
    test4(); // test delete front
    test5(); // test get nth from back
    test6(); // test is same

    std::cout << "\n\nNo Run Time Error!\n";
}
