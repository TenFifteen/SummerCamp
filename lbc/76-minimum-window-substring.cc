/*
题目大意：
给定一个字符串，和一个目标字符串。找出字符串中的一个字串，这个字串包含所有目标串的字符，
求这样的子串的最短。

解题思路：
左右两个指针，如果当前满足条件，则left++；否则right++。

遇到的问题：
竟然一次通过，不可思议。
*/
class Solution {
public:
    string minWindow(string s, string t) {
        auto ans = make_pair(0,0);
        int len = INT_MAX;
        int left = 0, right = 0;
        map<char, int> T,S;
        int total = 0;
        for(auto ch:t){
            T[ch]++;
            total++;
        }
        int num = 0;
        while(true){
            if(num < total){
                if(right == s.size())break;
                S[s[right]]++;
                if(S[s[right]] <= T[s[right]])num++;
                right++;
            }else{
                if(right-left < len){
                    len = right-left;
                    ans.first = left;
                    ans.second = right;
                }
                S[s[left]]--;
                if(S[s[left]] < T[s[left]])num--;
                left++;
            }
        }
        return s.substr(ans.first, ans.second-ans.first);
    }
};