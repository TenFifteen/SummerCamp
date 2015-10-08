/*
题目：32 % k数和 II 中等

题目大意：
跟89题是一样的，只是这次要输出结果。所以就是反向追踪了。

解题思路：
动归+反向追踪

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>>(A.size()+1, vector<int>(target+1, 0)));
        for (int i = 0; i < A.size(); ++i) {
            if(A[i] <= target) {
                for (int j = i; j < A.size(); ++j) {
                    dp[1][j+1][A[i]] = 1;
                }
            }
        }
        for (int i = 2; i <= k; ++i) {
            for (int j = i; j <= A.size(); ++j) {
                for (int v = 1; v <= target; ++v) {
                    dp[i][j][v] = dp[i][j-1][v];
                    if (A[j-1] <= v) {
                        dp[i][j][v] += dp[i-1][j-1][v-A[j-1]];
                    }
                }
            }
        }
        vector<vector<int>> ans;
        sub(dp, k, A.size(), target, vector<int>(), ans, A);
        return ans;
    }
    
    void sub(vector<vector<vector<int>>> &dp, int i, int j, int k, vector<int> cur, vector<vector<int>> &ans, vector<int> &A) {
        if (k == 0 && i == 0) {
            for (int i = 0; i < cur.size()/2; ++i) {
                swap(cur[i], cur[cur.size()-1-i]);
            }
            ans.push_back(cur);
            return;
        }
        if (k <= 0 || j <= 0) return;
        sub(dp, i, j-1, k, cur, ans, A);
        cur.push_back(A[j-1]);
        sub(dp, i-1, j-1, k-A[j-1], cur, ans, A);
    }
};

