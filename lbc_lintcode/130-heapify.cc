/*
题目：31 % 堆化 中等

题目大意：
给定一个数组，将其调整为最小堆

解题思路：
就是建堆的过程。

遇到的问题：
没有问题。
但是题目要求n的复杂度。

精彩解答：
http://blog.csdn.net/nicaishibiantai/article/details/43634975
虽然他用的也看出来是n的算法。但是感觉简洁了好多。
感觉堆这块还是要再看看的。
*/
class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        if (A.size() < 2) return;
        for (int i = 1; i < A.size(); ++i) {
            int cur = i;
            while (cur != 0) {
                int pa = (cur-1)/2;
                if (A[pa] > A[cur]) {
                    swap(A[pa], A[cur]);
                }
                cur = pa;
            }
        }
    }
};
