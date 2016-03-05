/*
题目大意：
给定一个字符串，问将s划分成都是回文子串的方法有哪些？

解题思路：
递归。
判定s的一个从后往前的所有字串是否是回文，如果是就递归找前面的字串的。

遇到的问题：
没有问题。

再次阅读：
一开始感觉这道题应该是用什么动归啊，什么的。
但是看了之前的解法，感觉好像的确是这样子的，因为这道题的结果空间复杂度就挺高的，
所以没有必要非得用动归什么的。
反而这种方法比较清晰易懂。DISCUSS中也有一个很不错的方法就是用的这种方法。
虽然DISUCSS中也有一个用DP的，但是我觉得没有太大必要。
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.size() == 0)return ans;
        if(s.size() == 1){
            vector<string> tmp;
            tmp.push_back(s);
            ans.push_back(tmp);
            return ans;
        }
        
        for(int i = s.size()-1; i >= 0; --i){
            bool isPa = true;
            for(int j = s.size()-1; j > s.size()-1-(s.size()-i)/2; --j){
                if(s[j] != s[s.size()+i-j-1]){
                    isPa = false;
                    break;
                }
            }
            if(isPa == true){
                if(i == 0){
                    vector<string> tmp;
                    tmp.push_back(s);
                    ans.push_back(tmp);
                    break;
                }
                auto ret = partition(s.substr(0, i));
                for(auto r:ret){
                    r.push_back(s.substr(i, s.size()-i));
                    ans.push_back(r);
                }
            }
        }
        return ans;
    }
};
/*
第二次做：
这次写的就比较顺畅了。
不过还是感觉，假如是在纸上写代码的话，肯定是不行的。
*/
class Solution {
private:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size()/2; ++i) {
            if (s[i] != s[s.size()-1-i]) return false;
        }    
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if (s.size() == 0) return ans;
        
        for (int i = s.size()-1; i >= 0; --i) {
            string left = s.substr(i);
            if (isPalindrome(left)) {
                auto ret = partition(s.substr(0, i));
                for (int j = 0; j < ret.size(); ++j) {
                    ret[j].push_back(left);
                    ans.push_back(ret[j]);
                }
                if (ret.size() == 0) {
                    vector<string> tmp;
                    tmp.push_back(left);
                    ans.push_back(tmp);
                }
            }
        }
        
        return ans;
    }
};