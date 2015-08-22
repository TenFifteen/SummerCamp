/*
题目：29 % 搜索二维矩阵 II 中等

题目大意：
给定一个二维矩阵，其中每行每列中的数字均不相同。
每行每列都是排序的。
给定一个target，在（m+n）的时间内找到target的数目

解题思路：
二分，不断的减小搜索区间。

遇到的问题：
不知道我的算法的时间复杂度是多少啊。
*/
class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int ans = 0;
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int row = 0, col = matrix[0].size()-1;
        while (col >= 0 && row < matrix.size()) {
            int left = 0, right = col;
            while (left <= right) {
                int mid = left + (right-left+1)/2;
                if (matrix[row][mid] == target) {
                    ans++;
                    col = mid-1;
                    break;
                } else if (matrix[row][mid] < target) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
            if (left == right) {
                if (matrix[row][left] >= target) {
                    col = left-1;
                } else {
                    col = left;
                }
            }
            row++;
        }
        return ans;
    }
};

