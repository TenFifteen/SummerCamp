/*
题目大意：
给定一个n*n的矩形，将其顺时针翻转。

解题思路：
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
    void rotate(vector<vector<int> > &matrix) {
        // write your code here
        int n = matrix.size();
        
        for (int i = 0; i < (n+1)/2; ++i) {
            for (int j = 0; j < n/2; ++j) {
                int now = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = now;
            }
        }
    }
};
