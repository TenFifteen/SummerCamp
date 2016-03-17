/*
题目大意：
给定两个排序的数组，将A归并到B里面去。

解题思路：
倒着放，见代码。

遇到的问题：
没有。
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
        int t = m+n-1, im = m-1, in = n-1;
        while (im >= 0 && in >= 0) {
            if (A[im] > B[in]) A[t--] = A[im--];
            else A[t--] = B[in--];
        }
        
        while (in >= 0) A[t--] = B[in--];
    }
};