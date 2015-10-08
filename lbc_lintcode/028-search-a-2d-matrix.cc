/*
题目：28 % 搜索二维矩阵 容易

题目大意：
给定一个排序的二维矩阵，搜索target是否在矩阵中。实际上这个矩阵可以看做是一维的

解题思路：
二分搜索

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int beg = 0, end = matrix.size()*matrix[0].size()-1;
        while (beg <= end) {
            int mid = beg + (end-beg+1)/2;
            int x = mid/matrix[0].size();
            int y = mid%matrix[0].size();
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] < target) beg = mid+1;
            else end = mid-1;
        }
        return false;
    }
};

