#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class TreeNode {
    public:
        explicit TreeNode(T data) : data {data}{
        }

        ~TreeNode() {
            for (auto & node : children) {
                delete node;
            }
        }

        void addChild(TreeNode* node) {
            children.push_back(node);
        }

        T getData() const {
            return data;
        }

        T data;
        std::vector<TreeNode *> children;
};

TreeNode<int>* takeInput() {
    int rootData {};
    std::cout << "Enter data: ";
    std::cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    std::cout << "Enter number of children of " << rootData << ": ";
    int n {};
    std::cin >> n;

    for (int i {}; i < n; ++i) {
        root->addChild(takeInput());
    }
    return root;
}

TreeNode<int>* takeInputByLevel() {
    std::queue<TreeNode<int>*> q;

    int rootData {};
    std::cout << "Enter root data: ";
    std::cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();

        std::cout << "Enter numbber of children of " << node->data << ": ";
        int n;
        std::cin >> n;
   
        for (int i {}; i < n; ++i) {
            // create
            std::cout << "Enter " << i + 1 << "th child of " << node->data << ": ";
            int childData;
            std::cin >> childData;
            auto child = new TreeNode<int>(childData);

            // push
            q.push(child);

            // connect
            node->addChild(child);
        }
    }
    return root;
}

void printTree(TreeNode<int>* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->getData() << ": ";
    for (auto & node : root->children) {
        std::cout << node->data << ' ';
    }
    std::cout << '\n';
    for (size_t i {}; i < root->children.size(); ++i) {
        printTree(root->children[i]);
    }
}

void printTreeByLevel(TreeNode<int>* root) {
    std::queue<TreeNode<int>*> q;

    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();

        std::cout << node->data << ": ";
   
        for (size_t i {}; i < node->children.size(); ++i) {
            q.push(node->children[i]);
            std::cout << node->children[i]->data << ' ';
        }
        std::cout << '\n';
    }
}

int countNodes(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }
    int answer {1};
    for (size_t i {}; i < root->children.size(); ++i) {
        answer += countNodes(root->children[i]);
    }
    return answer;
}

int heightOfTree(TreeNode<int>* root) {
    int answer {};
    for (size_t i {}; i < root->children.size(); ++i) {
        answer = std::max(answer, heightOfTree(root->children[i]));
    }
    return answer + 1;
}

void printAtDepth(int k, TreeNode<int>* root) {
    if (k == 0) {
        std::cout << root->data << '\n';
        return;
    }
    for (size_t i {}; i < root->children.size(); ++i) {
        printAtDepth(k - 1, root->children[i]);        
    }
}

int countLeafNodes(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->children.empty()) {
        return 1;
    }
    int answer {};
    for (size_t i {}; i < root->children.size(); ++i) {
        answer += countLeafNodes(root->children[i]);
    }
    return answer;
}

void preorderTraversal(TreeNode<int>* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << ' ';
    for (size_t i {}; i < root->children.size(); ++i) {
        preorderTraversal(root->children[i]);
    }
}

void postorderTraversal(TreeNode<int>* root) {
    if (root == nullptr) {
        return;
    }
    for (size_t i {}; i < root->children.size(); ++i) {
        postorderTraversal(root->children[i]);
    }
    std::cout << root->data << ' ';
}

int main() {
#if 0
    auto root = new TreeNode<int>(1);
    root->children.push_back(new TreeNode<int>(2));
    root->children.push_back(new TreeNode<int>(3));
#endif
    auto* root = takeInputByLevel();
    //printTree(root);
    printTreeByLevel(root);
    std::cout << "Node Count: " << countNodes(root) << '\n';
    std::cout << "Number of Leaf Nodes: " << countLeafNodes(root) << '\n';
    std::cout << "Tree Height: " << heightOfTree(root) << '\n';

    printAtDepth(2, root);

    std::cout << "Preorder Traversal\n";
    preorderTraversal(root);
    std::cout << '\n';

    std::cout << "Postorder Traversal\n";
    postorderTraversal(root);
    std::cout << '\n';

    delete root;
}
