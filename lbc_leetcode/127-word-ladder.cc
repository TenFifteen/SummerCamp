/*
题目大意：
给定一个初始字符串，一个结束字符串，一个单词表。每次只能变一个字母。
问，是否可以经过单词表内的单词转化。

解题思路：
宽度优先搜索。

遇到的问题：
没有问题。

再次阅读：
跟上一题一样，但是还要简单一些，因为不需要记录有多少路径了。
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_set<string> visited;
        vector<string> cur;
        cur.push_back(beginWord);
        int ans = 1;
        if(beginWord == endWord)return 1;
        while(cur.size() > 0){
            vector<string> next;
            unordered_set<string> local_v;
            for(int i = 0; i < cur.size(); ++i){
                for(int j = 0; j < cur[i].size(); ++j){
                    for(char ch = 'a'; ch <= 'z'; ++ch){
                        string tmp = cur[i];
                        tmp[j] = ch;
                        if(wordDict.count(tmp) > 0 && visited.count(tmp) == 0 && local_v.count(tmp) == 0){
                            if(tmp == endWord){
                                return ans+1;
                            }
                            next.push_back(tmp);
                            local_v.insert(tmp);
                        }
                    }
                }
            }
            cur = next;
            ans++;
            for(auto v:local_v){
                visited.insert(v);
            }
        }
        return 0;
    }
};
/*
第二次做：
就是一个BFS，还算可以吧。
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord == endWord) return 1;

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        visited.insert(beginWord);

        int cnt = 1, wordLen = beginWord.size();

        while (q.size()) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                string now = q.front(); q.pop();
                if (now == endWord) return cnt;

                for (int i = 0; i < wordLen; ++i) {
                    char old = now[i];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        now[i] = ch;
                        if (wordList.find(now) != wordList.end() && visited.find(now) == visited.end()) {
                            q.push(now);
                            visited.insert(now);
                        }
                    }
                    now[i] = old;
                }
            }
            cnt++;
        }

        return 0;
    }
};
/*
 * just soso
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (wordList.size() == 0) return 0;

        queue<string> q;
        unordered_set<string> visited;
        visited.insert(beginWord);
        q.push(beginWord);
        int level = 1;
        while (q.size() > 0) {
            int len = q.size();
            for (int i = 0; i < len; ++i) {
                string cur = q.front(); q.pop();
                if (cur == endWord) return level;
                for (int j = 0; j < cur.size(); ++j) {
                    char old = cur[j];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        cur[j] = ch;
                        if (wordList.find(cur) != wordList.end() && visited.find(cur) == visited.end()) {
                            visited.insert(cur);
                            q.push(cur);
                        }
                    }
                    cur[j] = old;
                }
            }
            level++;
        }

        return 0;
    }
};
