/*
题目大意：
给定一个字符串，问最后一个单词的长度是多少？

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int index = 0, len = 0;
        while (index < s.size()) {
            while (index < s.size() && s[index] == ' ') index++;
            if (index == s.size()) return len;
            
            int last = index;
            while (index < s.size() && s[index] != ' ') index++;
            len = index-last;
        }
        
        return len;
    }
};