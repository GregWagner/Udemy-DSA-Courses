#include <iostream>

struct queue {
    int a[100];
    int len {};

    auto add_end(int value) {
        a[len++] = value;
    }

    auto add_front(int value) {
        // shift right
        for (int i { len - 1 }; i >= 0; --i) {
            a[i + 1] = a[i];
        }
        a[0] = value;
        ++len;
    }

    auto remove_front() {
        int ret { a[0] };
        // shift left
        for (int i { 1 }; i < len; ++i) {
            a[i - 1] = a[i];
        }
        --len;
        return ret;
    }

    auto print() {
        for (int i {}; i < len; ++i) {
            std::cout << a[i] << ' ';
        }
        std::cout << '\n';
    }
};

auto main() -> int {
    queue my_queue;

    my_queue.add_end(10);
    my_queue.add_end(20);
    my_queue.add_end(30);
    my_queue.print();
    my_queue.add_front(1);
    my_queue.add_front(4);
    my_queue.print();

    std::cout << my_queue.remove_front() << '\n';
}