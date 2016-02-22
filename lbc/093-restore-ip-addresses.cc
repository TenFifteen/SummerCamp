/*
题目大意：
给定一个ip地址的数字表示，去掉了.
求出有多少种还原方式。

解题思路：
回溯。

遇到的问题：
i < (s.size() > 2 ? 3: s.size())
一开始放了加括号了。

再次阅读：
感觉现在的想法跟之前一样，还是类似于dfs的方法。
然后看了一下DISCUSS，不错的解法中也是用的DFS的方法，基本差不多的。
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        sub(ans, "", 0, s);
        return ans;
    }
    
    void sub(vector<string> &ans, string cur, int stage, string s){
        if(stage == 4){
            if(s == ""){
                ans.push_back(cur);
            }
            return;
        }
        if(s == "")return;
        if(s[0] == '0'){
            string next = stage == 0 ? "0" : cur+"."+"0";
            sub(ans, next, stage+1, s.substr(1, s.size()-1));
            return;
        }
        for(int i = 0; i < (s.size() > 2 ? 3: s.size()); ++i){
            string tmp = s.substr(0, i+1);
            if(stoi(tmp) > 255)return;
            string next = stage == 0 ? tmp : cur + "." + tmp;
            sub(ans, next, stage+1, s.substr(i+1, s.size()-i-1));
        }
    }
};