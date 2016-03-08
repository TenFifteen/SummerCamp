/*
题目大意：
给定两个排序的数组，计算器中位数。

解题思路：
用找第k小的元素的方式来实现。二分。

遇到的问题：
没有问题。
*/
class Solution {
    int kthElement(vector<int> &A, int i1, vector<int> &B, int i2, int k) {
        if (i1 == A.size()) return B[i2+k-1];
        if (i2 == B.size()) return A[i1+k-1];
        if (k == 1) return min(A[i1], B[i2]);
        
        int lenA = A.size()-i1, lenB = B.size()-i2;
        if (lenA > lenB) return kthElement(B, i2, A, i1, k);
        
        int k1 = min(lenA, k/2), k2 = k-k1;
        if (A[i1+k1-1] == B[i2+k2-1]) return A[i1+k1-1];
        else if (A[i1+k1-1] < B[i2+k2-1]) return kthElement(A, i1+k1, B, i2, k2);
        else return kthElement(A, i1, B, i2+k2, k1);
    }
    
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        int total = A.size() + B.size();
        double ans = kthElement(A, 0, B, 0, total/2+1);
        if (total % 2 == 0) {
            ans += kthElement(A, 0, B, 0, total/2);
            ans /= 2;
        }
        
        return ans;
    }
};
