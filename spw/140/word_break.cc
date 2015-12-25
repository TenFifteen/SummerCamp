#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Problem: Given a string and a dictionary of words dict, add spaces in s to construct a sentence where
 *          each word is a valid dictionary word. Return such possible sentences.
 * Solve: dp + dfs.
 *       1. DP: use s[0...len-1] as the substring, use a 2D array to remember the path
 *       2. DFS: use two position to specify a word.
 * Tips: select the subproblem carefully when using dp. We use length instead of position at last make it
 *       easy to understand and initialize(dp[0] = true).
 */
void dfs(vector<string> &ans, vector<vector<int>> &edges, string &s, int pos, int last_pos, string sentence) {
    sentence = s.substr(pos+1, last_pos-pos) + (sentence == "" ? "" : " " + sentence);

    if (pos == -1) {
        ans.push_back(sentence);
        return;
    }

    for (int i = 0; i < edges[pos].size(); ++i) {
        dfs(ans, edges, s, edges[pos][i], pos, sentence);

    }

}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    vector<string> ans;
    int width = s.size();
    if (width == 0) return ans;

    vector<vector<int>> parent(width, vector<int>());
    vector<bool> dp(width+1, false);

    dp[0] = true;
    for (int len = 1; len <= width; ++len) {
        for (int j = 0; j < len; ++j) {
            if (dp[j] && wordDict.find(s.substr(j, len-j)) != wordDict.end()) {
                dp[len] = true;
                parent[len-1].push_back(j-1);
            }
        }
    }
    if (dp[width] == false) return ans;

    for (int i = 0; i < parent[width-1].size(); ++i) {
        dfs(ans, parent, s, parent[width-1][i], width-1, "");

    }

    return ans;

}

int main()
{

}
