/*
题目：23 % 矩阵的之字型遍历 容易

题目大意：
给定一个二维数组，进行zigzag的遍历

解题思路：
直接进行模拟

遇到的问题：
就是注意边界条件。
不过一开始还是将m和n搞反了。。
*/
class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> ret;
        if (matrix.size() == 0 || matrix[0].size() == 0) return ret;
        int m = matrix.size();
        int n = matrix[0].size();
        bool dir = true;
        for (int i = 0; i < m+n-1; ++i) {
            if (dir) {
                int col_start = min(i, m-1);
                int col_end = 0;
                if (i >= n) {
                    col_end = i-n+1;
                }
                for (int c = col_start; c >= col_end; --c) {
                    ret.push_back(matrix[c][i-c]);
                }
            } else {
                int col_start = 0;
                if (i >= n) {
                    col_start = i-n+1;
                }
                int col_end = min(i, m-1);
                for (int c = col_start; c <= col_end; ++c) {
                    ret.push_back(matrix[c][i-c]);
                }
            }
            dir = !dir;
        }
        return ret;
    }
};
