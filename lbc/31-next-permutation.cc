/*
题目大意：
给一个数组，给出这个数组的排列的下一个排列。

解题思路：
根据排列的定义，从后往前找到第一组两个相邻的数，左边的小于右边的。
然后如果没找到，则当前的排列是最大的，也就是倒序的，直接翻转就行。
把当前扫描过的数字中第一个大于cur的数字，与cur交换。然后剩下的cur+1到
最后，直接翻转就行了。

遇到的问题：
需要注意数字中有相等的情况，也就是要注意大于号号大于等于号的使用。
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)return;
        int cur = nums.size()-2;
        while(cur >= 0 && nums[cur] >= nums[cur+1]){
            cur--;
        }
        if(cur < 0){
            for(int i = 0; i < nums.size()/2; ++i){
                swap(nums[i], nums[nums.size()-1-i]);
            }
            return;
        }
        int tmp = cur+1;
        while(tmp < nums.size() && nums[tmp] > nums[cur])tmp++;
        swap(nums[cur], nums[tmp-1]);
        for(int i = cur+1; i < cur+1+(nums.size()-cur)/2; ++i){
            swap(nums[i], nums[nums.size()-i+cur]);
        }
    }
};