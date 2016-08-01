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
/*
第二次做：
简单题就是容易出错。
忘记了s.insert(n)了。。。
而且，这次写的竟然跟之前的基本是一样的。。。
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto n : nums) {
            if (s.find(n) != s.end()) return true;
            s.insert(n);
        }
        return false;
    }
};
/*
 * ok
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (int i = 0; i < nums.size(); ++i) {
            if (us.find(nums[i]) != us.end()) return true;
            us.insert(nums[i]);
        }
        return false;
    }
};
