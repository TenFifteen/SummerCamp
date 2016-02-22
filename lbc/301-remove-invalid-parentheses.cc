/*
题目大意：
给定一个字符串，其中有括号和字符。括号可能是不匹配的。
问有哪些中括号的匹配的结果。而且匹配的数量是理论上最多的？

解题思路：
DFS+hash
感觉效率不是很高。但是重复实在是不太好控制了。

遇到的问题：
这种题目还是有点难的。

再次阅读：
同样是DFS，但是下面这种方式可以把复杂度降低很多，避免很多不必要的搜索路径：
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;
        int left_removed = 0;
        int right_removed = 0;
        for(auto c : s) {
            if(c == '(') {
                ++left_removed;
            }
            if(c == ')') {
                if(left_removed != 0) {
                    --left_removed;
                }
                else {
                    ++right_removed;
                }
            }
        }
        helper(s, 0, left_removed, right_removed, 0, "", result);
        return vector<string>(result.begin(), result.end());
    }
private:
    void helper(string s, int index, int left_removed, int right_removed, int pair, string path, unordered_set<string>& result) {
        if(index == s.size()) {
            if(left_removed == 0 && right_removed == 0 && pair == 0) {
                result.insert(path);
            }
            return;
        }
        if(s[index] != '(' && s[index] != ')') {
            helper(s, index + 1, left_removed, right_removed, pair, path + s[index], result);
        }
        else {
            if(s[index] == '(') {
                if(left_removed > 0) {
                    helper(s, index + 1, left_removed - 1, right_removed, pair, path, result);
                }
                helper(s, index + 1, left_removed, right_removed, pair + 1, path + s[index], result);
            }
            if(s[index] == ')') {
                if(right_removed > 0) {
                    helper(s, index + 1, left_removed, right_removed - 1, pair, path, result);
                }
                if(pair > 0) {
                    helper(s, index + 1, left_removed, right_removed, pair - 1, path + s[index], result);
                }
            }
        }
    }
};
*/
class Solution {
private:
    int maxLen = 0;
    unordered_set<string> us;
    
    void dfs(string out, string s, int left, int right) {
        if (s.size() == 0) {
            if (left == right && left == maxLen) {
                us.insert(out);
            }
            return;
        }
        if (s[0] != '(' && s[0] != ')') {
            dfs(out + s.substr(0, 1), s.substr(1), left, right);
        }
        else if (s[0] == '(') {
            dfs(out + s.substr(0,1), s.substr(1), left+1, right);
            dfs(out, s.substr(1), left, right);
        } else {
            if (left > right) dfs(out + s.substr(0,1), s.substr(1), left, right+1);
            dfs(out, s.substr(1), left, right);
        }
    }
    
    int getLen(const string &s) {
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                left++;
            } else if(s[i] == ')') {
                if (left > right) {
                    right++;
                }
            }
        }
        
        return right;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        
        this->maxLen =  getLen(s);
        dfs("", s, 0, 0);
        
        for (auto s : us) {
            ans.push_back(s);
        }
        if (ans.size() == 0) {
            ans.push_back("");
        }
        return ans;
    }
};