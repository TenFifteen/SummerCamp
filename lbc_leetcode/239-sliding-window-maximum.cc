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

再次阅读：
以前对于单调队列不是很熟，所以不知道怎么下手。
现在知道了，所以也知道怎么做了：
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
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
/*
第二次做：
第一次自己手动实现一个单调递减队列。
不过两个循环可以合并成一个。
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0) return vector<int>();
        
        deque<int> d;
        for (int i = 1; i < k; ++i) {
            if (d.size() == 0) {
                d.push_back(i-1);
            } else {
                while (d.size() > 0 && nums[d.back()] <= nums[i-1]) d.pop_back();
                d.push_back(i-1);
            }
        }
        
        vector<int> ans;
        for (int i = k-1; i < nums.size(); ++i) {
            while (d.size() > 0 && d.front() < i-k+1) d.pop_front();
            while (d.size() > 0 && nums[d.back()] <= nums[i]) d.pop_back();
            d.push_back(i);
            ans.push_back(nums[d.front()]);
        }
        
        return ans;
    }
};