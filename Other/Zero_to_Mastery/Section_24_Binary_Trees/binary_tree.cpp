#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

template <typename T>
struct BTNode {
    BTNode(T data) : data {data}, left {}, right {} {
    }

    ~BTNode() {
        delete left;
        delete right;
    }

    T data;
    BTNode* left;
    BTNode* right;
};

template <typename T>
void printTree(BTNode<T>* root) {
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

template <typename T>
BTNode<T>* takeInput() {
    int rootData {};
    std::cout << "Enter data: ";
    std::cin >> rootData;
    if (rootData == -1) {
        return nullptr;
    }
    BTNode<T>* root = new BTNode<T>(rootData);

    root->left = takeInput<T>();
    root->right = takeInput<T>();

    return root;
}

template <typename T>
BTNode<T>* takeInputByLevel() {
    std::queue<BTNode<T>*> q;

    T rootData {};
    std::cout << "Enter root data: ";
    std::cin >> rootData;
    if (rootData == -1) {
        return nullptr;
    }
    auto root = new BTNode<T>(rootData);
    q.push(root);

    while (!q.empty()) {
        T childData {};
        auto node = q.front();
        q.pop();

        // create left
        std::cout << "Enter the left child of " << node->data << ": ";
        std::cin >> childData;
        if (childData != -1) {
            auto child = new BTNode<T>(childData);
            q.push(child);          // push on queue
            node->left = child;     // connect to tree
        }

        // create right
        std::cout << "Enter the right child of " << node->data << ": ";
        std::cin >> childData;
        if (childData != -1) {
            auto child = new BTNode<T>(childData);
            q.push(child);          // push on queue
            node->right = child;    // connect to tree
        }
    }
    return root;
}

// Time = O(n), Space = O(n)
template <typename T>
void levelOrderTraversal(BTNode<T>* root) {
    std::queue<BTNode<T>*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        auto *node = q.front();
        q.pop();
        if (node == nullptr) {
            if (!q.empty()) {
                std::cout << '\n';
                q.push(nullptr);
            }
            continue;
        }
        std::cout << node->data << ' ';

        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
    std::cout << '\n';
}

template <typename T>
int countNodes(BTNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

template <typename T>
void inOrderTraversal(BTNode<T>* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data << ' ';
    inOrderTraversal(root->right);
}

template <typename T>
void preTraversal(BTNode<T>* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << ' ';
    preTraversal(root->left);
    preTraversal(root->right);
}

template <typename T>
void postTraversal(BTNode<T>* root) {
    if (root == nullptr) {
        return;
    }
    postTraversal(root->left);
    postTraversal(root->right);
    std::cout << root->data << ' ';
}

// Same as find height
template <typename T>
int maxDepth(BTNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

// need to compare both vallue and structure
// leetcode 101
template <typename T>
bool symetricHelper(BTNode<T>* leftTree, BTNode<T>* rightTree) {
    if (leftTree == nullptr && rightTree != nullptr) {
        return false;
    }
    if (leftTree != nullptr && rightTree == nullptr) {
        return false;
    }
    if (leftTree == nullptr && rightTree == nullptr) {
        return true;
    }
    if (leftTree->data != rightTree->data) {
        return false; 
    }
    return symetricHelper(leftTree->right, rightTree->left) &&
        symetricHelper(leftTree->left, rightTree->right);
}

template <typename T>
bool isSymmetric(BTNode<T>* root) {
    if (root == nullptr) {
        return true;
    }
    return symetricHelper(root->left, root->right);
}

template <typename T>
bool searchKey(BTNode<T>* root, T key) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    return findKey(root->left, key) ||
        findKey(root->right, key);
}

template <typename T>
T minValue(BTNode<T>* root) {
    if (root == nullptr) {
        return INT_MAX;
    }
    T leftMin = minValue(root->left);
    T rightMin = minValue(root->right);
    return std::min(root->val, std::min(leftMin, rightMin));
}

template <typename T>
T maxValue(BTNode<T>* root) {
    if (root == nullptr) {
        return -INT_MAX;
    }
    T leftMax = maxValue(root->left);
    T rightMax = maxValue(root->right);
    return std::max(root->val, std::min(leftMax, rightMax));
}

template <typename T>
int countLeafNodes(BTNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return countNodes(root->left) + countNodes(root->right);
}

/*
 * Construct a tree from PreOrder and Inorder Traversal
 * (need both to define a unique tree)
 * 1) Get the root from the preorder - it's the first item
 * 2) Find the root in the inorder to determine the left and right
 *    and use the index in inorder data to determine the ending
 *    index of left (index - 1) and the starting index of right
 *    (index + 1)
 * 3) Do recursion
 *
 * Inorder data:
 *  --- left --- root --- right ---
 *  Preorder data:
 *  root --- left --- right ---
 *
 *  leetcode 105
 */
template <typename T>
BTNode<T>* buildTreeHelper(const std::vector<T>& preorder, const std::vector<T>& inorder,
        int preOrderStart, int preOrderEnd, int inOrderStart, int inOrderEnd) {
    if (inOrderStart > inOrderEnd) {
        return nullptr;
    }
    int rootData = preorder[preOrderStart];
    BTNode<T>* root = new BTNode<T>(rootData);

    int rootInOrderIndex {};
    for (int i {inOrderStart}; i <= inOrderEnd; ++i) {
        if (inorder[i] == rootData) {
            rootInOrderIndex = i;
            break;
        }
    }
    int leftInOrderStart {inOrderStart};
    int leftInOrderEnd {rootInOrderIndex - 1};
    int leftPreOrderStart {preOrderStart + 1};
    int leftPreOrderEnd {leftPreOrderStart + leftInOrderEnd - leftInOrderStart};
    root->left = buildTreeHelper(preorder, inorder,
            leftPreOrderStart, leftPreOrderEnd,
            leftInOrderStart, leftInOrderEnd);        
    int rightInOrderStart {rootInOrderIndex + 1};
    int rightInOrderEnd {inOrderEnd};
    int rightPreOrderStart {leftPreOrderEnd + 1};
    int rightPreOrderEnd {preOrderEnd};
    root->right = buildTreeHelper(preorder, inorder,
            rightPreOrderStart, rightPreOrderEnd, 
            rightInOrderStart, rightInOrderEnd);
    return root;
}

/*
 * Inorder data:
 *  --- left --- root --- right ---
 *  Postorder data:
 *  --- left --- right --- root
 *
 *  leetcode 106
 */
template <typename T>
BTNode<T>* buildTreeHelper1(const std::vector<T>& inorder, const std::vector<T>& postorder,
        int inOrderStart, int inOrderEnd, int postOrderStart, int postOrderEnd) {
    if (inOrderStart > inOrderEnd) {
        return nullptr;
    }
    int rootData = postorder[postOrderEnd];
    BTNode<T>* root = new BTNode<T>(rootData);

    int rootInOrderIndex {};
    for (int i {inOrderStart}; i <= inOrderEnd; ++i) {
        if (inorder[i] == rootData) {
            rootInOrderIndex = i;
            break;
        }
    }

    int leftInOrderStart {inOrderStart};
    int leftInOrderEnd {rootInOrderIndex - 1};
    int leftPostOrderStart {postOrderStart};
    int leftPostOrderEnd {leftInOrderEnd - leftInOrderStart + leftPostOrderStart};
    root->left = buildTreeHelper(inorder, postorder,
            leftInOrderStart, leftInOrderEnd,
            leftPostOrderStart, leftPostOrderEnd);
    int rightInOrderStart {rootInOrderIndex + 1};
    int rightInOrderEnd {inOrderEnd};
    int rightPostOrderStart {leftPostOrderEnd + 1};
    int rightPostOrderEnd {postOrderEnd - 1};
    root->right = buildTreeHelper(inorder, postorder,
            rightInOrderStart, rightInOrderEnd,
            rightPostOrderStart, rightPostOrderEnd);
    return root;
}

template <typename T>
BTNode<T>* buildTree(std::vector<T>& preorder, std::vector<T>& inorder) {
    int n = preorder.size() - 1;
    return buildTreeHelper(preorder, inorder, 0, n, 0, n);
}

template <typename T>
BTNode<T>* buildTree1(std::vector<T>& inorder, std::vector<T>& postorder) {
    int n = postorder.size() - 1;
    return buildTreeHelper1(inorder, postorder, 0, n, 0, n);
}

// NOTE: diameter does not have to include the root
// O(n * height of tree)
template <typename T>
int diameter(BTNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    int includeRoot = maxDepth(root->left) + maxDepth(root->right);
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    return std::max(includeRoot, std::max(leftDiameter, rightDiameter));
}

// A better way to calculate diameter O(n)
template <typename T>
std::pair<int, int> getHeightDiameter(BTNode<T>* root) {
    std::pair<int, int> results {0, 0};
    if (root == nullptr) {
        return results;
    }
    auto leftAnswer {getHeightDiameter(root->left)};
    auto rightAnswer {getHeightDiameter(root->right)};

    int leftHeight = leftAnswer.first;
    int leftDiameter = leftAnswer.second;
    int rightHeight = rightAnswer.first;
    int rightDiameter = rightAnswer.second;

    int height = 1 + std::max(leftHeight, rightHeight);
    int diameter = std::max(leftHeight + rightHeight,
            std::max(leftDiameter, rightDiameter));
    results.first = height;
    results.second = diameter;
    return results;
}

template <typename T>
int betterDiameter(BTNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    auto results = getHeightDiameter(root);
    return results.second;
}

template <typename T>
bool getPath(BTNode<T>* root, T key, std::vector<T> &v) {
    if (root == nullptr) {
        return false;
    }
    v.push_back(root->data);
    if (root->data == key) {
        return true;
    }
    if (getPath(root->left, key, v) || getPath(root->right, key, v)) {
        return true;
    }
    v.pop_back();
    return false;
}

int main() {
#if 0
    BTNode<int>* root = new BTNode<int>(1);
    root->left = new BTNode<int>(2);
    root->right = new BTNode<int>(3);

    printTree(root);

    delete root;
#endif
#if 0
    BTNode<int>* root = takeInput<int>();
    printTree(root);
    delete root;
#endif
#if 0
    BTNode<int>* root = takeInputByLevel<int>();
    std::cout << "\n------------------------\n";
    printTree(root);
    std::cout << "------------------------\n";
    levelOrderTraversal<int>(root);
    std::cout << "------------------------\n";
    std::cout << "Number of Nodes: " << countNodes<int>(root) << '\n';
    std::cout << "------------------------\n";
    delete root;
#endif
    std::vector<int> preorder {3, 9, 20, 15, 7};
    std::vector<int> inorder  {9, 3, 15, 20, 7};
    std::vector<int> postorder  {9, 3, 15, 20, 7};
#if 0
    BTNode<int>* root = buildTree(preorder, inorder);
    printTree(root);
    delete root;
#endif
#if 0
    BTNode<int>* root = buildTree1(inorder, postorder);
    printTree(root);
    delete root;
#endif
    BTNode<int>* root = buildTree1(inorder, postorder);
    std::vector<int> v;
    if (getPath(root, 20, v)) {
        std::cout << "Found! Path is ";
        for (auto const& ele : v) {
            std::cout << ele << ' ';
        }
    } else {
        std::cout << "Item not found.";
    }
    std::cout << '\n';
    delete root;
}
