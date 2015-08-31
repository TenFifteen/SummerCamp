/*
题目：25 % 数组剔除元素后的乘积 容易

题目大意：
给定一个数组A，求数组B，B[i] 等于所有除了A[i] 之外的元素的乘积；
不能使用除法；

解题思路：
分别从两端计算子段的乘积

遇到的问题：
没有太大问题，只不过把--i写成了++i
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
        if (nums.size() <= 1) return ans;
        ans[0] = nums[0];
        for (int i = 1; i < nums.size()-1; ++i) {
            ans[i] = ans[i-1] * nums[i];
        }
        long long right = nums[nums.size()-1];
        ans[nums.size()-1] = ans[nums.size()-2];
        for (int i = nums.size()-2; i > 0; --i) {
            ans[i] = ans[i-1] * right;
            right *= nums[i];
        }
        ans[0] = right;
        return ans;
    }
};
