/*
题目大意：
给定一个数组，表示从0-n的数字。其中少了一个数字，问是哪一个？

解题思路：
求和然后相减。

遇到的问题：
这个题目也是在编程之美中遇到的。

再次阅读：
不得不说，天外有天，人外有人啊，下面这种算法竟然都有人可以想到。。。：
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;

        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }

        return result;
    }
};
当然了，还有一种是二分搜索。但是二分搜索要求数组是排序的。
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = (long long )nums.size() * (nums.size()+1) / 2;
        
        for (auto n : nums) {
            sum -= n;
        }
        
        return sum;
    }
};