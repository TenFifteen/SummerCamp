/*
题目大意：
给定两个字符串，判断是不是同构异形词

解题思路：
见代码。

遇到的问题：
挑战中说是不是可以优化到O(1)的空间复杂度。
感觉这样只用256个int的空间，应该是算是常数了吧。
*/
class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        if (s.size() != t.size()) return false;
        
        vector<int> count(256, 0);
        for (auto ch : s) {
            count[ch]++;
        }
        for (auto ch : t) {
            count[ch]--;
            if (count[ch] < 0) return false;
        }
        return true;
    }
};