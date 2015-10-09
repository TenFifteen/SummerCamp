/*
题目：37 % 最长单词 容易

题目大意：
给定一个string的数组，然后找出所有的长度最长的字符串

解题思路：
遍历一遍，找到所有最长的字符串的下标，然后将所有字符串放进去

遇到的问题：
竟然又遇到了unsigned和int比较的问题了。一开始将len设置为-1了。
*/
class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        // write your code here
        int len = 0;
        vector<int> index;
        for (int i = 0; i < dictionary.size(); ++i) {
            if (dictionary[i].size() > len) {
                len = dictionary[i].size();
                index.clear();
                index.push_back(i);
            } else if (dictionary[i].size() == len) {
                index.push_back(i);
            }
        }
        vector<string> ans;
        for (auto i : index) {
            ans.push_back(dictionary[i]);
        }
        return ans;
    }
};
