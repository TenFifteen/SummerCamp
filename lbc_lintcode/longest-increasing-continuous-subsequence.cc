/*
题目：26 % 最长上升连续子序列 容易

题目大意：
给定一个数组，求最长的连续上升子序列或者连续下降子序列。

解题思路：
见代码

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        // Write your code here
        if (A.size() < 2) return A.size();
        int ret = 1;
        int cur = 1;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > A[i-1]) {
                cur++;
                if (cur > ret) {
                    ret = cur;
                }
            } else {
                cur = 1;
            }
        }
        
        cur = 1;
        for (int i = A.size()-2; i >= 0; --i) {
            if (A[i] > A[i+1]) {
                cur++;
                if (cur > ret) {
                    ret = cur;
                }
            } else {
                cur = 1;
            }
        }
        
        return ret;
    }
};
