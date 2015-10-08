/*
题目：44 % 判断字符串是否没有重复字符 容易

题目大意：
给定一个字符串，问其中是否有重复的字母

解题思路：
hash

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        // write your code here
        unordered_set<char> us;
        for (auto s : str) {
            if (us.find(s) != us.end()) return false;
            us.insert(s);
        }
        return true;
    }
};
