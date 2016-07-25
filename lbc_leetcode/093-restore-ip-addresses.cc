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
/*
第二次做：
虽然不是什么难题，不过写代码的时候各种条件搞错了，一开始还忘记了加.了，后来发现最后一个域没有验证。
其实想一想的话，这个验证是否是一个合理的域应该抽象为一个函数。
*/
class Solution {
private:
    void dfs(vector<string> &ans, string now, string s, int n) {
        if (s.size() > n*3 || s.size() < n) return;
        if (n == 1) {
            if (s[0] != '0' && stoi(s) <= 255 || s == "0") ans.push_back(now+"."+s);
            return;
        }

        int len = s.size()+1-n < 4 ? s.size()+1-n : 3;
        if (s[0] == '0') len = 1;
        for (int i = 1; i <= len; ++i) {
            string cur = s.substr(0, i);
            if (stoi(cur) > 255) break;

            if (n == 4) dfs(ans, now+cur, s.substr(i), n-1);
            else dfs(ans, now+"."+cur, s.substr(i), n-1);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(ans, "", s, 4);
        return ans;
    }
};
/*
 * some tedious
 */
class Solution {
private:
    vector<string> restore(string s, int n) {
        if (n == 1) {
            vector<string> ans;
            if (s.size() == 0 || s.size() > 3 || stoi(s) > 255 || (s.size() > 1 && s[0] == '0')) return ans;
            ans.push_back(s);
            return ans;
        }

        if (s.size() < n) return vector<string>();

        vector<string> ans;
        string sub = s.substr(0, 1);
        vector<string> ret = restore(s.substr(1), n-1);
        for (auto s : ret) {
            ans.push_back(sub + "." + s);
        }
        if (s[0] != '0') {
            for (int i = 2; i < s.size(); ++i) {
                string sub = s.substr(0, i);
                if (stoi(sub) > 255) break;
                ret = restore(s.substr(i), n-1);
                for (auto s : ret) {
                    ans.push_back(sub + "." + s);
                }
            }
        }
        return ans;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        return restore(s, 4);
    }
};
