/*
题目：23 % 最多有k个不同字符的最长子字符串 中等

题目大意：
给定一个字符串，求不同的字母数量不超过k的最长的字串

解题思路：
卡尺法

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        if (s.size() == 0 || k <= 0) return 0;
        int ans = 1;
        unordered_map<char, int> um;
        int cur = 1;
        um[s[0]]++;
        int left = 0, right = 1;
        while (right < s.size()) {
            if (cur < k || um[s[right]] != 0) {
                um[s[right]]++;
                if (um[s[right]] == 1) {
                    cur++;
                }
                right++;
                if (right-left > ans) {
                    ans = right-left;
                }
            } else {
                um[s[left]]--;
                if (um[s[left]] == 0) {
                    cur--;
                }
                left++;
            }
        }
        return ans;
    }
};
