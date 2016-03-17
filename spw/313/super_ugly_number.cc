/**
 * Problem: Write a program to find the nth super ugly number.
 *          Super ugly numbers are positive numbers whose all prime factors
 *          are in the given prime list primes of size k. For example,
 *          [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence
 *          of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
 * Solve: the same as factor 2, 3, 5
 * Tips: no
 */
int nthSuperUglyNumber(int n, vector<int>& primes) {
    int len = primes.size();

    vector<int> pos(len, 0);
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        int next = INT_MAX;
        for (int j = 0; j < len; ++j) {
            next = min(next, dp[pos[j]] * primes[j]);

        }
        dp[i] = next;

        for (int j = 0; j < len; ++j) {
            if (next % primes[j] == 0) ++pos[j];

        }

    }

    return dp[n-1];

}
