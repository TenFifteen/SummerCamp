/*
题目大意：
给定一个二维数组，每一行，从左到右排序；每一列，从上到下排序。求一个数是否在矩阵中。

解题思路：
二分查找。每次将矩阵划分为四个小矩阵。

遇到的问题：
竟然一次通过。
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)return false;
        return sub(matrix, 0, matrix[0].size()-1, 0, matrix.size()-1, target);
    }
    
    bool sub(vector<vector<int>> &matrix, int left, int right, int top, int bot, int target){
        if(left > right || top > bot)return false;
        if(left == right){
            while(top <= bot){
                int mid = top + (bot-top)/2;
                if(matrix[mid][left] == target)return true;
                if(matrix[mid][left] < target)top = mid+1;
                else bot = mid-1;
            }
            return false;
        }
        if(top == bot){
            while(left <= right){
                int mid = left + (right-left)/2;
                if(matrix[top][mid] == target)return true;
                if(matrix[top][mid] < target)left = mid+1;
                else right = mid-1;
            }
            return false;
        }
        
        int h_mid = top + (bot-top)/2;
        int v_mid = left +(right-left)/2;
        bool ret = false;
        if(matrix[top][left] <= target && matrix[h_mid][v_mid] >= target)
            ret |= sub(matrix, left, v_mid, top, h_mid, target);
        if(ret == false && matrix[top][v_mid+1] <= target && matrix[h_mid][right] >= target)
            ret |= sub(matrix, v_mid+1, right, top, h_mid, target);
        if(ret == false && matrix[h_mid+1][left] <= target && matrix[bot][v_mid] >= target)
            ret |= sub(matrix, left, v_mid, h_mid+1, bot, target);
        if(ret == false && matrix[h_mid+1][v_mid+1] <= target && matrix[bot][right] >= target)
            ret |= sub(matrix, v_mid+1, right, h_mid+1, bot, target);
        return ret;
    }
};