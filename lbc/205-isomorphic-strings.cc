/*
题目大意：
给定两个字符串， 如果可以通过字母映射的方式将s转化为t，那么就是true

解题思路：
用两个map来记录已经做过的映射

遇到的问题：
搞不清楚题目到底需要什么样子的映射。
看了别人的题解才知道。原来是不能有s中的两个不同字母映射到同一个t中，
也不能有s中的一个字母映射到t中两个不同的字母。

*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())return false;
        unordered_map<char, char> um1, um2;
        for(int i = 0; i < s.size(); ++i){
            if(um1.count(s[i])){
                if(um1[s[i]] != t[i])return false;
            }else{
                um1[s[i]] = t[i];
            }
            if(um2.count(t[i])){
                if(um2[t[i]] != s[i])return false;
            }else{
                um2[t[i]] = s[i];
            }
        }
        return true;
    }
};