/*
题目大意：
给一堆字符串，找出所有的具有同构（字母完全一样，但是排列顺序不同）的字符串。

解题思路：
将所有字符串按照排序后的字符串作为key，聚合到一起。
最后找到所有超过了1个字符串的聚合都放到结果中。

遇到的问题：
感觉题目说的返回值并不是很明确。
*/
class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        map<string,vector<string>> mm;
        vector<string> ans;
        for(int i = 0; i < strs.size(); ++i){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mm[tmp].push_back(strs[i]);
        }
        for(auto v:mm){
            if(v.second.size() > 1){
                for(auto s:v.second){
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};