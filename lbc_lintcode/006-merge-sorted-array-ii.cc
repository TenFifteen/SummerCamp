/*
题目：合并排序数组 容易

题目大意：
合并两个有序的数组

解题思路：
直接合并

遇到的问题：
没有问题。

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
        int index1 = 0, index2 = 0;
        for (int i = 0; i < ans.size(); ++i) {
            if (index1 == A.size())ans[i] = B[index2++];
            else if (index2 == B.size())ans[i] = A[index1++];
            else if (A[index1] < B[index2])ans[i] = A[index1++];
            else ans[i] = B[index2++];
        }
        return ans;
    }
};
