/*
题目：36 % 最小差 中等

题目大意：
给定两个数组，求其中任意两个元素之差的最小值。

解题思路：
排序后，遍历。见代码。

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        if (A.size() == 0 || B.size() == 0) {
            return 0;
        }
        int ans = INT_MAX;
        int ia = 0, ib = 0;
        while (ia < A.size() && ib < B.size()) {
            if (abs(A[ia]-B[ib]) < ans) {
                ans = abs(A[ia]-B[ib]);
            }
            if (A[ia] > B[ib]) {
                ib++;
            } else {
                ia++;
            }
        }
        return ans;
    }
};

