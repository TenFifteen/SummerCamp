/*
题目：28 % 两个字符串是变位词 容易

题目大意：
给定两个字符串，问是否是变位词（也就是字母都一样，但是排列顺序不同）

解题思路：
用一个map存起来，然后判断

遇到的问题：
题目想要挑战n的时间和1的空间。
结果取网上找了半天也没有找到更好地方法。
但是想想，好像char最多也就256个，算是1的空间了把。。。
*/
class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if (s.size() != t.size()) return false;
        unordered_map<char, int> um;
        for (auto ch : s) {
            um[ch]++;
        }
        for (auto ch : t) {
            um[ch]--;
            if (um[ch] < 0) {
                return false;
            }
        }
        return true;
    }
};
