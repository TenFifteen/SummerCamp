/*
题目：22 % 分割回文串 容易

题目大意：
给定一个字符串，返回其所有可能的字串都是回文串的组合

解题思路：
算是动归吧

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        if (s.size() == 0) {
            vector<vector<string>> ans;
            return ans;
        }
        
        vector<vector<bool>> flag(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); ++i) {
            flag[i][i] = true;
        }
        for (int i = 1; i < s.size(); ++i) {
            for (int j = 0; j + i < s.size(); ++j) {
                if (s[j] == s[j+i]) {
                    if (i == 1) {
                        flag[j][j+i] = true;
                    } else {
                        flag[j][j+i] = flag[j+1][j+i-1];
                    }
                }
            }
        }
        
        return sub(s, s.size()-1, flag);
    }
    
    vector<vector<string>> sub(string &s, int last, vector<vector<bool>> &flag) {
        vector<vector<string>> ans;
        if (last == 0) {
            vector<string> tmp;
            tmp.push_back(s.substr(0, 1));
            ans.push_back(tmp);
            return ans;
        }
        for (int j = last; j > 0; --j) {
            if (flag[j][last]) {
                auto ret = sub(s, j-1, flag);
                for (int i = 0; i < ret.size(); ++i) {
                    ret[i].push_back(s.substr(j, last-j+1));
                    ans.push_back(ret[i]);
                }
            }
        }
        if (flag[0][last]) {
            vector<string> tmp;
            tmp.push_back(s.substr(0, last+1));
            ans.push_back(tmp);
        }
        return ans;
    }
};
