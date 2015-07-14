/*
题目大意：
给一个字符串，和一堆等长度的单词。在字符串中找出所有单词组成的字串的位置。

解题思路：
用的最naive的方法，直接遍历，通过记录当前已经匹配的单词的数量来判定是否符合条件。

遇到的问题：
一开始以为单词不会重复，用了set。结果发现竟然有重复。不过我感觉现在这个实现方案虽然简单，但是
有点太naive了，估计是有好一点的方法吧，回头看看别人的。
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> buf;
        map<string,int> buf_words;
        for(auto s: words){
            buf_words[s]++;
        }
        int len = words[0].size() * words.size();
        int word_len = words[0].size();
        vector<int> ans;
        if(s.size() < len)return ans;
        for(int i = 0; i < s.size()+1-len; ++i){
            buf.clear();
            bool found = true;
            for(int j = i; j < i+len; j+=word_len){
                string tmp = s.substr(j,word_len);
                if(buf_words[tmp] > buf[tmp]){
                    buf[tmp]++;
                }else{
                    found = false;
                    break;
                }
            }
            if(found){
                ans.push_back(i);
            }
        }
        return ans;
    }
};