/*
题目：23 % 翻转字符串 容易

题目大意：
给定一个字符串，将其中的单词都翻转过来。
但是原来字符串首尾的空格还有中间多出来的空格都不要了。

解题思路：
类似于翻转url

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        int index = 0;
        string ans;
        while (index < s.size() && s[index] == ' ') index++;
        while (index < s.size()) {
            while (index < s.size() && s[index] != ' ') {
                ans.push_back(s[index++]);
            }
            while (index < s.size() && s[index] == ' ') {
                index++;
            }
            if (index < s.size()) {
                ans.push_back(' ');
            }
        }
        reverse(ans, 0, ans.size()-1);
        index = 0;
        int last = 0;
        while (index < ans.size()) {
            while (index < ans.size() && ans[index] != ' ') index++;
            reverse(ans, last, index-1);
            last = index+1;
            index++;
        }
        return ans;
    }
    
    void reverse(string &s, int left, int right) {
        for (int i = left; i < left+(right-left+1)/2; ++i) {
            swap(s[i], s[right-i+left]);
        }
    }
};
