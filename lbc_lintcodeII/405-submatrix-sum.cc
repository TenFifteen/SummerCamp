/*
题目大意：
给定一个矩阵，找到其中一个子矩阵的和为0。

解题思路：
见代码。

遇到的问题：
还是没有想出来。一开始还写成了方阵的。。。

*/
class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
        vector<vector<int>> ans(2, vector<int>(2));
        if (matrix.size() == 0 || matrix[0].size() == 0) return ans;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<long long>> sum(m+1, vector<long long>(n+1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        for (int k = 1; k <= m; ++k) {
            for (int i = k; i <= m; ++i) {
                unordered_map<long long, int> hash;
                hash[0L] = 0;
                for (int j = 1; j <= n; ++j) {
                    long long now = sum[i][j] - sum[i-k][j];
                    if (hash.find(now) != hash.end()) {
                        ans[0][0] = i-k;
                        ans[0][1] = hash[now];
                        ans[1][0] = i-1;
                        ans[1][1] = j-1;
                        return ans;
                    }
                    hash[now] = j;
                }
            }
        }
        
        return ans;
    }
};
