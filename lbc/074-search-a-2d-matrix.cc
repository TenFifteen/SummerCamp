/*
题目大意：
给定一个二维数组，数组的每一行是排序的。并且每一行的第一个元素大于上一行的最后一个元素。

解题思路：
二分查找。

遇到的问题：
一次通过。
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)return false;
        int left = 0, right = matrix.size()*matrix[0].size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            int row = mid/matrix[0].size();
            int col = mid%matrix[0].size();
            if(matrix[row][col] == target){
                return true;
            }else if(matrix[row][col] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return false;
    }
};