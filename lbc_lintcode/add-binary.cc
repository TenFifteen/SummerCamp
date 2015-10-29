/*
题目：22 % 二进制求和 容易

题目大意：
给定两个二进制的字符串，将其相加。

解题思路：
见代码。

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        // Write your code here
        if (a == "") return b;
        if (b == "") return a;
        
        int c = 0;
        string ans;
        int ai = a.size()-1;
        int bi = b.size()-1;
        while (ai >= 0 || bi >= 0) {
            if (ai >= 0) {
                c += a[ai]-'0';
                ai--;
            }
            if (bi >= 0) {
                c += b[bi]-'0';
                bi--;
            }
            ans.push_back('0' + c%2);
            c /= 2;
        }
        if (c) {
            ans.push_back('0' + c);
        }
        reverse(ans);
        return ans;
    }
    
    void reverse(string &s) {
        for (int i = 0; i < s.size()/2; ++i) {
            swap(s[i], s[s.size()-1-i]);
        }
    }
};
