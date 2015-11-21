/*
题目：40 % 罗马数字转整数 中等

题目大意：
给定一个罗马数字，将其转化为十进制整数

解题思路：
根据罗马数字的性质。正常情况下，是由大到小排列的字母，如果出现了小字母在大字母前面，
说明出现了类似于10-1=9这种情况。然后就是将前面的小的算作负的就可以了。

遇到的问题：
虽然我还是没有从根本上理解罗马数字的规则，不过也差不多了。
*/
class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        // Write your code here
        unordered_map<char, int> rti;
        rti['I'] = 1;
        rti['V'] = 5;
        rti['X'] = 10;
        rti['L'] = 50;
        rti['C'] = 100;
        rti['D'] = 500;
        rti['M'] = 1000;
        
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i+1 < s.size() && rti[s[i]] < rti[s[i+1]]) {
                ans -= rti[s[i]];
            } else {
                ans += rti[s[i]];
            }
        }
        
        return ans;
    }
};
