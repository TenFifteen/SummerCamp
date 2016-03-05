/*
题目大意：
给定一个单词序列，一个字符串。
问是否可以有一个字符串中的字母和单词序列中的单词是一一对应的映射方式存在？

解题思路：
用两个map，分别记录单词到字符和字符到单词的映射。

遇到的问题：
没有问题。

再次阅读：
虽然感觉自己的写法已经很好了。但是还是在DISCUSS中找到了一个更简洁的，更好看的解法：
bool wordPattern(string pattern, string str) {
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
}
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
/*
第二次做：
没有太大问题。
不过DISCUSS中这种两个hash都指向一个下标的这种方式比较省空间，挺好的。
*/
class Solution {
    vector<string> split(const string s) {
        stringstream ss(s);
        vector<string> ans;
        string input;
        
        while (ss >> input) {
            ans.push_back(input);
        }
        return ans;
    }
    
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = split(str);
        if (pattern.size() != words.size()) return false;
        
        unordered_map<char, string> hash1;
        unordered_map<string, char> hash2;
        for (int i = 0;i < pattern.size(); ++i) {
            if (hash1.find(pattern[i]) == hash1.end()) {
                if (hash2.find(words[i]) != hash2.end()) return false;
                hash1[pattern[i]] = words[i];
                hash2[words[i]] = pattern[i];
            } else {
                if (hash1[pattern[i]] != words[i]) return false;
            }
        }
        
        return true;
    }
};