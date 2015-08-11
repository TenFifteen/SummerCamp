/*
题目大意：
给定一个数组，将其右移k位。

解题思路：
按照之前的翻转字符串中的单词的题目的思路，可以将前后两部分分别翻转，再将整个
数组翻转。

遇到的问题：
一开始没想到，只是看到了题目的提示才想到的。
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        sub(nums, 0, nums.size()-k-1);
        sub(nums, nums.size()-k, nums.size()-1);
        sub(nums, 0, nums.size()-1);
    }
    
    void sub(vector<int> &nums, int left, int right){
        for(int i = left; i < left + (right-left+1)/2; ++i){
            swap(nums[i], nums[right+left-i]);
        }
    }
};