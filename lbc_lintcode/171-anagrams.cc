/*
题目：22 % 乱序字符串 中等

题目大意：
给定一组乱序的字符串，然后将其中有同构字符串的都挑出来

解题思路:
hash

遇到的问题：
没有问题。
*/
class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string, vector<string>> um;
        for (auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            um[key].push_back(s);
        }
        vector<string> ret;
        for (auto m : um) {
            if (m.second.size() > 1) {
                for (auto s : m.second) {
                    ret.push_back(s);
                }
            }
        }
        return ret;
    }
};

