/*
题目大意：
给定罗马数字，转换成阿拉伯数字。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        // Write your code here
        unordered_map<char, int> hash;
        hash['I'] = 1;
        hash['X'] = 10;
        hash['C'] = 100;
        hash['M'] = 1000;
        hash['V'] = 5;
        hash['L'] = 50;
        hash['D'] = 500;
        
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i+1 < s.size() && hash[s[i]] < hash[s[i+1]]) {
                ans -= hash[s[i]];
            } else {
                ans += hash[s[i]];
            }
        }
        
        return ans;
    }
};
