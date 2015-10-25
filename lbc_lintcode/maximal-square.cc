/*
题目：24 % Maximal Square 中等

题目大意：
给定一个二维的表格，其中是1和0
问其中全部都是1的正方形最大是多少？

解题思路：
先计算出每个格子往上，往左分别最多有多少个1.然后动归。n*n的复杂度。

遇到的问题：
自从上次知道了单调队列，感觉这种类似的题目，都可以类似的来降低复杂度呢。
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
        vector<vector<int>> h(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> v(matrix.size(), vector<int>(matrix[0].size(), 0));
        h[0][0] = v[0][0] = matrix[0][0];
        for (int i = 1; i < matrix.size(); ++i) {
            h[i][0] = matrix[i][0];
        }
        for (int i = 1; i < matrix[0].size(); ++i) {
            v[0][i] = matrix[0][i];
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 1) {
                    h[i][j] = h[i][j-1] + 1;
                    v[i][j] = v[i-1][j] + 1;
                }
            }
        }
        vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), 0));
        int ret = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            ans[i][0] = h[i][0];
            if (ans[i][0] > ret) {
                ret = ans[i][0];
            }
        }
        for (int i = 1; i < matrix[0].size(); ++i) {
            ans[0][i] = v[0][i];
            if (ans[0][i] > ret) {
                ret = ans[0][i];
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 1) {
                    ans[i][j] = min(min(ans[i-1][j-1], h[i][j-1]), v[i-1][j]) + 1;
                    if (ans[i][j] > ret) {
                        ret = ans[i][j];
                    }
                }
            }
        }
        return ret * ret;
    }
};
