/*
题目：32 % 删除元素 容易

题目大意：
删除一个数组中所有等于elem的元素，其他元素往前移，返回最后数组元素的个数

解题思路：
见代码

遇到的问题：
没有问题。
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
        int cnt = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != elem) {
                A[cnt++] = A[i];
            }
        }
        return cnt;
    }
};
