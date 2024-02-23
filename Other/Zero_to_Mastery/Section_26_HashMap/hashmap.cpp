/*
 * Hashmap with Separate Chaining
 */
#include <string>
#include <iostream>

template <typename T>
struct Node {
    std::string key;
    T value;
    Node* next {};

    Node(std::string key, T value): key {key}, value {value}, next {} {
    }

    ~Node() {
        delete next;
    }
};

template <typename T>
class map {
    public:
        map() : count {}, numberOfBumkets {5} {
            buckets = new Node<T>*[numberOfBumkets] {};
        }

        ~map() {
            for (int i {}; i < numberOfBumkets; ++i) {
                delete buckets[i];
            }
            delete [] buckets;
        }

        int size() const {
            return count;
        }

        T getValue(std::string key) {
            int bucketIndex {hash(key)};
            Node<T>* head {buckets[bucketIndex]};
            while (head != nullptr) {
                if (head->key == key) {
                    return head->value;
                }
                head = head->next;
            }
            return 0;
        }

        void insert(std::string key, T value) {
            int bucketIndex {hash(key)};
            Node<T>* head {buckets[bucketIndex]};

            // if key already inserted, update the value
            while (head != nullptr) {
                if (head->key == key) {
                    head->value = value;
                    return;
                }
                head = head->next;
            }

            Node<T>* node = new Node<T>(key, value);
            node->next = buckets[bucketIndex];
            buckets[bucketIndex] = node;
            ++count;

            double loadFactor {static_cast<float>(count) / numberOfBumkets};
            if (loadFactor > 0.7) {
                rehash();
            }
        }

        T remove(std::string key) {
            int bucketIndex {hash(key)};
            Node<T>* head {buckets[bucketIndex]};
            Node<T>* prev {};
            while (head != nullptr) {
                if (head->key == key) {
                    if (prev == nullptr) {
                        buckets[bucketIndex] = head->next;
                    } else {
                        prev->next = head->next;
                    }
                    T value = head->value;
                    head->next = nullptr;
                    delete head;
                    --count;
                    return value;
                }
                prev = head;
                head = head->next;
            }
            return 0;
        }

        double getLoadFactor() {
            return static_cast<float>(count) / numberOfBumkets;
        }

    private:
        Node<T>** buckets;
        int count {};
        int numberOfBumkets {};

        int hash(std::string key) {
            int hashCode {};
            int base {1};
            int prime {37};

            for (int i = key.size() - 1; i >= 0; --i) {
                hashCode += (key[i] * base) % numberOfBumkets;
                base *= prime % numberOfBumkets;
            }
            return hashCode % numberOfBumkets;
        }

        void rehash() {
            std::cout << "Rehashing\n";
            Node<T>** temp {buckets};
            int oldBucketSize {numberOfBumkets};
//          int oldCount {count};

            numberOfBumkets *= 2;
            buckets = {new Node<T>*[numberOfBumkets] {}};
            count = 0;

            for (int i {}; i < oldBucketSize; ++i) {
                Node<T>* head = temp[i];
                while (head != nullptr) {
                    std::string key = head->key;
                    int value = head->value;
                    insert(key, value);
                    head = head->next;
                }
            }
            for (int i {}; i < oldBucketSize; ++i) {
                delete temp[i];
                
            }
            delete [] temp;
        }
};

int main() {
    map<int> m;
    for (int i {}; i < 10; ++i) {
        char c = '0' + i;
        std::string key = "abc";
        key += c;
        int value {i + 1};
        m.insert(key, value);
        std::cout << "Inserted " << i << ", load factor: " << m.getLoadFactor() << '\n';
    }
    std::cout << "Map Size is " << m.size() << '\n';

    m.remove("abc1");
    m.remove("abc6");
    std::cout << "---------------------\n";

    for (int i {}; i < 10; ++i) {
        char c = '0' + i;
        std::string key = "abc";
        key += c;
        std::cout << "Key: " << key << ", value: " << m.getValue(key) << '\n';
    }
}
