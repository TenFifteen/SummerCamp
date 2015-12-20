/*
题目大意：
给定一组单词。定义两个单词的乘积为其长度的乘积。
然后要求所有没有交集的单词的乘积的最大值。

解题思路：
由于输入中只有小写字母，所以可以确定最多有26个字母。然后可以将其映射到
整数的bit上。这样就可以用整数操作来表示两个字符串是否是相交的。

遇到的问题：
一开始没有想到这种映射方式。只是直接拿字符串进行hash看是否是相交的了。
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        if (n < 3) return 0;
        vector<int> bit(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                bit[i] |= (1 << (words[i][j]-'a'));
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if ((bit[i] & bit[j]) == 0) {
                    int cur = words[i].size() * words[j].size();
                    ans = max(ans, cur);
                }
            }
        }
        
        return ans;
    }
};