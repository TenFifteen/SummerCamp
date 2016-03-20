/*
题目大意：
给定一个字符串，将其分割成每个字串都是回文串。输出所有的划分方案。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
    
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<string>> ans;
        
        if (s.size() == 0) {
            ans.push_back(vector<string>());
            return ans;
        }
        
        for (int i = s.size()-1; i >= 0; --i) {
            if (isPalindrome(s, i, s.size()-1)) {
                auto ret = partition(s.substr(0, i));
                for (auto r : ret) {
                    r.push_back(s.substr(i));
                    ans.push_back(r);
                }
            }
        }
        
        return ans;
    }
};