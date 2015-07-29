/*
题目大意：
给定一个映射，二十六个字母分别映射1-26，然后给定一个数字串，计算有多少种组合的可能。

解题思路：
动态规划。

遇到的问题：
一开始并没有考虑会有不合法的情况。
*/
class Solution {
public:
    int numDecodings(string s) {
        if(s == "")return 0;
        if(s[0] == '0')return 0;
        vector<int> ans(s.size()+1, 0);
        ans[0] = 1;
        ans[1] = s[0] == '0' ? 0 : 1;
        for(int i = 1; i < s.size(); ++i){
            int tmp = s[i]-'0';
            tmp += (s[i-1]-'0')*10;
            if(s[i] == '0'){
                if(s[i-1] == '0' || s[i-1] > '2')return 0;
                ans[i+1] = ans[i-1];
            }else{
                if(tmp > 9 && tmp < 27){
                    ans[i+1] = ans[i-1] + ans[i];
                }else{
                    ans[i+1] = ans[i];
                }
            }
        }
        return ans[s.size()];
    }
};