/*
题目大意：
给定一个旋转过的数组，查找某个数字是否在其中。

解题思路：
二分，分类讨论。

遇到的问题：
没有。
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
            int mid = left + (right-left)/2;
            if (A[mid] == target) return mid;
            else if (A[mid] < target) {
                if (A[left] > A[right] && A[mid] < A[left] && A[right] < target) right = mid-1;
                else left = mid+1;
            } else {
                if (A[left] > A[right] && A[mid] > A[left] && A[left] > target) left = mid+1;
                else right = mid-1;
            }
        }
        
        return -1;
    }
};