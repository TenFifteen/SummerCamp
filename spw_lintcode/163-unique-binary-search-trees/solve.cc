/**
 * Problem: Given n, how many structurally unique BSTs
 *          (binary search trees) that store values 1...n?
 * Solve: memorize recursive
 * Tips: no
 */
#include <vector>
#include <iostream>

using namespace std;


int sub(int n, vector<int> &dp) {
    if (dp[n] != 0) return dp[n];

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int left = sub(i-1, dp);
        int right = sub(n-i, dp);

        ans += left * right;
    }

    return dp[n] = ans;
}

int numTrees(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    return sub(n, dp);
}
int main()
{
    cout << numTrees(5) << endl;
    return 0;
}
