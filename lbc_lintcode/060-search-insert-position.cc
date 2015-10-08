/*
题目：29 % 搜索插入位置 容易

题目大意：
给定一个排序的无重复的数组，给定一个数字，问将该数字插入到数组中的位置

解题思路：
二分

遇到的问题：
没有问题。
*/
class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if (A.size() == 0) return 0;
        int left = 0, right = A.size()-1;
        while (left <= right) {
            if (A[left] > target) return left;
            if (A[right] < target) return right+1;
            int mid = left + (right-left+1)/2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] < target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return left;
    }
};
