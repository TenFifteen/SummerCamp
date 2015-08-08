/*
题目大意：
给定一个数组，其中只有一个数字出现了一次，其他的都出现了两次。问这个出现了一次的数是多少？

解题思路：
两个数相同的话，异或就是0.所以把所有的数都异或起来，最后剩下的就是该数。

遇到的问题：
老问题了，一次通过。
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            ans ^= nums[i];
        }
        return ans;
    }
};