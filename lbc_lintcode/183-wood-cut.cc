/*
题目：19 % 木材加工 中等

题目大意：
给定n个木头的长度，然后问如果要切割出至少k条一样长的木材，问最长的长度是多少？

解题思路：
二分

遇到的问题：
边界，L有可能为空；如果没有分割办法，应该返回0
*/
class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        if (L.size() == 0) return 0;
        int left = 1;
        int right = L[0];
        for (int i = 1; i < L.size(); ++i) {
            if (L[i] > right) {
                right = L[i];
            }
        }
        int ret = 0;
        while (left <= right) {
            int mid = left + (right-left+1)/2;
            int sum = 0;
            for (auto l : L) {
                sum += l/mid;
            }
            if (sum >= k) {
                if (mid > ret) {
                    ret = mid;
                }
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return ret;
    }
};
