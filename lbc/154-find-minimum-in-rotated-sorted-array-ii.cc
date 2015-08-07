/*
题目大意：
给定一个数组，本来排序，现在是旋转了一下。跟153题是一样的，但是数字有重复。

解题思路：
经过分析，就算是二分，也不可以降到logn，所以是n的算法。
所以直接遍历一遍就行了。

遇到的问题：
一次通过。
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ret = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < ret)ret = nums[i];
        }
        return ret;
    }
};