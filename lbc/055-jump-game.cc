/*
题目大意：
给一个数组，每一个数字表示该点可以往后跳多远。求，从0开始，能否跳到最后一个点？

解题思路：
跟45题相似。其实应该是先做这个题，再做45题。反正思路都一样。

遇到的问题：
一次通过。
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0)return false;
        if(nums.size() == 1)return true;
        int cur = 0,len = 1,dist = nums[0];
        while(true){
            if(dist >= nums.size()-1)return true;
            if(dist < cur+len)return false;
            int tmp = 0;
            for(int i = cur+len; i <= dist; ++i){
                tmp = max(tmp, nums[i]+i);
            }
            cur = cur+len;
            len = dist-cur+1;
            dist = tmp;
        }
    }
};