#include <iostream>

void sort(int a[], int size)
{
    for (int i {}; i <= size - 1; ++i) {
        bool swap {};
        for (int j {}; j <= size - 2; ++j) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                swap = true;
            }
        }
        if (!swap) {
            break;
        }
    }
}

void print(int a[], int n) {
    for (int i {}; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

int main()
{
    int a[] {7, 5, 3, 6, 8};
    sort(a, 5);
    print(a, 5);

    int b[] {1, 2, 3, 4, 5};
    sort(b, 5);
    print(b, 5);

    int c[] {5, 4, 3, 2, 1};
    sort(c, 5);
    print(c, 5);
}
