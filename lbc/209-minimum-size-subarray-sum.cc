/*
题目大意：
给定一个正数数组，一个sum，问最小的区间满足和大于sum的是多少？

解题思路：
卡尺

遇到的问题：
忘记了左边前进的时候减去左边的数了。
另外，题目说，可以实现nlogn的另一个算法，应该就是二分了。
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ret = INT_MAX;
        if(nums.size() == 0)return 0;
        int sum = nums[0], left = 0, right = 0;
        while(right < nums.size()){
            if(sum < s){
                right++;
                if(right < nums.size()){
                    sum += nums[right];
                }
            }else{
                if(right - left + 1 < ret){
                    ret = right - left + 1;
                }
                sum -= nums[left];
                left++;
            }
        }
        if(ret == INT_MAX)return 0;
        return ret;
    }
};