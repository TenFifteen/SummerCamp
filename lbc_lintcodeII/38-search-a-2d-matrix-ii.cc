/*
题目大意：
给定一个二维数组，其中每一行都是排序的，每一列都是排序的。而且同一行或者同一列没有
重复的数字。
给定一个target，计算二维数组中出现了多少次target

解题思路：
从右上角开始，不断的缩小搜索范围。

遇到的问题：
没有问题。
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
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        
        int m = matrix.size(), n = matrix[0].size(), i = 0, j = n-1, cnt = 0;
        while (i < m && j >= 0) {
            if (matrix[i][j] > target) {
                j--;
            } else if (matrix[i][j] < target) {
                i++;
            } else {
                cnt++;
                i++;
                j--;
            }
        }
        
        return cnt;
    }
};
