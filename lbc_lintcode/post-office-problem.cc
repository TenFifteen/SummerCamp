/*
题目：23 % Post Office Problem 困难

题目大意：
给定一个office位置的信息，他们在一条直线上。给定k个点，问，所有office到k
个点中最近的距离总和是多少？

解题思路：
动态规划。
有一条很重要的性质。就是在[i,j]区间内要是有一个点的话，那么这个点一定可以是
i+(j-i)/2

遇到的问题：
这道题据说有n的平方的解法。但是我实在是想不到了。
回头可以多看看别人的解法。
*/
class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        // Write your code here
        if (A.size() <= k) return 0;
        vector<vector<int> > dp(A.size(), vector<int>(k, INT_MAX));
        
        sort(A.begin(), A.end());
        
        vector<vector<int> > cost(A.size(), vector<int>(A.size()));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i+1; j < A.size(); ++j) {
                int mid = i + (j-i)/2;
                int c = 0;
                for (int k = i; k <= j; ++k) {
                    c += abs(A[k] - A[mid]);
                }
                cost[i][j] = c;
            }
        }
     
        dp[0][0] = 0;
        for (int i = 1; i < A.size(); ++i) {
            dp[i][0] = cost[0][i];
        }
        
        for (int j = 1; j < k; ++j) {
            for (int i = 0; i < A.size(); ++i) {
                if (i <= j) {
                    dp[i][j] = 0;
                } else {
                    for (int x = j-1; x < i; ++x) {
                        dp[i][j] = min(dp[i][j], dp[x][j-1] + cost[x+1][i]);
                    }
                }
            }
        }
        
        return dp[A.size()-1][k-1];
    }
};
