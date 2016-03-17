/*
题目大意：
给定一组字符串，返回其中有同构的字符串。

解题思路：
hash

遇到的问题：
没有。
*/
class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map<string, vector<string>> hash;
        
        for (auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            
            hash[key].push_back(s);
        }
        
        vector<string> ans;
        for (auto p : hash) {
            if (p.second.size() > 1) {
                for (auto s : p.second) {
                    ans.push_back(s);
                }
            }
        }
        
        return ans;
    }
};
