/*
题目：21 % 两个排序数组的中位数 困难

题目大意：
给定两个排序的数组，求中位数

解题思路：
利用求两个排序数组中的第k小的数进行求解

遇到的问题：
一开始没想利索，还是看了一下原来的方案。
*/
class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        int total = A.size() + B.size();
        if (total & 1) {
            return findK(A, 0, B, 0, total/2+1);
        } else {
            double a = findK(A, 0, B, 0, total/2);
            double b = findK(A, 0, B, 0, total/2+1);
            return (a+b)/2;
        }
    }
    
    //k start from 1
    int findK(vector<int> &A, int a, vector<int> &B, int b, int k) {
        int lenA = A.size()-a;
        int lenB = B.size()-b;
        if (lenA > lenB) {
            return findK(B, b, A, a, k);
        }
        if (lenA == 0) {
            return B[b+k-1];
        }
        if (k == 1) {
            return min(A[a], B[b]);
        }
        int am = min(k/2, lenA);
        int bm = k - am;
        if (A[a+am-1] == B[b+bm-1]) return A[a+am-1];
        else if (A[a+am-1] < B[b+bm-1]) {
            return findK(A, a+am, B, b, k-am);
        } else {
            return findK(A, a, B, b+bm, k-bm);
        }
    }
};

