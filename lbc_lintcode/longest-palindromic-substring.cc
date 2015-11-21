/*
题目：23 % 最长回文子串 中等

题目大意：
给定一个字符串，求出最长的回文子串。

解题思路：
曼彻斯特算法

遇到的问题：
最后返回的时候计算下标出了点问题。
*/
class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        if (s.size() < 2) return s;
        
        string str(s.size()*2+1, '#');
        for (int i = 0; i < s.size(); ++i) {
            str[i*2+1] = s[i];
        }
        
        int id = 0, cur = 0, mx = 0;
        vector<int> ans(str.size(), 1);
        while (cur < str.size()) {
            if (mx > cur) {
                ans[cur] = ans[2*id - cur];
                if (ans[cur]+cur-1 > mx) {
                    ans[cur] = mx-cur+1;
                }
            }
            
            while (cur-ans[cur] >= 0 && cur+ans[cur] <= str.size() 
                && str[cur-ans[cur]] == str[cur+ans[cur]]) {
                    ans[cur]++;
            }
            
            if (ans[cur] + cur -1 > mx) {
                mx = ans[cur] + cur - 1;
                id = cur;
            }
            
            cur++;
        }
        
        int ret = 0;
        for (int i = 1; i < ans.size(); ++i) {
            if (ans[i] > ans[ret]) {
                ret = i;
            }
        }
        
        if (ret % 2) {
            return s.substr((ret-1)/2-ans[ret]/2+1, ans[ret]-1);
        } else {
            return s.substr((ret-2)/2-(ans[ret]-3)/2, ans[ret]-1);
        }
    }
};
