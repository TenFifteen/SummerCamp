/*
题目大意：
给定一个二维的char数组，一个单词集合。问能在二维表中找到多少个集合中的单词？

解题思路：
trie + dfs

遇到的问题：
一开始把存放结果的代码位置放错位置了。
*/
class Solution {
    class TrieNode {
    public:
        bool isWord;
        unordered_map<char, TrieNode *> next;
        TrieNode(): isWord(false) {}
    };
    
    TrieNode *root;
    
    void insert(const string &s) {
        TrieNode *cur = root;
        for (auto ch : s) {
            if (cur->next.find(ch) == cur->next.end()) cur->next[ch] = new TrieNode();
            cur = cur->next[ch];
        }
        cur->isWord = true;
    }
    
    void destroy(TrieNode *node) {
        for (auto n : node->next) {
            destroy(n.second);
        }
        delete node;
    }
    
    void dfs(vector<string> &ans, vector<vector<char>> &board, int x, int y, TrieNode *node, string now) {
        if (node->isWord) {
            ans.push_back(now);
            node->isWord = false;
        }
        
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || 
            node->next.find(board[x][y]) == node->next.end()) return;
        
        const int ix[] = {-1, 0, 1, 0};
        const int iy[] = {0, -1, 0, 1};
        
        char old = board[x][y];
        board[x][y] = 0;
        for (int i = 0; i < 4; ++i) {
            dfs(ans, board, x+ix[i], y+iy[i], node->next[old], now+old);
        }
        board[x][y] = old;
    }
    
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        vector<string> ans;
        if (board.size() == 0 || board[0].size() == 0) return ans;
        
        root = new TrieNode();
        for (auto w : words) {
            insert(w);
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(ans, board, i, j, root, "");
            }
        }
        
        destroy(root);
        return ans;
    }
};