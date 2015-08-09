/*
题目大意：
给定一个数组，问其中是否有重复的数字。

解题思路：
直接用set

遇到的问题：
没有问题。
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto n:nums){
            if(s.count(n))return true;
            s.insert(n);
        }
        return false;
    }
};