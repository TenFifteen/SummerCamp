/*
题目大意：
跟之前的抢劫是一样的，但是这次是首位也相连了。

解题思路：
分别计算去掉第一家和去掉最后一家的结果，取最大值。

遇到的问题：
被我想得稍微复杂了点。
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        if(nums.size() == 1)return nums[0];
        vector<int> rob(nums.size(), 0),norob(nums.size(), 0);
        rob[0] = nums[0];
        for(int i = 1; i < nums.size()-1; ++i){
            rob[i] = norob[i-1] + nums[i];
            norob[i] = max(norob[i-1], rob[i-1]);
        }
        int ret = max(rob[nums.size()-2], norob[nums.size()-2]);
        norob[1] = 0;
        rob[1] = nums[1];
        for(int i = 2; i < nums.size(); ++i){
            rob[i] = norob[i-1] + nums[i];
            norob[i] = max(norob[i-1], rob[i-1]);
        }
        return max(ret,max(rob[nums.size()-1], norob[nums.size()-1]));
    }
};