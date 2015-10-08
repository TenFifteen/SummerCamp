/*
题目：15 % 单词接龙 II 困难

题目大意：
跟120一样，但是这次得输出所有的可以转化的路径。

解题思路：
宽度优先搜索，记录fa路径

遇到的问题：
没有问题。
*/
class Solution {
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
        vector<string> cur;
        unordered_set<string> visited;
        visited.insert(start);
        cur.push_back(start);
        unordered_map<string, unordered_set<string>> fa;
        fa[start].insert(start);
        while (cur.size() > 0) {
            unordered_set<string> visited_next;
            vector<string> next;
            bool finish = false;
            for (auto s : cur) {
                string old = s;
                for (int i = 0; i < s.size(); ++i) {
                    s = old;
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        s[i] = ch;
                        if (s == end && s != old) {
                            finish = true;
                            fa[end].insert(old);
                        }
                        if (dict.find(s) != dict.end() 
                            && visited.find(s) == visited.end()) {
                            if (visited_next.find(s) == visited_next.end()) {
                                next.push_back(s);
                                visited_next.insert(s);
                            }
                            fa[s].insert(old);
                        }
                    }
                }
            }
            if (finish) {
                vector<string> cur;
                cur.push_back(end);
                for (auto f : fa[end]) {
                    sub(ans, fa, f, cur);
                }
                return ans;
            }
            cur.swap(next);
            for (auto s : visited_next) {
                visited.insert(s);
            }
        }
        return ans;
    }
    
    void sub(vector<vector<string>> &ans, unordered_map<string, unordered_set<string>> &fa, string s, vector<string> cur) {
        cur.push_back(s);
        if (fa[s].find(s) != fa[s].end()) {
            for (int i = 0; i < cur.size()/2; ++i) {
                swap(cur[i], cur[cur.size()-1-i]);
            }
            ans.push_back(cur);
            return ;
        }
        for (auto f : fa[s]) {
            sub(ans, fa, f, cur);
        }
    }
};
