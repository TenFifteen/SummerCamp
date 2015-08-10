/*
题目大意：
给定一个数组，求其中的众数。也就是有一个元素的个数超过了n/2了。

解题思路：
二分

遇到的问题：
一次通过。
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        auto ret = sub(nums, 0, nums.size()-1);
        return ret.first;
    }
    
    pair<int, bool> sub(vector<int> &nums, int left, int right){
        if(left > right){
            return make_pair(0, false);
        }
        if(left == right){
            return make_pair(nums[left], true);
        }
        int mid = left + (right-left+1)/2;
        auto ret_l = sub(nums, left, mid-1);
        auto ret_r = sub(nums, mid, right);
        if(ret_l.second){
            int cnt = 0;
            for(int i = left; i <= right; ++i){
                if(nums[i] == ret_l.first)cnt++;
            }
            if(cnt > (right-left+1)/2)return ret_l;
        }
        if(ret_r.second){
            int cnt = 0;
            for(int i = left; i <= right; ++i){
                if(nums[i] == ret_r.first)cnt++;
            }
            if(cnt > (right-left+1)/2)return ret_r;
        }
        return make_pair(0, false);
    }
};