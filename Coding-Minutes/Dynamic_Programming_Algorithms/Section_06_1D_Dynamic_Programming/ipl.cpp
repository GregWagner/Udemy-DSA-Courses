#include <bits/stdc++.h>

int main() {
    int n {};
    std::cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    // dp[i][0]  represents maximum earnings from [0...i] if
    // Nikhil doesnt play on the ith day
    // dp[i][1] represents maximum earnings from [0...i]
    // if Nikhil plays on the ith day
    int dp[n][2];
    memset(dp, 0, sizeof(dp));

    // base case for the 0th day
    dp[0][0] = 0; // 0 if he doesnt play
    dp[0][1] = a[0]; // 1 if he plays

    int ans = 0;

    for (int i = 1; i < n; i++) {
        // case when he doesn't play on the ith day
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);

        // case when he plays on the ith day

        // so if we include the ith day we can get two cases
        // we need to maintain the fact that he doesnt play 3 times straight
        // Case 1)
        //    include ith day and don't include (i-1)th day
        //    therefpre we take best answer of (i-2)th day and add a[i] to it
        // this handles cases like '...101' , '...001'.
        dp[i][1] = a[i] + (i - 2 >= 0 ? std::max(dp[i - 2][0], dp[i - 2][1]) : 0);

        // Case 2)
        //	  include ith and dont include (i-1)th day
        // 	  therefore we take best answer if (i-2) is not include and
        // 	  add a[i-1] and a[i] to it
        // 	  this handles cases like '...011'
        dp[i][1] = std::max(dp[i][1], a[i - 1] + a[i] + (i - 2 >= 0 ? dp[i - 2][0] : 0));
    }

    // finally, the max answer would come if we end on last day or
    // we end sometime before which indirectly means end day not included.
    // therefore max of two.

    std::cout << std::max(dp[n - 1][1], dp[n - 1][0]);
}
