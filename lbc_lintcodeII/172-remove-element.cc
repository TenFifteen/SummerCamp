/*
题目大意：
给定一个数组，将其中的所有等于elem的元素都删掉。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        int total = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != elem) A[total++] = A[i];
        }
        return total;
    }
};