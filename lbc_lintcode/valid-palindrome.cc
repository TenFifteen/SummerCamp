/*
题目：21 % 有效回文串 容易

题目大意：
给定一个字符串，问其是否是回文。只算大小写字母和数字。而且，不区分大小写。

解题思路：
两指针。

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        if (s.size() == 0) return true;
        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left < right && !isAlp(s[left])) {
                left++;
            }
            while (left < right && !isAlp(s[right])) {
                right--;
            }
            if (s[left] == s[right] || lower(s[left]) == lower(s[right])) {
                left++;
                right--;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    
    char lower(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch - 'A' + 'a';
        }
        return ch;
    }
    
    bool isAlp(char ch) {
        if (ch >= 'a' && ch <= 'z') {
            return true;
        }
        if (ch >= 'A' && ch <= 'Z') {
            return true;
        }
        if (ch >= '0' && ch <= '9') {
            return true;
        }
        return false;
    }
};
