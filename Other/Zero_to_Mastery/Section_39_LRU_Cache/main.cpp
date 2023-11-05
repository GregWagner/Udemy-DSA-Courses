#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) : capacity {capacity} {
        keys = new std::list<int> (3000);
    }
    
    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }
        keys->remove(key);
        keys->push_front(key);
        return m[key];
    }
    
    void put(int key, int value) {
        if (m.find(key) == m.end()) {
            if (keys->size() == capacity) {
                int item = keys->back();
                keys->pop_back();
                m.erase(item);
            } 
            m[key] = value;
            keys->push_front(key);
        } else {
            keys->remove(key);
            keys->push_front(key);
            m[key] = value;
        }
    }

private:
    int capacity;
    std::unordered_map<int, int> m;
    std::list<int>* keys;
};

int main() {
    std::cout << std::boolalpha;
    LRUCache* obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    std::cout << (obj->get(1) == 1) << '\n';
    obj->put(3, 3);
    std::cout << (obj->get(2) == -1) << '\n';
    obj->put(4, 4);
    std::cout << (obj->get(1) == -1) << '\n';
    std::cout << (obj->get(3) == 3) << '\n';
    std::cout << (obj->get(4) == 4) << '\n';
}
