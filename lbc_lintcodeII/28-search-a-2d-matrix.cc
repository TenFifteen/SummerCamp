/*
题目大意：
给定一个二维数组，排序的。查找一个target是否存在

解题思路：
二分

遇到的问题：
没有。
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
        
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m*n-1;
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            int x = mid/n, y = mid%n;
            if (matrix[x][y] == target) return true;
            else if (matrix[x][y] < target) left = mid+1;
            else right = mid-1;
        }
        
        return false;
    }
};
