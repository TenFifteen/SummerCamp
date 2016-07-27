/*
题目大意：
给定一个起始字符串，一个终止字符串，一个字典。两个字符串之间有一个字母不同，就可以互相转换。
问是否存在一个字典中的转换，是得start转换到end

解题思路：
深搜找路径，并且记录每个人的fa，而且其fa不一定是一个。

遇到的问题：
没有问题。

再次阅读：
明明是BFS，之前的解题思路写的有问题。
感觉上，基本也就是这么做了，没啥别的思路了。
*/
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        map<string, vector<string>> fa;
        unordered_set<string> visited;
        vector<vector<string>> ans;
        if(start == end){
            vector<string> tmp;
            tmp.push_back(start);
            ans.push_back(tmp);
            return ans;
        }

        fa[start].push_back("");
        visited.insert(start);
        vector<string> cur;
        cur.push_back(start);
        bool finish = false;
        while(cur.size() > 0 && finish == false){
            unordered_set<string> local_v;
            vector<string> next;
            for(int i = 0; i < cur.size(); ++i){
                for(int j = 0; j < cur[i].size(); ++j){
                    for(char ch = 'a'; ch <= 'z'; ++ch){
                        string tmp = cur[i];
                        tmp[j] = ch;
                        if(tmp == end){
                            finish = true;
                            fa[tmp].push_back(cur[i]);
                            continue;
                        }
                        if(dict.count(tmp) > 0 && visited.count(tmp) == 0){
                            fa[tmp].push_back(cur[i]);
                            if(local_v.count(tmp) == 0){
                                local_v.insert(tmp);
                                next.push_back(tmp);
                            }
                        }
                    }
                }
            }
            for(auto v:local_v){
                visited.insert(v);
            }
            if(finish == true){
                vector<string> path;
                path.push_back(end);
                sub(ans, end, fa, path);
            }
            cur = next;
        }
        return ans;
    }

    void sub(vector<vector<string>> &ans, string cur, map<string, vector<string>> &fa, vector<string> &path){
        if(fa[cur].size() == 1 && fa[cur][0] == ""){
            vector<string> tmp = path;
            for(int i = 0; i < tmp.size()/2; ++i){
                swap(tmp[i], tmp[tmp.size()-1-i]);
            }
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < fa[cur].size(); ++i){
            path.push_back(fa[cur][i]);
            sub(ans, fa[cur][i], fa, path);
            path.pop_back();
        }
    }
};
/*
第二次做：
感觉这种题目就是变态啊，各种条件。
如果真的要是在纸上写，肯定是一团糟。
*/
class Solution {
private:
    void getPaths(vector<vector<string>> &ans, unordered_map<string, vector<string>> &fa, string now, vector<string> &path) {
        if (now == "") {
            ans.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }

        path.push_back(now);
        for (auto s : fa[now]) {
            getPaths(ans, fa, s, path);
        }
        path.pop_back();
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string> > ans;
        int wordLen = beginWord.size();

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, vector<string>> fa;
        fa[beginWord] = vector<string>(1, "");

        bool notFinish = true;
        while (q.size() && notFinish) {
            int len = q.size();
            unordered_map<string, vector<string>> newfa;
            unordered_set<string> visited;

            for (int i = 0; i < len; ++i) {
                string now = q.front(); q.pop();
                if (now == endWord) {
                    vector<string> path;
                    getPaths(ans, fa, endWord, path);
                    notFinish = false;
                    break;
                }

                string cur = now;
                for (int i = 0; i < wordLen; ++i) {
                    char old = now[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        now[i] = ch;
                        if (wordList.find(now) != wordList.end() && fa.find(now) == fa.end()) {
                            newfa[now].push_back(cur);
                            if (visited.find(now) == visited.end()) {
                                q.push(now);
                                visited.insert(now);
                            }
                        }
                    }
                    now[i] = old;
                }
            }

            for (auto f : newfa) {
                fa[f.first] = f.second;
            }
        }

        return ans;
    }
};
/*
 * some hard, but this time ok
 */
class Solution {
private:
    void findFathers(unordered_map<string, vector<string>> &fa, string word, vector<string> &now, vector<vector<string>> &ans) {
        if (fa.find(word) == fa.end()) {
            ans.push_back(vector<string>(now.rbegin(), now.rend()));
            return;
        }

        for (auto f : fa[word]) {
            now.push_back(f);
            findFathers(fa, f, now, ans);
            now.pop_back();
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        unordered_set<string> visited;
        unordered_map<string, vector<string>> fa;
        vector<vector<string>> ans;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        while (q.size() > 0) {
            int len = q.size();
            unordered_map<string, vector<string>> next;
            for (int i = 0; i < len; ++i) {
                string now = q.front(); q.pop();
                if (now == endWord) {
                    vector<string> path;
                    path.push_back(now);
                    findFathers(fa, now, path, ans);
                    return ans;
                }

                string cur = now;
                for (int j = 0; j < cur.size(); ++j) {
                    char old = cur[j];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        cur[j] = ch;
                        if (visited.find(cur) != visited.end() || wordList.find(cur) == wordList.end()) continue;
                        if (next.find(cur) == next.end()) q.push(cur);
                        next[cur].push_back(now);
                    }
                    cur[j] = old;
                }
            }

            for (auto p : next) {
                fa.insert(p);
                visited.insert(p.first);
            }
        }
        return ans;
    }
};
