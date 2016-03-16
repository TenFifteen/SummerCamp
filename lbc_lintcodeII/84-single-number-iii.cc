/*
题目大意：
给定一个数组，其中除了两个数之外，其他所哟的数都出现了两次。
问这两个数是啥？

解题思路：
见代码

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int x = 0;
        for (auto a : A) x ^= a;
        
        x &= -x;
        vector<int> ans(2, 0);
        for (auto a : A) {
            if (x & a) ans[0] ^= a;
            else ans[1] ^= a;
        }
        
        return ans;
    }
};