/*
题目大意：
给定一个字符串。问有多少种转换到合理的IP地址。

解题思路：
dfs

遇到的问题：
没有。
*/
class Solution {
    void dfs(vector<string> &ans, vector<string> &now, int index, string s) {
        if (index == 4) {
            if (s.size() > 0) return;
            
            string tmp = now[0];
            for (int i = 1; i < 4; ++i) {
                tmp += "." + now[i];
            }
            ans.push_back(tmp);
            return;
        }
        
        if (s.size() < 4-index) return;
        
        if (s[0] == '0') {
            now[index] = "0";
            dfs(ans, now, index+1, s.substr(1));
        } else {
            int len = 3;
            if (s.size() < 3) len = s.size();
            
            for (int i = 1; i <= len; ++i) {
                string cur = s.substr(0, i);
                if (stoi(cur) > 255) break;
                now[index] = cur;
                dfs(ans, now, index+1, s.substr(i));
            }
        }
    }
    
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        // Write your code here
        vector<string> ans;
        vector<string> now(4);
        
        dfs(ans, now, 0, s);
        
        return ans;
    }
};