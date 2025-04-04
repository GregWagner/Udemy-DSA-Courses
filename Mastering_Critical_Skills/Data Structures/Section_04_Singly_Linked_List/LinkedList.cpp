#include "LinkedList.h"
#include <cassert>
#include <iostream>
#include <sstream>

/* better to use for loop - see below
void LinkedList::print() {
    Node* currentNode = head;
    while (currentNode != nullptr) {
        std::cout << currentNode->data << ' ';
        currentNode = currentNode->next;
    }
    std::cout << '\n';
}
*/

void LinkedList::addNode(Node* node) {
    debugAddNode(node);
    ++length;
}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

void LinkedList::print() const {
    for (Node* currentNode = head; currentNode != nullptr; currentNode = currentNode->next) {
        std::cout << currentNode->data << ' ';
    }
    std::cout << '\n';
}

void LinkedList::insertEnd(int data) {
    Node* newNode = new Node(data);
    addNode(newNode);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    debugVerifyIntegrity();
}

void LinkedList::insertFront(int data) {
    Node* newNode = new Node(data);
    addNode(newNode);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    debugVerifyIntegrity();
}

void LinkedList::deleteNode(Node* node) {
    --length;
    delete node;
}

void LinkedList::deleteFront() {
    // make sure there is at least one
    if (head != nullptr) {
        Node* node = head;
        head = head->next;
        // handle if this is te last item on list
        if (head == nullptr) {
            tail = nullptr;
        }
        deleteNode(node);
    }
    debugVerifyIntegrity();
}

void LinkedList::deleteEnd() {
    // make sure there is at least one item on the list
    if (length <= 1) {
        deleteFront();
        return;
    }
    Node* prevousNode = getNth(length - 1);
    deleteNode(tail);
    tail = prevousNode;
    tail->next = nullptr;

    debugVerifyIntegrity();
}

void LinkedList::deleteNth(int n) {
    if (n < 0 || n >= length) {
        return;
    }
    if (n == 0) {
        deleteFront();
        return;
    }
    if (n == length) {
        deleteEnd();
        return;
    }

    Node* previousNode = getNth(n - 1);
    Node* currentNode = previousNode->next;
    previousNode = currentNode->next;
    deleteNode(currentNode);

    debugVerifyIntegrity();
}

Node* LinkedList::getNth(int n) const {
    int count {};
    for (Node* currentNode = head; currentNode != nullptr; currentNode = currentNode->next) {
        ++count;
        if (count == n) {
            return currentNode;
        }
    }
    return nullptr;
}

Node* LinkedList::getNthBack(int n) const {
    int index = length - n;
    if (index < 0) {
        return nullptr;
    }
    return getNth(index);
}

int LinkedList::search(int value) const {
    int index {};
    for (Node* currentNode { head }; currentNode != nullptr; currentNode = currentNode->next) {
        if (currentNode->data == value) {
            return index;
        }
        ++index;
    }
    return -1;
}

int LinkedList::improveSearch(int value) const {
    int index {};
    Node* previousNode {};
    for (Node* currentNode { head }; currentNode != nullptr; currentNode = currentNode->next) {
        if (currentNode->data == value) {
            if (previousNode) {
                std::swap(previousNode->data, currentNode->data);
            }
            return index;
        }
        previousNode = currentNode;
        ++index;
    }
    return -1;
}

bool LinkedList::isSame(const LinkedList& other) const {
    if (length != other.length) {
        std::cout << "Length mismatch\n";
        return false;
    }

    Node* currentNode = head;
    Node* otherCurrentNode = other.head;
    while (currentNode != nullptr) {
        if (currentNode->data != otherCurrentNode->data) {
            return false;
        }
        currentNode = currentNode->next;
        otherCurrentNode = otherCurrentNode->next;
    }
    return true;
}

void LinkedList::debugVerifyIntegrity() const {
    if (length == 0) {
        assert(head == nullptr);
        assert(tail == nullptr);
    } else {
        assert(head != nullptr);
        assert(tail != nullptr);
        if (length == 1) {
            assert(head == tail);
        } else {
            assert(head != tail);
        }
        assert(tail->next == nullptr);
    }

    int calculatedLength {};
    for (Node* currentNode = head; currentNode != nullptr; currentNode = currentNode->next) {
        assert(calculatedLength < 10000); // check for infinte cycle
        ++calculatedLength;
    }
    assert(length == calculatedLength);
    // TODO: Add debugData tracking
    // assert(length == (int)debugData.size());
}

std::string LinkedList::debugToString() const {
    if (length == 0) {
        return "";
    }
    std::ostringstream output;
    for (Node* currentNode = head; currentNode != nullptr; currentNode = currentNode->next) {
        output << currentNode->data;
        if (currentNode->next) {
            output << ' ';
        }
    }
    return output.str();
}

void LinkedList::debugPrintList(std::string msg) const {
    if (msg != "") {
        std::cout << msg << "\n";
    }
    for (int i {}; i < (int)debugData.size(); ++i) {
        debugPrintNode(debugData[i]);
    }
    std::cout << "************\n"
              << std::flush;
}

void LinkedList::debugPrintNode(Node* node, bool is_seperate) const {
    if (is_seperate) {
        std::cout << "Sep: ";
    }
    if (node == nullptr) {
        std::cout << "nullptr\n";
        return;
    }
    std::cout << node->data << " ";
    if (node->next == nullptr) {
        std::cout << "X ";
    } else {
        std::cout << node->next->data << " ";
    }

    if (node == head) {
        std::cout << "head\n";
    } else if (node == tail) {
        std::cout << "tail\n";
    } else {
        std::cout << "\n";
    }
}

void LinkedList::debugPrintAddress() const {
    for (Node* currentNode = head; currentNode != nullptr; currentNode = currentNode->next) {
        std::cout << currentNode << ", " << currentNode->data << '\t';
    }
    std::cout << "\n";
}

void LinkedList::debugAddNode(Node* node) {
    debugData.push_back(node);
}

void LinkedList::debugRemoveNode(Node* node) {
    auto it = std::find(debugData.begin(), debugData.end(), node);
    if (it == debugData.end()) {
        std::cout << "Node does not exist\n";
    } else {
        debugData.erase(it);
    }
}
