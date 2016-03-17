/*
题目大意：
合并两个有序数组。

解题思路：
见代码

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        vector<int> ans(A.size()+B.size());
        
        int ia = 0, ib = 0, ic = 0;
        while (ia < A.size() && ib < B.size()) {
            if (A[ia] < B[ib]) ans[ic++] = A[ia++];
            else ans[ic++] = B[ib++];
        }
        
        while (ia < A.size()) ans[ic++] = A[ia++];
        while (ib < B.size()) ans[ic++] = B[ib++];
        
        return ans;
    }
};