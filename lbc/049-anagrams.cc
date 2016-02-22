/*
题目大意：
给一堆字符串，找出所有的具有同构（字母完全一样，但是排列顺序不同）的字符串。

解题思路：
将所有字符串按照排序后的字符串作为key，聚合到一起。
最后找到所有超过了1个字符串的聚合都放到结果中。

遇到的问题：
感觉题目说的返回值并不是很明确。

再次阅读：
虽然题目感觉有点问题，但是觉得应该是这样做，之前的做法基本就不错了。
然后这里有一个DISCUSS中的比较完整的代码：
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].insert(s);
        }
        vector<vector<string>> anagrams;
        for (auto m : mp) { 
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
};
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