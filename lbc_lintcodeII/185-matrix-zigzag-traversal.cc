/*
题目大意：
给定一个二维的矩阵，按照之字型进行遍历。

解题思路：
见代码。

遇到的问题：
一开始两个j的方向搞反了，都写成了j++了。
*/
class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        // write your code here
        vector<int> ans;
        
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        if (n == 0) return ans;
        
        for (int i = 0; i < m+n-1; ++i) {
            if (i & 0x1) {
                int j = i >= n-1 ? n-1 : i;
                for ( ; j >= 0 && i-j < m; --j) {
                    ans.push_back(matrix[i-j][j]);
                }
            } else {
                int j = i >= m-1 ? m-1 : i;
                for ( ;j >= 0 && i-j < n; --j) {
                    ans.push_back(matrix[j][i-j]);
                }
            }
        }
        
        return ans;
    }
};