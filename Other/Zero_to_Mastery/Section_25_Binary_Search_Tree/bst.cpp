#include <iostream>

template<typename T>
class BTNode{
    public:
        T data;
        BTNode* left;
        BTNode* right;

        BTNode(T data) : data {data}, left {}, right {} {
        }

        ~BTNode() {
            delete left;
            delete right;
        }
};

class BST {
    public:
        BST() : root {} {
        }

        ~BST() {
            delete root;
        }

        void deleteNode(int data) {
            root = deleteHelper(root, data);
        }

        void insert(int data) {
            root = insert(root, data);
        }

        bool hasData(int data) {
            return hasData(root, data);
        }

        void print() {
            printTree(root);
        }

        // Convert BST to linked list - no new nodes
        // use right pointer to next node and set left pointer to null
        BTNode<int>* convertToLinkedLiist() {
            auto p = convertToLLHelper(root);
            auto temp = p.head;
            while (temp) {
                temp->left = nullptr;
                temp = temp->right;
            }
             
            return p.head;
        }

    private:
        struct Pair {
            BTNode<int>* head;
            BTNode<int>* tail;
        };

        // This is not working
        Pair convertToLLHelper(BTNode<int>* root) {
            if (root == nullptr) {
                Pair answer {};
                answer.head = nullptr;
                answer.tail = nullptr;
                return answer;
            }
            if (root->left == nullptr && root->right == nullptr) {
                Pair p {};
                p.head = root;
                p.tail = root;
                return p;
            }

            if (root->left && root->right == nullptr) {
                Pair leftLL = convertToLLHelper(root->left);
                leftLL.tail->right = root;
                Pair answer {};
                answer.head = leftLL.head;
                answer.tail = root;
                return answer;
            }

            if (root->left == nullptr && root->right) {
                Pair rightLL = convertToLLHelper(root->right);
                root->right = rightLL.head;
                Pair answer {};
                answer.head = root;
                answer.tail = rightLL.tail;
                return answer;
            }

            // both right and left exists
            Pair leftLL = convertToLLHelper(root->left);
            Pair rightLL = convertToLLHelper(root->right);
            leftLL.tail = root;
            root->right = rightLL.head;
            Pair answer {};
            answer.head = leftLL.head;
            answer.tail = rightLL.tail;
            return answer;
        }

        // this is not working correctly
        BTNode<int>* deleteHelper(BTNode<int>* node, int data) {
            if (node == nullptr) {
                return nullptr;
            }

            if (data < node->data) {
                node->left =  deleteHelper(node->left, data);
            } else if (data > node->data) {
                node->right =  deleteHelper(node->right, data);
            } else {
                // Match found

                // Case 1: match is a leaf node
                if (node->left == nullptr && node->right == nullptr) {
                    delete node;
                    return nullptr;
                }

                // Case 3: match has one child
                if (node->left == nullptr) {
                    BTNode<int>* temp = node->right;
                    node->right = nullptr;
                    delete node;
                    return temp;
                } 
                if (node->right) {
                    BTNode<int>* temp = node->left;
                    node->left = nullptr;
                    delete node;
                    return temp;
                } else {
                    // Case 3: match has 2 children
                    // Swap the right minimum and then delete the right minimum
                    BTNode<int>* minNode = node->right;
                    while (minNode->left) {
                        minNode = minNode->left;
                    }
                    node->data = minNode->data;
                    node->right = deleteHelper(node->right, node->data);
                }
            }
            return node;
        }

        BTNode<int>* insert(BTNode<int>* node, int data) {
            if (node == nullptr) {
                return new BTNode<int>(data);
            }
            if (data < node->data) {
                node->left = insert(node->left, data);
            } else {
                node->right = insert(node->right,data);
            }
            return node;
        }

        bool hasData(BTNode<int>* root, int data) {
            if (root == nullptr) {
                return false;
            }
            if (root->data == data) {
                return true;
            }
            if (data < root->data) {
                return hasData(root->left, data);
            }
            return hasData(root->right, data);
        }


        void printTree(BTNode<int>* root) {
            if (root == nullptr) {
                return;
            }
            std::cout << root->data << ": ";
            if (root->left) {
                std::cout << root->left->data << ' ';
            }
            if (root->right) {
                std::cout << root->right->data << ' ';
            }
            std::cout << '\n';

            printTree(root->left);
            printTree(root->right);
        }

        BTNode<int>* root;
};

int main() {
    BST b;
    //int a[] {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int a[] {10, 5, 20, 7, 3, 15};
    for (int x : a) {
        b.insert(x);
    }
    std::cout << std::boolalpha;
    std::cout << "Has Data 10? " << b.hasData(10) << '\n';
    std::cout << "Has Data 11? " << b.hasData(11) << '\n';
    b.print();
    std::cout << "-------------------------\n";
#if 0
    std::cout << "Delete 10:\n";
    b.deleteNode(10);
    b.print();

    std::cout << "-------------------------\n";
    std::cout << "Delete 5:\n";
    b.deleteNode(5);
    b.print();

    std::cout << "-------------------------\n";
    std::cout << "Delete 15:\n";
    b.deleteNode(15);
    b.print();

    std::cout << "-------------------------\n";
    std::cout << "Delete 100:\n";
    b.print();

    std::cout << "-------------------------\n";
    std::cout << "Delete 7:\n";
    b.deleteNode(7);
    b.print();
#endif
    auto head = b.convertToLinkedLiist();
    auto temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->right;
    }
    std::cout << '\n';
}
