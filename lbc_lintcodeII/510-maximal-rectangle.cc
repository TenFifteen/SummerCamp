/*
题目大意：
给定一个二维的01矩阵，问最大的1的矩阵是什么？

解题思路：
化简为一维的最大矩形问题。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param matrix a boolean 2D matrix
     * @return an integer
     */
    int maximalRectangle(vector<vector<bool> > &matrix) {
        // Write your code here
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<int> line(n, 0);
        
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) line[j]++;
                else line[j] = 0;
            }
            
            stack<pair<int, int>> s;
            s.push(make_pair(-1, -1));
            for (int j = 0; j < n; ++j) {
                if (line[j] >= s.top().second) {
                    s.push(make_pair(j, line[j]));
                } else {
                    while (line[j] < s.top().second) {
                        auto cur = s.top(); s.pop();
                        ans = max(ans, (j-s.top().first-1)*cur.second);
                    }
                    s.push(make_pair(j, line[j]));
                }
            }
            
            while (s.size() > 1) {
                auto cur = s.top(); s.pop();
                ans = max(ans, (n-s.top().first-1)*cur.second);
            }
        }
        
        return ans;
    }
};