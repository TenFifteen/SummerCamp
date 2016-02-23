#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Given a string s, cut s into some substrings that every substrings is a
 *          palindrome. Return the minimum cuts needed for the palindrome.
 * Solve: dp for the length of the string s.
 * Tips: 1. The size of DP vector is s.size() + 1, because in the boundary, we use dp[0]=-1;
 *       2. see comments below.
 */
class Solution {
    public:
        /**
         * @param s a string
         * @return an integer
         */
        int minCut(string s) {
            // write your code here
            int n = s.size();
            vector<int> dp(n+1, 0);
            for (int i = 0; i <= n; ++i) {
                dp[i] = i-1;
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; i + j < n && i - j >= 0 && s[i+j] == s[i-j]; ++j) {
                    dp[i+j+1] = min(dp[i+j+1], dp[i-j]+1);
                }

                for (int j = 0; i + j + 1 < n && i - j >= 0 && s[i+j+1] == s[i-j]; ++j) {
                    // i+j+1 && i-j or i+j && i-j-1 are all OK
                    dp[i+j+2] = min(dp[i+j+2], dp[i-j]+1);
                }
            }

            return dp[n];
        }
};

