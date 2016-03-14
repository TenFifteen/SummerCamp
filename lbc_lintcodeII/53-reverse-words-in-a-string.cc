/*
题目大意：
给定一个字符串，其中有很多单词，翻转其中的单词。

解题思路：
翻转url的思路。

遇到的问题：
没有。
*/
class Solution {
    void reverse(string &s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }
    
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        stringstream ss(s);
        string ans, tmp;
        ss >> ans;
        
        while (ss >> tmp) {
            ans += " " + tmp;
        }
        
        if (ans.size() == 0) return ans;
        
        reverse(ans, 0, ans.size()-1);
        
        int i = 0;
        while (i < ans.size()) {
            int j = i;
            while (j < ans.size() && ans[j] != ' ') j++;
            reverse(ans, i, j-1);
            i = j+1;
        }
        return ans;
    }
};