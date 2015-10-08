/*
题目：44 % 寻找峰值 中等

题目大意：
给定一个数组，其中满足每个数都不同，而且A[0] < A[1];
A[n-2] > A[n-1];找到一个峰值

解题思路：
二分

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int left = 0, right= A.size()-1;
        while (left <= right) {
            int mid = left + (right-left+1)/2;
            if (A[mid] > A[mid-1] && A[mid] > A[mid+1]) return mid;
            if (A[mid] < A[mid-1]) right = mid;
            else left = mid;
        }
        return left;
    }
};

