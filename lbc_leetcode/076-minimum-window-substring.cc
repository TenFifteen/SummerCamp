/*
题目大意：
给定一个字符串，和一个目标字符串。找出字符串中的一个字串，这个字串包含所有目标串的字符，
求这样的子串的最短。

解题思路：
左右两个指针，如果当前满足条件，则left++；否则right++。

遇到的问题：
竟然一次通过，不可思议。

再次阅读：
感觉这种解法已经足够了。
*/
class Solution {
public:
    string minWindow(string s, string t) {
        auto ans = make_pair(0,0);
        int len = INT_MAX;
        int left = 0, right = 0;
        map<char, int> T,S;
        int total = 0;
        for(auto ch:t){
            T[ch]++;
            total++;
        }
        int num = 0;
        while(true){
            if(num < total){
                if(right == s.size())break;
                S[s[right]]++;
                if(S[s[right]] <= T[s[right]])num++;
                right++;
            }else{
                if(right-left < len){
                    len = right-left;
                    ans.first = left;
                    ans.second = right;
                }
                S[s[left]]--;
                if(S[s[left]] < T[s[left]])num--;
                left++;
            }
        }
        return s.substr(ans.first, ans.second-ans.first);
    }
};
/*
第二次做：
比较顺利，只是少写了一个条件，别的懂完全没有问题。
不过这次代码比之前怎么多了好多呢。看了一下，是total的含义变化了。。。。
*/
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> buf;
        for (auto ch : t) {
            buf[ch]++;
        }

        unordered_map<char, int> cur;
        int front = 0, end = 0, total = 0;
        while (front < s.size() && total < buf.size()) {
            if (buf.find(s[front]) != buf.end()) {
                cur[s[front]]++;
                if (cur[s[front]] == buf[s[front]]) total++;
            }
            front++;
        }

        if (total < buf.size() && front == s.size()) return "";

        int min_len = front-end, min_start = end;
        while (total == buf.size()) {
            while (total == buf.size()) {
                if (buf.find(s[end]) != buf.end()) {
                    if (buf[s[end]] == cur[s[end]]) total--;
                    cur[s[end]]--;
                }
                end++;
                if (total == buf.size() && front-end < min_len) {
                    min_len = front-end;
                    min_start = end;
                }
            }
            while (front < s.size() && total < buf.size()) {
                if (buf.find(s[front]) != buf.end()) {
                    cur[s[front]]++;
                    if (cur[s[front]] == buf[s[front]]) {
                        total++;
                    }
                }
                front++;
            }
        }

        return s.substr(min_start, min_len);
    }
};
/*
 * it's ok
 */
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> um;
        for (auto ch : t) um[ch]++;

        int start = -1, len = INT_MAX;
        unordered_map<char, int> now;
        int total = 0;
        int left = 0, right = 0;
        while (right < s.size()) {
            while (right < s.size() && total < t.size()) {
                now[s[right]]++;
                if (now[s[right]] <= um[s[right]]) total++;
                right++;
            }

            if (total < t.size()) break;

            while (total == t.size()) {
                if (right - left < len) {
                    len = right - left;
                    start = left;
                }
                now[s[left]]--;
                if (now[s[left]] < um[s[left]]) total--;
                left++;
            }
        }

        if (len == INT_MAX) return "";
        return s.substr(start, len);
    }
};
