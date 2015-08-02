/*
题目大意：
给定一个数组。求出所有窗口大小为k的子数组的最大值。

解题思路：
用一个堆来存放当前k窗口的元素。每次删掉前面一个，添加后边一个。保持窗口大小为k。

遇到的问题：
题目中有说用线性时间。现在这个算法的时间是nlogk的。

上网查了一下，这个问题适合用一个带有取最大值的队列。
至于怎么实现一个常数复杂度取最大值的队列，以及如何实现一个常数复杂度取最大值的栈，在该博客中有解释：
http://blog.csdn.net/kay_zhyu/article/details/8869542
http://blog.csdn.net/kay_zhyu/article/details/8869641
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        for(int i = 0; i < k; ++i){
            s.insert(nums[i]);
        }
        vector<int> ans;
        if(nums.size() == 0)return ans;
        ans.push_back(*s.rbegin());
        for(int i = k; i < nums.size(); ++i){
            s.erase(s.find(nums[i-k]));
            s.insert(nums[i]);
            ans.push_back(*s.rbegin());
        }
        return ans;
    }
};