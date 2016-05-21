/*
题目大意：
给定一个二维矩阵。按照顺时针的顺序将其打印出来。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0) return ans;
        
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bot = m - 1;
        while (left <= right && top <= bot) {
            for (int i = left; i <= right; ++i) ans.push_back(matrix[top][i]);
            top++;
            
            if (left <= right) for (int i = top; i <= bot; ++i) ans.push_back(matrix[i][right]);
            right--;
            
            if (top <= bot) for (int i = right; i >= left; --i) ans.push_back(matrix[bot][i]);
            bot--;
            
            if (left <= right) for (int i = bot; i >= top; --i) ans.push_back(matrix[i][left]);
            left++;
        }
        
        return ans;
    }
};
