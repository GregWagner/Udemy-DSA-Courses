#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Node {
public:
    explicit Node(char data)
        : data{ data } {
    }

    friend class Trie;

private:
    char data;
    std::unordered_map<char, Node*> map;
    bool isTerminal{};
};

class Trie {
public:
    Trie() {
        root = new Node('\0');
    }

    void insert(const std::string& word) {
        Node* temp = root;
        for (char ch : word) {
            if (temp->map.count(ch) == 0) {
                Node* node = new Node(ch);
                temp->map[ch] = node;
            }
            // go to the next node
            temp = temp->map[ch];
        }
        temp->isTerminal = true;
    }

    bool search(const std::string& word) {
        Node* temp = root;
        for (char ch : word) {
            if (temp->map.count(ch) == 0) {
                return false;
            }
            // go to the next node
            temp = temp->map[ch];
        }
        return temp->isTerminal;
    }

private:
    Node* root;
};

int main() {
    std::vector<std::string> words{ "apple", "ape", "mango", "news", "mo" };
    Trie tree;

    for (const auto& word : words) {
        tree.insert(word);
    }

    std::vector<std::string> queries{ "apple", "banna", "new", "mango" };
    for (const auto& word : queries) {
        std::cout << (tree.search(word) ? "Yes\n" : "No\n");
    }
}
