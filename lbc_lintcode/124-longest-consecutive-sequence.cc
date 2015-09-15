/*
题目：32 % 最长连续序列 中等

题目大意：
给定一个无序的有重复数字的数组。
问其中最长的连续的整数区间是多少

解题思路：
一开始是用的排序后遍历的算法，nlogn
后来查了一下，用的是hash的方法。

遇到的问题：
一开始没有处理重复的数字。
后来没有想到用hash的算法。
*/
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> buf;
        for (auto n : num) {
            buf.insert(n);
        }
        int ret = 0;
        while (buf.size() > 0) {
            int cur = *buf.begin();
            int right = 1;
            while (buf.find(cur+right) != buf.end()) {
                buf.erase(buf.find(cur+right));
                right++;
            }
            int left = 1;
            while (buf.find(cur-left) != buf.end()) {
                buf.erase(buf.find(cur-left));
                left++;
            }
            if (left+right-1 > ret) {
                ret = left+right-1;
            }
            buf.erase(buf.find(cur));
        }
        return ret;
    }
    
    int longestConsecutive2(vector<int> &num) {
        // write you code here
        sort(num.begin(), num.end());
        if (num.size() == 0) return 0;
        int ret = 1;
        int cur = 1;
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] == num[i-1]+1) {
                cur++;
            } else if (num[i] == num[i-1]) {
                ;
            }else {
                cur = 1;
            }
            if (cur > ret) {
                ret = cur;
            }
        }
        return ret;
    }
};
