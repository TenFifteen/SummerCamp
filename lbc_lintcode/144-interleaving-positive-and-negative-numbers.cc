/*
题目：20 % 交错正负数 中等

题目大意：
给定一个数组，其中既有正数，又有负数。
将其排列的正好是交错的。

解题思路：
先将其排为先负数，后整数。然后根据正负数的个数再调整一遍。

遇到的问题：
感觉这种问题的边界问题是一个大问题，一定要认真对待。
*/
class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        if (A.size() < 2) return;
        int left = 0, right = A.size()-1;
        int neg = 0, pos = 0;
        while (left < right) {
            while (left < right && A[left] < 0) {
                left++;
                neg++;
            }
            while (left < right && A[right] > 0) {
                right--;
                pos++;
            }
            swap(A[left], A[right]);
        }
        pos = A.size() - neg;
        if (neg >= pos) {
            int end = A.size()-1;
            if (neg == pos) {
                end--;
            }
            for (int i = 1; i < neg; i += 2) {
                swap(A[i], A[end]);
                end -= 2;
            }
        }
        else {
            int start = 0;
            for (int i = A.size()-2; i >= neg; i -= 2) {
                swap(A[i], A[start]);
                start += 2;
            }
        }
    }
};
