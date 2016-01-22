/*
题目大意：
给定一个数组，问其中在一个窗口k大小内，是否存在重复的数字。

解题思路：
保持窗口大小不变，维护set

遇到的问题：
竟然min(k+1, nums.size())有语法错误。。。。。。

再次阅读：
用一个set是没有问题的。
不过可以使用unordered_set也许更好一些。
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        int len = nums.size();
        for(int i = 0; i < min(k+1, len); ++i){
            if(s.count(nums[i]))return true;
            s.insert(nums[i]);
        }
        for(int i = k+1; i < nums.size(); ++i){
            s.erase(nums[i-k-1]);
            if(s.count(nums[i]))return true;
            s.insert(nums[i]);
        }
        return false;
    }
};