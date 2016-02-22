/*
题目大意：
给定两个字符串，判断是否为同构的词（两个字符串的各个字母的数量是一样的，但是排列顺序不同）。

解题思路：
排序，然后比较。
也可以使用hash的方法，计算每一个字符的数量。

遇到的问题：
一次通过。
这个题是cracking code interview中的一个题目。

再次阅读：
简单题，还可以用hash的方式来计数：
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};