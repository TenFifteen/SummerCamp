/*
题目：27 % 比较字符串 容易

题目大意：
给定两个字符串，都是大写字母。问A是否可以包含B的所有字符，不要求有序

解题思路：
拿一个map来记录其中每个字母的个数，然后数一遍就知道了。

遇到的问题：
没有问题，就是一开始把-‘A’习惯性的写成了'0'
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
        if (A.size() < B.size()) return false;
        vector<int> num(26, 0);
        for (auto b : B) {
            num[b-'A']++;
        }
        for (auto a : A) {
            num[a-'A']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (num[i] > 0) return false;
        }
        return true;
    }
};

