/*
题目大意：
给定一个string 的start 和end，一个单词表。每次只能变化一个字母，问是否可以从单词表中找到一条路径从start 到end
输出所有路径。

解题思路：
bfs， backtracking

遇到的问题：
没有太大问题。
就是一开始忘记了将next更新到fa里了。
*/
class Solution {
    void backTrack(vector<vector<string>> &ans, vector<string> &path, 
                   unordered_map<string, vector<string>> &fa) {
        if (fa[path.back()][0] == path.back()) {
            vector<string> now(path.rbegin(), path.rend());
            ans.push_back(now);
            return;
        }
        
        string cur = path.back();
        for (auto p : fa[cur]) {
            path.push_back(p);
            backTrack(ans, path, fa);
            path.pop_back();
        }
    }
    
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        vector<vector<string>> ans;
        
        if (start == end) {
            vector<string> tmp;
            tmp.push_back(start);
            ans.push_back(tmp);
            return ans;
        }
        
        unordered_map<string, vector<string>> fa;
        fa[start].push_back(start);
        
        queue<string> q;
        q.push(start);
        
        bool found = false;
        while (q.size() > 0 && !found) {
            int len = q.size();
            unordered_map<string, vector<string>> next;
            
            for (int i = 0; i < len; ++i) {
                auto cur = q.front(); q.pop();
                string now = cur;
                
                for (int j = 0; j < cur.size(); ++j) {
                    char old = cur[j];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        cur[j] = ch;
                        if (cur == end) {
                            found = true;
                            next[cur].push_back(now);
                        } else if (dict.find(cur) != dict.end() && fa.find(cur) == fa.end()) {
                            next[cur].push_back(now);
                            if (next[cur].size() == 1) q.push(cur);
                        }
                    }
                    cur[j] = old;
                }
            }
            
            for (auto p : next) {
                fa.insert(p);
            }
        }
        
        if (found) {
            vector<string> path;
            path.push_back(end);
            backTrack(ans, path, fa);
        }
        
        return ans;
    }
};