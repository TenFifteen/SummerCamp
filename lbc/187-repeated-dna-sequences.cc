/*
题目大意：
给定一个DNA串。问其中以10个为单位，在串中出现多与1次的串有哪些

解题思路：
将10个字符映射成整数，进行hash。

遇到的问题：
一开始直接将字符串作为hash的key，发现超过了内存限制了。
然后看网上有人将每个字符的后三位表示取出来作为其唯一表示。
但是我想了一下，不就是一个四进制的转化么，然后相当于是每个字母用
两位就可以表示了。
这样的话，其实可以最长用int表示16个字母。

再次阅读：
我以为我用的这种bit模式的操作已经足够好了呢
结果感觉人家这个更好。。。：
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> m;
    vector<string> r;
    int t = 0, i = 0, ss = s.size();
    while (i < 9)
        t = t << 3 | s[i++] & 7;
    while (i < ss)
        if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1)
            r.push_back(s.substr(i - 10, 10));
    return r;
}
*/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<int, int> mm;
        vector<string> ans;
        map<char, int> buf;
        buf['A'] = 0;
        buf['C'] = 1;
        buf['G'] = 2;
        buf['T'] = 3;
        if(s.size() <= 10)return ans;
        int cur = 0;
        for(int i = 0; i < 10; ++i){
            cur <<= 2;
            cur += buf[s[i]];
        }
        mm[cur] = 1;
        for(int i = 10; i < s.size(); ++i){
            cur -= buf[s[i-10]] << 18;
            cur <<= 2;
            cur += buf[s[i]];
            if(mm[cur] == 1)ans.push_back(s.substr(i-9, 10));
            mm[cur]++;
        }
        return ans;
    }
};