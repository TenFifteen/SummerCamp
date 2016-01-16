/*
题目大意：
给一个字符串，和一堆等长度的单词。在字符串中找出所有单词组成的字串的位置。

解题思路：
用的最naive的方法，直接遍历，通过记录当前已经匹配的单词的数量来判定是否符合条件。

遇到的问题：
一开始以为单词不会重复，用了set。结果发现竟然有重复。不过我感觉现在这个实现方案虽然简单，但是
有点太naive了，估计是有好一点的方法吧，回头看看别人的。

再次阅读：
这次看完了题目之后，然后又看了一下之前的代码。感觉的确是有点low。其实可以将其看做一个滑动
窗口的问题的。而且，窗口大小是固定的，因为单词要互相之间直接相连。可以看一下下面的代码，就是用的滑动窗口
用上滑动窗口之后，复杂度的确是低了很多。
// travel all the words combinations to maintain a window
// there are wl(word len) times travel
// each time, n/wl words, mostly 2 times travel for each word
// one left side of the window, the other right side of the window
// so, time complexity O(wl * 2 * N/wl) = O(2N)
vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> ans;
    int n = S.size(), cnt = L.size();
    if (n <= 0 || cnt <= 0) return ans;

    // init word occurence
    unordered_map<string, int> dict;
    for (int i = 0; i < cnt; ++i) dict[L[i]]++;

    // travel all sub string combinations
    int wl = L[0].size();
    for (int i = 0; i < wl; ++i) {
        int left = i, count = 0;
        unordered_map<string, int> tdict;
        for (int j = i; j <= n - wl; j += wl) {
            string str = S.substr(j, wl);
            // a valid word, accumulate results
            if (dict.count(str)) {
                tdict[str]++;
                if (tdict[str] <= dict[str]) 
                    count++;
                else {
                    // a more word, advance the window left side possiablly
                    while (tdict[str] > dict[str]) {
                        string str1 = S.substr(left, wl);
                        tdict[str1]--;
                        if (tdict[str1] < dict[str1]) count--;
                        left += wl;
                    }
                }
                // come to a result
                if (count == cnt) {
                    ans.push_back(left);
                    // advance one word
                    tdict[S.substr(left, wl)]--;
                    count--;
                    left += wl;
                }
            }
            // not a valid word, reset all vars
            else {
                tdict.clear();
                count = 0;
                left = j + wl;
            }
        }
    }

    return ans;
}
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