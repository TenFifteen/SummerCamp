/*
题目大意：
给定一个数组，求其连续的最大的子数组的乘积。

解题思路：
用动态规划，以当前元素为结尾的子数组的最大乘积等于max（last_max*nums[i],
last_min*nums[i], nums[i])

遇到的问题：
一开始用的二维的动归，超时。
感觉并没有想清楚这个题目，所以看了网上别人的解法，才感觉豁然开朗。
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = nums[0];
        int last_max = nums[0];
        int last_min = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            int cur_max = max(max(last_max*nums[i], last_min*nums[i]), nums[i]);
            int cur_min = min(min(last_max*nums[i], last_min*nums[i]), nums[i]);
            if(cur_max > ret)ret = cur_max;
            last_max = cur_max;
            last_min = cur_min;
        }
        return ret;
    }
};