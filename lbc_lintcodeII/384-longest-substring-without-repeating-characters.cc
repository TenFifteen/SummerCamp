/*
题目大意：
给定一个字符串，问子串的不含重复字母的最大长度是多少？

解题思路：
见代码。two pointers

遇到的问题：
没有问题。
不过就是下面注释中的一行bug搞得我找了好久。
*/
class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        if (s.size() == 0) return 0;
        
        unordered_map<char, int> count;
        int left = 0, right = 0, ans = 1;
        count[s[0]]++;
        while (right < s.size()) {
            right++;
            if (right >= s.size()) break; // else will take end as a char.
            count[s[right]]++;
            if (count[s[right]] < 2) {
                ans = max(ans, right-left+1);
            } else {
                while (count[s[right]] > 1) {
                    count[s[left]]--;
                    left++;
                }
            }
        }
        
        return ans;
    }
};
