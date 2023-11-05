#include <iostream>

class Node {
    public:
        int data;
        Node* next;

        Node(int data) : data(data), next{nullptr} {}
};

int length(Node *node);

// find midpoint in O(n) time (leetcode 876)
// Slow and fast pointer approach
// Move slow pointer by 1 and fast pointer by 2
// When fast reaches the end, slow will be at the midpoint
Node* findMiddle(Node* head) {
    Node* slowNode {head};
    Node* fastNode {head->next};
    while (fastNode && fastNode->next) {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
    }
    return (fastNode) ? slowNode->next : slowNode;
}

// slow method
int findMiddle1(Node* head) {
    int size = length(head) / 2;
    Node *current {head};
    for (int i {}; i < size; ++i) {
        current = current->next;
    }
    return current->data;
}

Node* reverse(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node *current {head};
    Node *previous {};
    while (current) {
        Node *next = current->next;  // save this node
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}

Node* insertAt(Node* head, int position, int value) {
    if (position == 0) {
        Node* n = new Node(value);
        n->next = head;
        return n;
    }
    int index {};
    Node* node = head;
    while (node) {
        if (index == position) {
            Node* n = new Node(value);
            n->next = node->next;
            node->next = n;
            return head;
        }
        node = node->next;
        ++index;
    }
    std::cout << "Invalid position, item not inserted\n";
    return head;
}

// Remove kth item from the end (leetcode 19)
// slow why would be to remove (length -k + 1) from the front
// fast way, 2 pointers
//      slow moves by 1
//      fast starts k steps away
Node* removeAtK(Node* head, int k) {
    Node* slowNode {head};
    Node* fastNode {head};
    Node* previous {head};
    for (int i {}; i < k; ++k) {
        fastNode = fastNode->next;
    }

    // check iff deleting the first node
    if (fastNode == nullptr) {
        Node* temp = head->next;
        head->next = nullptr;
        delete head;
        return temp;
    }

    // stop when slowNode iw one behind
    while (fastNode->next) {
        slowNode = slowNode->next;
        fastNode = fastNode->next;
    }
    Node* temp = slowNode->next;
    slowNode->next = slowNode->next->next;
    temp->next = nullptr;
    delete temp;
    return head;
}

     
Node* deleteAt(Node* head, int position) {
    if (position == 0 && head) {
        Node* temp = head->next;
        head->next = nullptr;
        delete (head);
        head = nullptr;
        return temp;
    }
    int index {1};
    Node* node = head;
    Node* previous = node;
    node = node->next;
    while (node) {
        if (index == position) {
            previous->next = node->next;
            node->next = nullptr;
            delete node;
            node = nullptr;
            return head;
        }
        ++index;
        node = node->next;
    }
    std::cout << "Invalid position, item not deleted\n";
    return head;
}

void printAt(Node* node, int position) {
    int index {};
    while (node) {
        if (index == position) {
            std::cout << node->data << '\n';
            return;
        }
        node = node->next;
        ++index;
    }
    std::cout << "Illegal Position\n";
}

int length(Node *node) {
    int count {};
    while (node != nullptr) {
        ++count;
        node = node->next;
    }
    return count;
}

int length1(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + length1(node->next);
}

// insert at tail
Node* takeInputTail() {
    Node *head {};
    Node *tail  {};
    int data {};
    while (std::cin >> data && data != -1) {
        Node *node = new Node(data);
        if (head == nullptr) {      // first node in list
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }
    return head;
}

// insert at head
Node* takeInput() {
    Node *head {};
    int data {};
    while (std::cin >> data && data != -1) {
        Node *node = new Node(data);
        node->next = head;
        head = node;
    }
    return head;
}

void print(Node* head) {
    Node* currentNode {head};
    while (currentNode != nullptr) {
        std::cout << currentNode->data << " -> ";
        currentNode = currentNode->next;
    }
    std::cout << "null\n";
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node *temp = head->next;
        delete head;
        head = temp;
    }
}

bool isPresent(Node* head, int data) {
    Node *current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool findElement(Node* head, int data) {
    if (head == nullptr) {
        return false;
    }
    if (head->data == data) {
        return true;
    }
    return findElement(head->next, data);
}


int main() {
    // statically 
    Node n1(1);
    Node n2(2);
    n1.next = &n2;

    std::cout << n1.data << " " << n2.data
        << ", Length: " << length(&n1) << '\n';

    // dynamically
    Node *n3 = new Node(3); 
    Node *n4 = new Node(4); 
    n3->next = n4;
    print(n3);

    deleteList(n3);

    std::cout << "Enter values to put in list: ";
    Node* head = takeInputTail();
    print(head);
    std::cout << "Length: " << length(head) << '\n';

    std::cout << "Printing at position\n";
    printAt(head, 0);
    printAt(head, 2);
    printAt(head, 10);
#if 0    
    std::cout << "Inserting at position\n";
    head = insertAt(head, 1, 99);
    head = insertAt(head, 99, 1);
    head = insertAt(head, 0, 55);
    print(head);

    std::cout << "Deleting at position\n";
    head = deleteAt(head, 0);
    print(head);
    head = deleteAt(head, 2);
    print(head);
#endif
    deleteList(head);
}
