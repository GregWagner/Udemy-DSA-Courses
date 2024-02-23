#include <iostream>
#include <vector>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : data {data}, left {}, right {} {}
};

int minValue(TreeNode* root) {
    if (root == nullptr) {
        return -1;
    }

    while (root->left != nullptr) {
        root = root->left;
    }
    return root->value;
}

int maxValue(TreeNode* root) {
    if (root == nullptr) {
        return -1;
    }

    while (root->right != nullptr) {
        root = root->right;
    }
    return root->value;
}

int rangeSumBST(TreeNode* root, int low, int high) {
    if (root == nullptr) {
        return 0;
    }
    int sum {};
    if (root->value >= low && root->value <= high) {
        sum += root->value;
    }

    if (high < root->value) {
        sum += rangeSumBST(root->left, low, high);
    } else if (low > root->value) {
        sum += rangeSumBST(root->right, low, high);
    } else {
        sum += rangeSumBST(root->left, low, high);
        sum += rangeSumBST(root->right, low, high);
    }
    return sum;
}

// Do inorder (left, root, right) traversal and make sure it is sorted
// or
// check the constraint of every node
bool validateHelper(TreeNode* root, long long minValue=-10000000000, long long maxValue=10000000000) {
    if (root == nullptr) {
        return true;
    }

    bool leftValid = validateHelper(root->left, minValue, root->value);
    bool rightValid = validateHelper(root->right, root->value, maxValue);

    return leftValid && rightValid && root->value > minValue
        && root->value < maxValue;
}

bool validateBST(TreeNode* root) {
    return validateHelper(root);
}

// Create a balanced BST from sorted array
TreeNode* sortedArrayToBSTHelper(std::vector<int>& arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    TreeNode* node = new TreeNode(arr[mid]);
    node->left = sortedArrayToBSTHelper(arr, start, mid - 1);
    node->right = sortedArrayToBSTHelper(arr, mid + 1, end);

    return node;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
}


int main() {

}
