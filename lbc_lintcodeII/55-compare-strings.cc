/*
题目大意：
给定两个字符串，问A中的字母是否能够包含所有B中的字母。

解题思路：
hash

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int count[26] = {0};
        for (auto ch : A) count[ch-'A']++;
        for (auto ch : B) {
            count[ch-'A']--;
            if (count[ch-'A'] < 0) return false;
        }
        return true;
    }
};
