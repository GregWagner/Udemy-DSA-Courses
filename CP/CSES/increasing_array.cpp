#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> arr(n, 0);

    for (int i = 0; i < arr.size(); ++i) {
        std::cin >> arr[i];
    }

    long long answer{};
    long long previous{ arr[0] };
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < previous) {
            answer += previous - arr[i];
            // std::cout << "Previous: " << previous << ", answer: " << answer << '\n';
        }
        previous = std::max(arr[i], previous);
    }
    std::cout << answer << '\n';
}

/*
10
6 10 4 10 2 8 9 2 7 7
     6    8
*/
