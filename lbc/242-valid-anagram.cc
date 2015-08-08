/*
题目大意：
给定两个字符串，判断是否为同构的词（两个字符串的各个字母的数量是一样的，但是排列顺序不同）。

解题思路：
排序，然后比较。
也可以使用hash的方法，计算每一个字符的数量。

遇到的问题：
一次通过。
这个题是cracking code interview中的一个题目。
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};