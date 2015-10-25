/*
题目：24 % 电话号码的字母组合 new 中等

题目大意：
给定一个电话号码的表盘和一串数字，问可能的字母组合有哪些

解题思路：
找到每个数字对应的字母表，然后递归

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        vector<string> ans;
        if (digits.size() == 0) return ans;
        sub(ans, "", digits, 0);
        return ans;
    }
    
    void sub(vector<string> &ans, string now, string digits, int index) {
        if (index == digits.size()) {
            ans.push_back(now);
            return;
        }
        for (auto ch : um[digits[index]-'0']) {
            sub(ans, now+ch, digits, index+1);
        }
    }
    Solution() {
        um[2] = "abc";
        um[3] = "def";
        um[4] = "ghi";
        um[5] = "jkl";
        um[6] = "mno";
        um[7] = "pqrs";
        um[8] = "tuv";
        um[9] = "wxyz";
        um[0] = " ";
        um[1] = "";
    }
private:
    unordered_map<int, string> um;
};
