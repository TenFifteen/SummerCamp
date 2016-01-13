#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class TrieNode {
    public:
        // Initialize your data structure here.
        TrieNode* children[26];
        bool end;

        TrieNode() {
            for (int i = 0; i < 26; ++i) children[i] = NULL;
            end = false;
        }
};

class Trie {
    public:
        Trie() {
            root = new TrieNode();
        }

        // Inserts a word into the trie.
        void insert(string word) {
            int n = word.size();
            TrieNode *level = root;
            for (int i = 0; i < n; ++i) {
                int pos = word[i] - 'a';
                if (level->children[pos] == NULL) {
                    level->children[pos] = new TrieNode();
                }
                level = level->children[pos];
            }
            level->end = true;
        }

        // Returns if the word is in the trie.
        bool search(string word) {
            int n = word.size();
            TrieNode *level = root;
            for (int i = 0; i < n; ++i) {
                int pos = word[i] - 'a';
                if (level->children[pos] == NULL) {
                    return false;
                }
                level = level->children[pos];
            }
            return level->end == true;
        }

        // Returns if there is any word in the trie
        // that starts with the given prefix.
        bool startsWith(string prefix) {
            int n = prefix.size();
            TrieNode *level = root;
            for (int i = 0; i < n; ++i) {
                int pos = prefix[i] - 'a';
                if (level->children[pos] == NULL) {
                    return false;
                }
                level = level->children[pos];
            }
            return level != NULL;
        }

    private:
        TrieNode* root;
};

/**
 * Problem: Given a matrix of lower alphabets and a dictionary. Find all the words in the dictionary,
 *          that can be found in the matrix. A word can start from any position in the matrix and go
 *          left/right/up/down to adjacent position.
 * Solve: dfs + trie
 * Tips: 1. Trie is used as dictionary of words to search an startwith.
 *       2. Then when we use DFS search, we can branch efficiently with a trie.
 *       3. When we find a word, we should not stop.
 */
class Solution {
    public:
        vector<string> ans;
        unordered_set<string> ans_set;
        /**
         * @param board: A list of lists of character
         * @param words: A list of string
         * @return: A list of string
         */
        vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
            ans.clear();
            int m = board.size();
            if (m == 0) {
                return ans;
            }
            int n = board[0].size();

            Trie trie;
            for (int i = 0; i < words.size(); ++i) {
                trie.insert(words[i]);
            }

            vector<vector<bool>> visited(m, vector<bool>(n, false));
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    dfs(board, visited, "", i, j, trie);
                }
            }

            for ( auto it = ans_set.begin(); it != ans_set.end(); ++it)
                ans.push_back(*it);
            ans_set.clear();
            return ans;
        }

    private:
        void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, string prefix, int i, int j, Trie &trie) {
            if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0) return;
            if (visited[i][j]) return;

            prefix += board[i][j];

            if (!trie.startsWith(prefix)) return;

            if (trie.search(prefix)) {
                // don not stop here, that is, do not return.
                ans_set.insert(prefix);
            }

            visited[i][j] = true;
            dfs(board, visited, prefix, i+1, j, trie);
            dfs(board, visited, prefix, i, j-1, trie);
            dfs(board, visited, prefix, i-1, j, trie);
            dfs(board, visited, prefix, i, j+1, trie);
            visited[i][j] = false;
        }
};


