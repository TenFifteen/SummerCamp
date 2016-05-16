/*
题目大意：
给定一个矩形，把0出现的行和列都赋值为0.

集体思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int m = matrix.size(), n = matrix[0].size();
        
        bool row = false, col = false;
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) {
                col = true;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) {
                row = true;
                break;
            }
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (row) {
            for (int i = 0; i < n; ++i) matrix[0][i] = 0;
        }
        if (col) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};
