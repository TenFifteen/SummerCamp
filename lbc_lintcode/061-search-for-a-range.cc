/*
题目：20 % 搜索区间 中等

题目大意：
给定一个排序的有重复的数组，一个target，求在该数组中的区间

解题思路：
二分

遇到的问题：
没有问题。
*/
class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> ans(2, -1);
        if (A.size() == 0) return ans;
        int left = 0, right = A.size()-1;
        while (left <= right) {
            int mid = left + (right-left+1)/2;
            if (A[mid] == target) {
                while (A[left] != target) left++;
                while (A[right] != target) right--;
                ans[0] = left;
                ans[1] = right;
                return ans;
            } else if (A[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ans;
    }
};
