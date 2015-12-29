#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

void dfs(vector<vector<string> > &ans, vector<string> &path, string word, int dis);

/**
 * Problem: Given two words and a dictionary's word list, find all transformation sequences from the
 *          begin word to the end word.
 * Solve: use BFS to construct a graph and remember every node's level, then use DFS to traversal the
 *            graph to get all the path.
 * Tips: 1. Every node who has more than one parent have the only one level, because we have no back
 *          edge and we keep the min edge every time;
 *       2. Then when level[endWord]  = minLen(if have one), then we use the parent relation to back traversal, we find
 *          level[beginWord] = 1 at last.
 */
unordered_map<string, unordered_set<string> > parent;
vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList)
{
    vector<vector<string> > ans;
    if (wordList.size() == 0) return ans;
    int len = beginWord.size();

    unordered_set<string> now;
    unordered_map<string, int> level;
    for (auto it = wordList.begin(); it != wordList.end(); ++it) {
        level[*it] = INT_MAX;
    }

    now.insert(beginWord);
    level[beginWord] = 1;
    while (!now.empty()) {
        unordered_set<string> next;
        for (auto it = now.begin(); it != now.end(); ++it) {
            string s = *it;
            for (int i = 0; i < len; ++i) {
                char tmp = s[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    s[i] = c;
                    if (wordList.find(s) != wordList.end()) {
                        // skip all the back edge: level[s] < level[parent[s]] + 1
                        if (level[*it] + 1 < level[s]) {
                            level[s] = level[*it] + 1;
                            next.insert(s);
                            parent[s].insert(*it);
                        } else if (level[*it] + 1 == level[s]) {
                            parent[s].insert(*it);
                        }
                    }
                }
                s[i] = tmp;
            }
        }
        now = next;
    }

    // warn!! Find no path
    if (level[endWord] == INT_MAX) return ans;
    vector<string> path(level[endWord]);
    dfs(ans, path, endWord, level[endWord]);

    return ans;
}

void dfs(vector<vector<string>> &ans, vector<string> &path, string word, int dis)
{
    path[dis-1] = word;
    if (dis == 1) {
         ans.push_back(path);
         return;
    }

    unordered_set<string> p = parent[word];
    for (auto it = p.begin(); it != p.end(); ++it) {
        dfs(ans, path, *it, dis-1);
    }
}

int main()
{
    unordered_set<string> wordList;
    wordList.insert("hot");
    wordList.insert("dog");
    findLadders("hot", "dog", wordList);

    return 0;
}
