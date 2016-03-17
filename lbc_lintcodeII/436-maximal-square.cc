/*
题目大意：
给定一个二维矩阵，其中为0和1.问其中由1组成的最大的正方形的面积是多少？

解题思路：
动归。

遇到的问题：
返回值搞错了。第一次反悔了dp[n-1]，第二次反悔了ans
*/
class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> col(n, 0), dp(n, 0);
        
        for (int i = 0; i < m; ++i) {
            vector<int> row(n, 0);
            row[0] = matrix[i][0];
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j]) row[j] = row[j-1]+1;
            }
            
            for (int j = n-1; j > 0; --j) {
                if (matrix[i][j]) col[j] += 1;
                else col[j] = 0;
                
                dp[j] = min(dp[j-1]+1, min(row[j], col[j]));
                ans = max(ans, dp[j]);
            }
            dp[0] = matrix[i][0];
            ans = max(ans, dp[0]);
        }
        
        return ans*ans;
    }
};