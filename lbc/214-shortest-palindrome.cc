/*
题目大意：
给定一个字符串，问在通过在字符串前面加字符的方式将其变为回文字符串，最短的结果是多少？

解题思路：
计算以字符串开头为起点的最长的回文子串。

遇到的问题：
虽然一开始想到了这个解法，但是感觉Manchester并不能直接写出来，就试了一个朴素的解法，不出意料，超时了。
得到的的结果就是Manchester算法一定要熟练掌握。
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.size() < 2)return s;
        string str(s.size()*2+1,'#');
        for(int i = 0; i < s.size(); ++i){
            str[i*2+1] = s[i];
        }
        int id = 0, mx = 0, cur = 0;
        vector<int> len(str.size(), 1);
        while(cur < str.size()){
            if(cur < mx){
                len[cur] = min(mx-cur, len[2*id-cur]);
            }
            while(cur - len[cur] >= 0 && cur+len[cur] < str.size() && str[cur-len[cur]] == str[cur+len[cur]]){
                len[cur]++;
            }
            if(cur + len[cur] > mx){
                mx = cur + len[cur];
                id = cur;
            }
            cur++;
        }
        int max_p = str.size()/2+1;
        while(len[max_p] != max_p+1)max_p--;
        string pad = s.substr(max_p, s.size());
        for(int i = 0; i < pad.size()/2; ++i){
            swap(pad[i], pad[pad.size()-1-i]);
        }
        return pad + s;
    }
};