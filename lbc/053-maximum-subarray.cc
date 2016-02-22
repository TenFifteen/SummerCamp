/*
题目大意：
给一个数组，求出所有的子数组的和的最大值。

解题思路：
求出以每一个数字为结尾的子数组的最大和。

遇到的问题：
一次通过。
还有一个二分的方法可以尝试。回头试试。

再次阅读：
这是一个经典老题，O（n）的算法应该是没有什么问题。
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        int ret = nums[0];
        int last = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            int tmp = nums[i];
            if(last > 0){
                tmp += last;
            }
            last = tmp;
            if(last > ret){
                ret = last;
            }
        }
        return ret;
    }
};