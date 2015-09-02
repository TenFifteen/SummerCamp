/*
题目：33 % 合并排序数组 II 容易

题目大意：
给定两个排序的数组，将其进行合并

解题思路：
从后往前合并

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int i = m-1, j = n-1;
        int cur = m+n-1;
        while (i >= 0 || j >= 0) {
            if (j < 0) break;
            if (i < 0) {
                while (j >= 0) {
                    A[cur--] = B[j--];
                }
                break;
            }
            if (A[i] < B[j]) {
                A[cur--] = B[j--];
            } else {
                A[cur--] = A[i--];
            }
        }
    }
};
