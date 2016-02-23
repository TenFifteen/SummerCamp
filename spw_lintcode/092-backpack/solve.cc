#include <iostream>
#include <vector>

using namespace std;


/**
 * Problem: Given n items with size Ai, an integer m denotes the size
 *          of a backpack. How full you can fill this backpack.
 * Solve: dp for the capacity of the backpack.
 * Tips: 1. the size of dp vector.
 *       2. When iterator on j, only need  to A[i], or the backpack will
 *          not hold.
 */
class Solution {
    public:
        /**
         * @param m: An integer m denotes the size of a backpack
         * @param A: Given n items with size A[i]
         * @return: The maximum size
         */
        int backPack(int m, vector<int> A) {
            // write your code here
            vector<int> dp(m+1, 0);

            for (int i = 0; i < A.size(); ++i) {
                for (int j = m; j >= A[i]; --j) {
                    dp[j] = max(dp[j], dp[j-A[i]] + A[i]);
                }
            }

            return dp[m];
        }
};
