/*
题目大意：
给定一组字符串，问他们共同的前缀最大是什么？

解题思路：
暴力。

遇到的问题：
没有。
*/
class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if (strs.size() == 0) return "";
        
        int len = 0;
        while (true) {
            if (strs[0].size() <= len) break;
            bool goon = true;
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i].size() > len && strs[i][len] == strs[0][len]) continue;
                else {
                    goon = false;
                    break;
                }
            }
            
            if (goon) len++;
            else break;
        }
        
        return strs[0].substr(0, len);
    }
};