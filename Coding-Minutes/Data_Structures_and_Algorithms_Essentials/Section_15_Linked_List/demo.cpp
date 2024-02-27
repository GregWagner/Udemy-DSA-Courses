#include <iostream>

// forward declarations
class List;

class Node {
public:
    explicit Node(int d)
        : data{ d }
        , next{ nullptr } {
    }

    ~Node() {
        delete next;
    }

    int getData() const {
        return data;
    }

    friend class List;

private:
    int data;
    Node* next;
};

class List {
public:
    List()
        : head(nullptr)
        , tail(nullptr) {
    }

    ~List() {
        Node* currrent_node = head;
        while (currrent_node != nullptr) {
            head = currrent_node->next;
            currrent_node->next = nullptr;
            delete currrent_node;
            currrent_node = head;
        }
        head = tail = nullptr;
    }

    Node* begin() const {
        return head;
    }

    void print() const {
        Node* currrent_node = head;
        while (currrent_node != nullptr) {
            std::cout << currrent_node->getData() << " -> ";
            currrent_node = currrent_node->next;
        }
        std::cout << "null\n";
    }

    void push_front(int data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            head = tail = node;
        } else {
            node->next = head;
            head = node;
        }
    }

    void pop_front() {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    void push_back(int data) {
        Node* node = new Node(data);
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    Node* deleteTail() {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return head;
        }
        Node* previous_node{};
        Node* currrent_node = head;
        while (currrent_node->next) {
            previous_node = currrent_node;
            currrent_node = currrent_node->next;
        }
        delete previous_node->next;
        previous_node->next = nullptr;
        tail = previous_node;
        return head;
    }

    void pop_back() {
        Node* previous_node{};
        Node* currrent_node = head;
        while (currrent_node->next) {
            previous_node = currrent_node;
            currrent_node = currrent_node->next;
        }
        delete previous_node->next;
        previous_node->next = nullptr;
    }

    void insert(int data, int position) {
        if (position == 0) {
            push_front(data);
            return;
        }
        Node* currrent_node = head;
        for (int index{ 1 }; index <= position - 1; ++index) {
            if (currrent_node->next == nullptr) {
                std::cerr << "Invald insertation position.\n";
                return;
            }
            currrent_node = currrent_node->next;
        }
        Node* node = new Node(data);
        node->next = currrent_node->next;
        currrent_node->next = node;
    }

    void remove(int position) {
        if (head == nullptr) {
            std::cerr << "List is empty\n";
            return;
        }
        Node* currrent_node = head;
        int index{ 1 };
        while (index < position - 1 && currrent_node->next) {
            currrent_node = currrent_node->next;
            ++index;
        }
        if (currrent_node->next == nullptr) {
            std::cerr << "Trying to delete a node not in list\n";
            return;
        }
        Node* temp_node = currrent_node->next;
        currrent_node->next = temp_node->next;
        delete temp_node;
    }

    bool search(int key) const {
        Node* currrent_node = head;
        while (currrent_node != nullptr) {
            if (head->getData() == key) {
                return true;
            }
            currrent_node = head->next;
        }
        return false;
    }

    bool searchRecursive(Node* currrent_node, int key) const {
        if (currrent_node == nullptr) {
            return false;
        }
        if (currrent_node->getData() == key) {
            return true;
        }
        return searchRecursive(currrent_node->next, key);
    }

    int recursiveSearch(int key) {
        return searchHelper(head, key);
    }

    void reverse() {
        tail = head;
        Node* currrent_node = head;
        Node* previous_node = {};
        while (currrent_node != nullptr) {
            Node* next_node = currrent_node->next;
            currrent_node->next = previous_node;
            previous_node = currrent_node;
            currrent_node = next_node;
        }
        head = previous_node;
    }

private:
    Node* head;
    Node* tail;

    int searchHelper(Node* currrent_node, int key) {
        if (currrent_node == nullptr) {
            return -1;
        }
        if (currrent_node->getData() == key) {
            return 0;
        }
        int index = searchHelper(currrent_node->next, key);
        return (index == -1 ? -1 : index + 1);
    }
};

int main() {
    List list;
    ;
    list.push_front(1);
    list.push_front(3);
    list.print();

    list.push_back(4);
    list.print();

    list.insert(5, 2);
    list.insert(6, 2);
    list.print();

    list.pop_front();
    list.print();

    list.deleteTail();
    list.print();
    list.push_back(99);
    list.print();

    list.reverse();
    list.print();

    list.deleteTail();
    list.print();
}
