/*
题目大意：
给定一个没有排序的数组。问其中连续存在的数的最大的长度是多少？

解题思路：
排序。然后从前完后遍历，符合条件就+1，要不然重新开始计数。

遇到的问题：
一开始没有考虑数字会有重复的情况。
面试的时候一定要记得问清楚这种情况。

再次阅读：
看到之前用的方法竟然是排序。完全不符合题意呀。
看了一下DISCUSS中的解答，有一个实在是厉害的解法：
int longestConsecutive(vector<int> &num) {
    unordered_map<int, int> m;
    int r = 0;
    for (int i : num) {
        if (m[i]) continue;
        r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
    }
    return r;
}
1) neither i+1 nor i-1 has been seen: m[i]=1;

2) both i+1 and i-1 have been seen: extend m[i+m[i+1]] and m[i-m[i-1]] to each other;

3) only i+1 has been seen: extend m[i+m[i+1]] and m[i] to each other;

4) only i-1 has been seen: extend m[i-m[i-1]] and m[i] to each other.


相当于是把每个元素对应的目前的长度都计算出来了。
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        sort(nums.begin(), nums.end());
        int ans = 1;
        int ret = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[i-1])continue;
            if(nums[i] == nums[i-1] + 1){
                ans++;
                if(ans > ret){
                    ret = ans;
                }
            }else{
                ans = 1;
            }
        }
        return ret;
    }
};
/*
第二次做；
一开始还是没有想到O(n)的思路，不过看了提示之后，大体知道了使用并查集的思路。
不过尝试着写了一下并查集，结果好难写啊。
所以看了一下之前的内容，发现DISCUSS中这种思路简直是太好了啊。所以就拿过来用了。
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 0;
        for (auto i : nums) {
            if (m[i]) continue;
            int newlen = m[i-1] + m[i+1] + 1;
            m[i-m[i-1]] = newlen;
            m[i+m[i+1]] = newlen;
            m[i] = newlen;
            ans = max(ans, m[i]);
        }
        return ans;
    }
};