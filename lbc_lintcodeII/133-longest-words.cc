/*
题目大意：
给定一组单词，找到所有最长的单词。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        vector<string> ans;
        for (auto w : dictionary) {
            while (ans.size() > 0 && ans.back().size() < w.size()) ans.pop_back();
            if (ans.size() == 0 || ans.back().size() == w.size()) ans.push_back(w);
        }
        
        return ans;
    }
};