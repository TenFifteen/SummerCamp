/*
题目：28 % 寻找缺失的数 中等

题目大意：
给定一个数组，包含0-n的数字的n个数字，问少了哪个数字

解题思路：
求和，然后减去所有出现的数字

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        long long n = nums.size();
        long long sum = n * (n+1) / 2;
        for (auto x : nums) {
            sum -= x;
        }
        return sum;
    }
};
