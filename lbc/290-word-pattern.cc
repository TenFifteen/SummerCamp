/*
题目大意：
给定一个单词序列，一个字符串。
问是否可以有一个字符串中的字母和单词序列中的单词是一一对应的映射方式存在？

解题思路：
用两个map，分别记录单词到字符和字符到单词的映射。

遇到的问题：
没有问题。
*/
class Solution {
private:
    vector<string> split(string str, char delim) {
        stringstream ss(str);
        vector<string> ans;
        string cur;
        
        while (ss >> cur) {
            ans.push_back(cur);
        }
        
        return ans;
    }
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = split(str, ' ');
        if (words.size() != pattern.size()) return false;
        
        unordered_map<string, char> stc;
        unordered_map<char, string> cts;
        for (int i = 0; i < words.size(); ++i) {
            if (stc.find(words[i]) == stc.end()) {
                if (cts.find(pattern[i]) != cts.end()) {
                    return false;
                }
                cts[pattern[i]] = words[i];
                stc[words[i]] = pattern[i];
            } else if (stc[words[i]] != pattern[i]) {
                return false;
            }
        }
        
        return true;
    }
};