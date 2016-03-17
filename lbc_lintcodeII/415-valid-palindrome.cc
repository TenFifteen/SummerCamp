/*
题目大意：
判断一个字符串是否是回文。只考虑字母和数字。不考虑大小写。

解题思路：
直接判断。

遇到的问题：
首先是一开始没有考虑数字。
然后是大写字母比小写字母的ASCII码还要小。
还有一点就是while中最后忘记了修改left和right了。
*/
class Solution {
    bool isAlpha(char ch) {
        return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9';
    }
    
    bool equal(char ch1, char ch2) {
        if (ch1 >= 'A' && ch1 <= 'Z') ch1 = ch1-'A'+'a';
        if (ch2 >= 'A' && ch2 <= 'Z') ch2 = ch2-'A'+'a';
        return ch1 == ch2;
    }
    
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        if (s.size() == 0) return true;
        
        int left = 0, right = s.size();
        while (left < right) {
            while (left < right && !isAlpha(s[left])) left++;
            while (left < right && !isAlpha(s[right])) right--;
            if (left < right && !equal(s[left++], s[right--])) return false;
        }
        return true;
    }
};