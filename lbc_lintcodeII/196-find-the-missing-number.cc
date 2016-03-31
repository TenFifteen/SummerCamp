/*
题目大意：
给定一个数组，其中有0-n的数字，少了其中一个。问少了哪个？

解题思路：
求和相减

遇到的问题：
没有。
*/
class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        
        long long sum = n;
        sum *= n+1;
        sum /= 2;
        
        for (auto x : nums) sum -= x;
        
        return sum;
    }
};