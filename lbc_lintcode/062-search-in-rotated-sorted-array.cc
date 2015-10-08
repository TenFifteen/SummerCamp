/*
题目：29 % 搜索旋转排序数组 中等

题目大意：
给定一个排序的数组，该数组右移了一部分，给定一个target，问是否在该数组中

解题思路：
二分，但是得分清楚各种情况

遇到的问题：
一开始对于最后一种情况就没有考虑太清楚。
*/
class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        if (A.size() == 0) return -1;
        int left = 0, right = A.size()-1;
        while (left <= right) {
            int mid = left + (right-left+1)/2;
            if (A[mid] == target) return mid;
            if (A[mid] < target) {
                if (A[left] < A[right]) {
                    left = mid+1;
                } else if (A[mid] < A[right]) {
                    if (A[right] >= target) {
                        left = mid+1;
                    } else {
                        right = mid-1;
                    }
                } else {
                    left = mid+1;
                }
            } else {
                if (A[left] > A[right] && A[mid] > A[right] && A[left] > target) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};
