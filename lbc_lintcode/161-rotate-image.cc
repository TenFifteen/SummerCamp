/*
题目：35 % 旋转图像 中等

题目大意：
给定一个n*n的图像，将其顺时针旋转90度

解题思路：
直接旋转。

遇到的问题：
还是边界问题。
*/
class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        // write your code here
        int n = matrix.size();
        for (int i = 0; i < (n+1)/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }
};
