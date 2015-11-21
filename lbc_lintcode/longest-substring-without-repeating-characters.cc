/*
题目：26 % 最长无重复字符的子串 中等

题目大意：
给定一个字符串，问所有的字串中，最长的没有重复字母的是多长？

解题思路：
卡尺

遇到的问题：
没有问题。
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
        int ans = 1;
        int left = 0, right = 1;
        unordered_set<char> us;
        us.insert(s[0]);
        while (right < s.size()) {
            if (us.find(s[right]) == us.end()) {
                us.insert(s[right]);
                if (right - left + 1 > ans) {
                    ans = right - left + 1;
                }
                right++;
            } else {
                while (s[left] != s[right]) {
                    us.erase(us.find(s[left++]));
                }
                left++;
                right++;
            }
        }
        
        return ans;
    }
};
