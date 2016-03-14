/*
题目大意：
给定一个数组，求去掉元素i之后，所有数字的乘积。不可以使用除法。

解题思路：
先算后半部分，再算前半部分。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        vector<long long> ans(nums.size(), 1);
        if (nums.size() < 2) return ans;
        
        for (int i = ans.size()-2; i >= 0; --i) {
            ans[i] = ans[i+1]*nums[i+1];
        }
        
        long long pre = 1;
        for (int i = 0; i < nums.size(); ++i) {
            ans[i] *= pre;
            pre *= nums[i];
        }
        
        return ans;
    }
};