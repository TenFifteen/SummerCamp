/*
题目大意：
给定一个n，产生所有的[0-n]区间内数字的1的个数的序列。

解题思路：
将ans本身作为一个hash，查找之前的数字的数字的情况。

遇到的问题：
没有。在题目的提示下，我竟然写出来啦。。。
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        
        for (int i = 1; i <= num; ++i) {
            ans[i] = ans[i&(i-1)] + 1;
        }
        
        return ans;
    }
};