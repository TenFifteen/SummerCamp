/*
题目大意：
给定两个字符串， 如果可以通过字母映射的方式将s转化为t，那么就是true

解题思路：
用两个map来记录已经做过的映射

遇到的问题：
搞不清楚题目到底需要什么样子的映射。
看了别人的题解才知道。原来是不能有s中的两个不同字母映射到同一个t中，
也不能有s中的一个字母映射到t中两个不同的字母。

再次阅读：
感觉的确是需要两个hash的，而且呢，感觉之前的写法和做法都还可以。
然后在DISCUSS中找到一个另类想法：
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256] = {0}, m2[256] = {0}, n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};

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
/*
第二次做：
没有太大问题。
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> m1, m2;
        for (int i = 0;i < s.size(); ++i) {
            if (m1.find(s[i]) == m1.end() && m2.find(t[i]) == m2.end()) {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            } else if (m1.find(s[i]) == m1.end() || m2.find(t[i]) == m2.end()) {
                return false;
            }
            if (m1[s[i]] != t[i] || m2[t[i]] != s[i]) return false;
        }

        return true;
    }
};
/*
 * ok
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t, t2s;
        for (int i = 0; i < s.size(); ++i) {
            if (s2t.find(s[i]) == s2t.end()) {
                if (t2s.find(t[i]) != t2s.end()) return false;
                s2t[s[i]] = t[i];
                t2s[t[i]] = s[i];
            } else {
                if (t2s.find(t[i]) == t2s.end()) return false;
                if (t2s[t[i]] != s[i] || s2t[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};
