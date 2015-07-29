/*
题目大意：
给一个数组，求出该数组中缺少的第一个正整数。时间复杂度为n

解题思路：
将所有数据遍历一遍，将每个数组放到属于该数字的地方去。最后从头到尾遍历一遍，就可以找到第一个
缺少的正整数了。

遇到的问题：
一开始没想到这个方法，看了别人的思路才知道的。
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            int index = nums[i]-1;
            while(index >= 0 && index < nums.size()){
                int tmp = nums[index]-1;
                nums[index] = index+1;
                if(tmp != index){
                    index = tmp;
                }else{
                    break;
                }
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};