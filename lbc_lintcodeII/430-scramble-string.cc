/*
题目大意：
给定一个两个字符串，一个字符串可以表示成很多种不同的树，然后数的任意位置可以左右旋转。问a是否可以经过旋转达到b

解题思路：
类似于暴力，还有一种n*n*n*n的dp的方法。
不过我想了一下，这种搜索方式的复杂度才是n*n*n的呢

遇到的问题：
子数组的长度经常搞错。
*/
class Solution {
    bool isDiff(const string &s1, const string &s2) {
        if (s1.size() != s2.size()) return true;
        
        unordered_map<char, int> hash;
        for (auto ch : s1) hash[ch]++;
        
        for (auto ch : s2) {
            hash[ch]--;
            if (hash[ch] < 0) return true;
        }
        
        return false;
    }
    
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string& s1, string& s2) {
        // Write your code here
        if (isDiff(s1, s2)) return false;
        if (s1.size() == 1) return true;
        
        int n = s1.size();
        for (int i = 1; i < n; ++i) {
            string left1 = s1.substr(0, i), left2 = s2.substr(0, i);
            string right1 = s1.substr(i), right2 = s2.substr(i);
            if (isScramble(left1, left2) && isScramble(right1, right2)) return true;
            
            left1 = s1.substr(0, i), left2 = s2.substr(n-i);
            right1 = s1.substr(i), right2 = s2.substr(0, n-i);
            if (isScramble(left1, left2) && isScramble(right1, right2)) return true;
        }
        return false;
    }
};