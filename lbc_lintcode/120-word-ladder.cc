/*
题目：22 % 单词接龙 中等

题目大意：
给定一个字典，两个单词。每次只能变换单词中的一个字母。问经过多少步，start可以经过字典中的单词，
变成end。

解题思路：
宽度优先搜索

遇到的问题：
一开始忘记了每次将s初始化为old了。
*/
class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        if (start == end) return 1;
        vector<string> cur;
        unordered_set<string> visited;
        visited.insert(start);
        cur.push_back(start);
        int cnt = 1;
        while (cur.size() > 0) {
            unordered_set<string> visited_next;
            vector<string> next;
            for (auto s : cur) {
                string old = s;
                for (int i = 0; i < s.size(); ++i) {
                    s = old;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        s[i] = ch;
                        if (s == end) return cnt+1;
                        if (dict.find(s) != dict.end() 
                            && visited.find(s) == visited.end() 
                            && visited_next.find(s) == visited_next.end()) {
                            next.push_back(s);
                            visited_next.insert(s);
                        }
                    }
                }
            }
            cur.swap(next);
            for (auto s : visited_next) {
                visited.insert(s);
            }
            cnt++;
        }
        return 0;
    }
};
