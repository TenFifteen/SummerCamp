/*
题目大意：
给定一个数组，找到一个峰值元素的下标。
首先数组保证第一个和最后一个不是峰值；另外就是相邻的元素不相等。

解题思路：
二分。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int left = 1, right = A.size()-2;
        
        while (left < right) {
            int mid = left + ((right-left)>>1);
            if (A[mid] > A[mid-1] && A[mid] > A[mid+1]) return mid;
            else if (A[mid-1] > A[mid]) right = mid-1;
            else left = mid+1;
        }
        
        return left;
    }
};
