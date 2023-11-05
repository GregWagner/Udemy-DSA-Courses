#include <string>
#include <iostream>
#include <vector>

class Node {
    public:
        Node() {}

        Node* child[26] {};
        bool isTerminal {};
};

void add(const std::string& word, Node* trie) {
    for (char ch : word) {
        if (trie->child[ch - 'a'] == nullptr) {
            trie->child[ch - 'a'] = new Node();
        }
        trie = trie->child[ch - 'a'];
    }
    trie->isTerminal = true;
}

bool search(const std::string& word, Node* trie) {
    for (char ch : word) {
        if (trie->child[ch - 'a'] == nullptr) {
            return false;
        }
        trie = trie->child[ch - 'a'];
    }
    return trie->isTerminal;
}

int main() {

    std::vector<std::string> words {"apple", "ape", "mango", "news", "mo"};
    Node* tree = new Node();

    for (const auto& word : words) {
        add(word, tree);
    }

    std::vector<std::string> queries {"apple", "banna", "new", "mango"};
    for (const auto& word : queries) {
        std::cout << (search(word, tree) ? "Yes\n" : "No\n");
    }
}
