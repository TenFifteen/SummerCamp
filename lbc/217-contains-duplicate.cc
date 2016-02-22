/*
题目大意：
给定一个数组，问其中是否有重复的数字。

解题思路：
直接用set

遇到的问题：
没有问题。

再次阅读：
比较简单。
最简单的方法就是两层循环遍历，
然后第二种是排序后遍历
最好的就是采用这种牺牲空间复杂度的，采用hash的方式。
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