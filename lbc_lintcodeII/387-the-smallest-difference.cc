/*
题目大意：
给定两个数组，求其中两个元素的最小的差值。

解题思路：
见代码。排序，遍历

遇到的问题：
没有。
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
        
        int ia = 0, ib = 0;
        int ans = INT_MAX;
        while (ia < A.size() && ib < B.size()) {
            ans = min(ans, abs(A[ia]-B[ib]));
            if (ia+1 == A.size()) ib++;
            else if (ib+1 == B.size()) ia++;
            else if (A[ia] < B[ib]) ia++;
            else ib++;
        }
        
        return ans;
    }
};
