/*
题目：35 % 最后一个单词的长度 容易

题目大意：
给定一个字符串，其中只有大小写字母以及空格。问其中最后一个单词的长度是多少？

解题思路：
见代码

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        // Write your code here
        int ret = 0;
        int last = 0;
        int index = 0;
        while (index < s.size()) {
            while (last < s.size() && s[last] == ' ') {
                last++;
            }
            index = last;
            while (index < s.size() && s[index] != ' ') {
                index++;
            }
            if (index - last > 0) {
                ret = index - last;
            }
            last = index + 1;
        }
        return ret;
    }
};
