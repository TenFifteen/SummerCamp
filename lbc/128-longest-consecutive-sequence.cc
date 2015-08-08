/*
题目大意：
给定一个没有排序的数组。问其中连续存在的数的最大的长度是多少？

解题思路：
排序。然后从前完后遍历，符合条件就+1，要不然重新开始计数。

遇到的问题：
一开始没有考虑数字会有重复的情况。
面试的时候一定要记得问清楚这种情况。
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        sort(nums.begin(), nums.end());
        int ans = 1;
        int ret = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[i-1])continue;
            if(nums[i] == nums[i-1] + 1){
                ans++;
                if(ans > ret){
                    ret = ans;
                }
            }else{
                ans = 1;
            }
        }
        return ret;
    }
};