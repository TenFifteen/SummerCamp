/*
题目大意：
给定一组单词，还有一个起点一个终点，如果两个字符串之间只有一个字母是不一样的，可以认为他们之间是连接的。
然后问是否可以找到一组字典中的单词，从起点到终点。

解题思路：
BFS

遇到的问题：
一开始忘记了处理end不在dict中的情形。
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
        queue<string> q;
        q.push(start);
        
        unordered_set<string> visited;
        visited.insert(start);
        
        int ans = 1;
        while (q.size() > 0) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                string now = q.front(); q.pop();
                if (now == end) return ans;
                
                for (int j = 0; j < now.size(); ++j) {
                    char old = now[j];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        now[j] = ch;
                        if (now == end) return ans+1;
                        
                        if (dict.find(now) != dict.end() && visited.find(now) == visited.end()) {
                            q.push(now);
                            visited.insert(now);
                        }
                    }
                    now[j] = old;
                }
            }
            
            ans++;
        }
        
        return 0;
    }
};