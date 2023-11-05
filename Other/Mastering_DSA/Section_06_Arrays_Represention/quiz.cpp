#include <cstdio>
#include <iostream>

// Question 1
void fun1() {
    // int A[1...10][1...15] (1 byte each)
    // L0 = 100, w = 1
    // Address(A[i][j] = L0 + (i - 1) * n + (j - 1)
    //                   100 + (i - 1) * 15 + j - 1
    //                   100 + 15i - 15 + j - 1
    //                   84 + 15i + j
}

// Question 2
void fun2() {
    unsigned x[4] [3] {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    printf("%u\n%u\n%u\n", x + 3, *(x + 3), *(x + 2) +3);

    // L0 = 2000, sizeof(int) = 4
}

// Question 4
void fun4() {

}

int main() {
    fun2();
}
