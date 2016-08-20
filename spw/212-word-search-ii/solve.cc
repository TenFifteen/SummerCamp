/**
 * Problem: Given a 2D board and a list of words from the dictionary, find all words in the board.
 * Solve: use trie tree as the dict.
 * Tips: no
 */
class TrieNode {
    public:
        TrieNode *next[26];
        bool isEnd;
        TrieNode() {
            for (int i = 0; i < 26; ++i) {
                next[i] = NULL;
            }
            isEnd = false;
        }
};

class TrieDict {
    private:
        TrieNode *root;
    public:
        TrieDict() {
            root = new TrieNode();
        }

        void addWord(string s) {
            int n = s.size();
            TrieNode *it = root;
            for (int i = 0; i < n; ++i) {
                int pos = s[i] - 'a';
                if (it->next[pos] == NULL)
                    it->next[pos] = new TrieNode();
                it = it->next[pos];
            }

            it->isEnd = true;
        }

        int search(string s) {
            int n = s.size();
            TrieNode *it = root;
            for (int i = 0; i < n; ++i) {
                int pos = s[i] - 'a';
                if (it->next[pos] == NULL)
                    return 0;
                it = it->next[pos];
            }

            if (it->isEnd) return 1;
            return 2;
        }

        ~TrieDict() {
            delTree(root);
        }
        void delTree(TrieNode *root) {
            if (root == NULL) return;
            for (int i = 0; i < 26; ++i)
                delTree(root->next[i]);
            delete root;
        }
};

class Solution {
    public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            vector<string> ans;
            if (words.size() == 0 || board.size() == 0) return ans;

            TrieDict dict;
            for (string w : words)
                dict.addWord(w);

            int m = board.size(), n = board[0].size();
            vector<vector<bool>> used(m, vector<bool>(n, false));

            // use the set to remove the duplicates
            unordered_set<string> ansSet;
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    dfs(ansSet, dict, board, used, i, j, "");
            for (string s : ansSet)
                ans.push_back(s);
            return ans;
        }

        void dfs(unordered_set<string> &ans,  TrieDict &dict, vector<vector<char>>& board, vector<vector<bool>> &used, int y, int x, string now) {
            static int dx[] = {1, 0, -1, 0};
            static int dy[] = {0, -1, 0, 1};

            int m = board.size(), n = board[0].size();
            if (y < 0 || y >= m || x < 0 || x >= n || used[y][x]) return;

            used[y][x] = true;
            now += board[y][x];

            int r = dict.search(now);
            if (r == 0) {
                used[y][x] = false;
                return;
            } else if (r == 1) {
                ans.insert(now);
            }

            for (int i = 0; i < 4; ++i) {
                dfs(ans, dict, board, used, y+dy[i], x+dx[i], now);
            }

            used[y][x] = false;
        }
};
