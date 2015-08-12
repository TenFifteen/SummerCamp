/*
题目大意：
给定一列房子的钱，两个连着的房子是不可以抢的，问最多可以抢多少钱

解题思路：
动归

遇到的问题：
一次通过
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> rob(nums.size()), norob(nums.size());
        if(nums.size() == 0)return 0;
        rob[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            rob[i] = norob[i-1] + nums[i];
            norob[i] = max(rob[i-1], norob[i-1]);
        }
        return max(rob[nums.size()-1], norob[nums.size()-1]);
    }
};