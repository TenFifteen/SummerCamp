/*
题目大意：
给定一个字符串，判定其是否是一个回文的。只考虑字母和数字。忽略大小写。

解题思路：
将字符串先转化为一个纯净的字符串，然后进行首尾比较。

遇到的问题：
其实也可以不用单独再开辟sp空间，可以用两个指针不断的移动。
一开始差点当做了动态规划做的最长回文子串问题了。

再次阅读：
一开始看到代码就想到了两个指针的，但是看到之前其实也是已经考虑过这个思路了，
只是没有实现出来而已。
*/
class Solution {
public:
    bool isPalindrome(string s) {
        string ps;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] <= 'z' && s[i] >= 'a'){
                ps.push_back(s[i]);
            }else if(s[i] >= 'A' && s[i] <= 'Z'){
                ps.push_back(s[i]-'A'+'a');
            }else if(s[i] >= '0' && s[i] <= '9'){
                ps.push_back(s[i]);
            }
        }
        if(ps == "")return true;
        for(int i = 0; i < ps.size()/2; ++i){
            if(ps[i] != ps[ps.size()-1-i])return false;
        }
        return true;
    }
};
/*
第二次做：
虽然比较简单，但是还是挺容易出错的。
我一开始就忘记了大小写的问题了。
*/
class Solution {
private:
    bool isAlpha(char ch) {
        return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9';
    }

    bool isEqual(char ch1, char ch2) {
        if (ch1 >= 'A' && ch1 <= 'Z') ch1 = ch1-'A'+'a';
        if (ch2 >= 'A' && ch2 <= 'Z') ch2 = ch2-'A'+'a';
        return ch1 == ch2;
    }

public:
    bool isPalindrome(string s) {
        if (s.size() < 2) return true;

        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left < right && !isAlpha(s[left])) left++;
            while (left < right && !isAlpha(s[right])) right--;
            if (!isEqual(s[left++], s[right--])) return false;
        }
        return true;
    }
};
/*
 * almost the same with second
 */
class Solution {
private:
    bool isSame(char a, char b) {
        if (a >= 'a' && a <= 'z') a = a - 'a' + 'A';
        if (b >= 'a' && b <= 'z') b = b - 'a' + 'A';
        return a == b;
    }

    bool isAlpha(char ch) {
        return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9';
    }

public:
    bool isPalindrome(string s) {
        if (s.size() == 0) return true;

        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left < right && !isAlpha(s[left])) left++;
            while (left < right && !isAlpha(s[right])) right--;
            if (!isSame(s[left++], s[right--])) return false;
        }
        return true;
    }
};
