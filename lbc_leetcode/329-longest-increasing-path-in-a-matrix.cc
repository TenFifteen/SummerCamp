/*
题目大意：
给定一个二维矩阵，计算其中最长上升子序列。只有上下左右相连才算是相连

解题思路：
dp+dfs

遇到的问题：
好久没写代码了，感觉这次光注意着风格了，好多小细节都没有注意到。

再次阅读：
嗯，解得不错。
*/
class Solution {
private:
    int dfs(vector<vector<int> > &dp, vector<vector<int> > &matrix, int x, int y) {
        if (dp[x][y]) return dp[x][y];
        
        const int ix[] = {-1, 0, 1, 0};
        const int iy[] = {0, 1, 0, -1};
        
        dp[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int new_x = x + ix[i];
            int new_y = y + iy[i];
            
            if (new_x >= 0 && new_x < matrix.size() && 
                new_y >= 0 && new_y < matrix[x].size() && 
                matrix[new_x][new_y] > matrix[x][y]) {
                dp[x][y] = max(dp[x][y], 1 + dfs(dp, matrix, new_x, new_y));
            }
        }
        
        return dp[x][y];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        
        vector<vector<int> > dp(m, vector<int>(n, 0));
        int ans = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(dp, matrix, i, j));
            }
        }
        
        return ans;
    }
};
/*
第二次做：
这次已经可以自己想出解法来了。
*/
class Solution {
    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int x, int y) {
        if (dp[x][y] > 0) return dp[x][y];
        
        const int ix[] = {-1, 0, 1, 0};
        const int iy[] = {0, -1, 0, 1};
        
        dp[x][y] = 1;
        for (int i = 0; i < 4; ++i) {
            int nx = x + ix[i], ny = y + iy[i];
            
            if (nx < 0 || nx >= matrix.size() 
                || ny < 0 || ny >= matrix[0].size() 
                || matrix[nx][ny] >= matrix[x][y]) continue;
                
            dp[x][y] = max(dp[x][y], dfs(matrix, dp, nx, ny) + 1);
        }
        
        return dp[x][y];
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(matrix, dp, i, j));
            }
        }
        
        return ans;
    }
};