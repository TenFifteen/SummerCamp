/*
题目：33 % 矩阵归零 中等

题目大意：
给定一个二维数组，如果其中有一个元素为0， 那么就将该行该列都设置为0

解题思路：
遍历

遇到的问题：
没有问题。
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
        bool row = false, col = false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                col = true;
                break;
            }
        }
        for (int i = 0; i < matrix[0].size(); ++i) {
            if (matrix[0][i] == 0) {
                row = true;
                break;
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < matrix[0].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix[0].size(); ++i) {
            if (matrix[0][i] == 0) {
                for (int j = 1; j < matrix.size(); ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (row) {
            for (int i = 0; i < matrix[0].size(); ++i) {
                matrix[0][i] = 0;
            }
        }
        if (col) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
