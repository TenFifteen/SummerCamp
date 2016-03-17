/*
题目大意：
给定一串手机键盘的数字，翻译成可能的字母表示。

解题思路：
dfs

遇到的问题：
边界条件一定要跟面试官问清楚。
*/
class Solution {
    void dfs(vector<string> &ans, string now, string &digits, int index, 
             unordered_map<char, string> &hash) {
        if (index == digits.size()) {
            ans.push_back(now);
            return;
        }          
        
        for (auto ch : hash[digits[index]]) {
            dfs(ans, now+ch, digits, index+1, hash);
        }
    }
    
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        if (digits.size() == 0) return vector<string>();
        
        // Write your code here
        unordered_map<char, string> hash;
        hash['1'] = "1";
        hash['2'] = "abc";
        hash['3'] = "def";
        hash['4'] = "ghi";
        hash['5'] = "jkl";
        hash['6'] = "mno";
        hash['7'] = "pqrs";
        hash['8'] = "tuv";
        hash['9'] = "wxyz";
        hash['*'] = "*";
        hash['0'] = " ";
        hash['#'] = "#";
        
        vector<string> ans;
        dfs(ans, "", digits, 0, hash);
        return ans;
    }
};