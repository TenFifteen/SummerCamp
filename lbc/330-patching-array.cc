/*
题目大意：
给定一个排序的正数数组，还有一个n，如果可以将数字添加到数组中，使其所有的可能的
组合能找到所有的[1,n]的所有数字。问最少添加的数字数量

解题思路：
一开始是没有啥思路的，想用集合来做来着，但是不太好弄。
然后看了提示说是贪心，就感觉应该是加当前缺少的最小的那个数字。
但是实现起来也是挺麻烦的，还要记录所有的已经组合出来的数字。
后来看了一下DISCUSS，发现人家的实现就是直接默认了这个特性，直接选择最小的数字，
而且，还利用了一个很好的性质，如果当前的num小于等于miss，那么就可以组成[1,miss+num)的所有数，
如果没有，那么加上miss之后，下一个可能miss的数字是miss*2

遇到的问题：
哎，还是没有想出来啊。

再次阅读：
没啥好再次阅读的了。已经参考了最优的答案了。
*/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1, cur = 0, added = 0;
        while (miss <= n) {
            if (cur < nums.size() && nums[cur] <= miss) {
                miss += nums[cur++];
            } else {
                miss <<= 1;
                added++;
            }
        }
        
        return added;
    }
};