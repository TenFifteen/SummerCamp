/*
题目：19 % 单词搜索 II 困难

题目大意：
给定一个二维的字母表，一个单词表
问那些单词可以在字母表中找到

解题思路：
先将所有的单词建一个trie，然后在单词表的每个位置都进行一次dfs

遇到的问题：
竟然一次通过了。
但是感觉自己dfs那部分的代码写的有点啰嗦啊。回头看看别人是怎么实现的。
*/
class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
     
    struct node {
        bool isWord;
        unordered_map<char, node *> next;
        node() {
            isWord = false;
        }
    };
    
    node *head;
    
    void insert(const string &word) {
        auto cur = head;
        for (auto ch : word) {
            if (cur->next.find(ch) == cur->next.end()) {
                cur->next[ch] = new node();
            }
            cur = cur->next[ch];
        }
        cur->isWord = true;
    }
    
    void dfs(vector<string> &ans, vector<vector<char>> &board, int x, int y, vector<vector<bool>> &flag, node *cur, string &now) {
        if (cur->isWord == true) {
            ans.push_back(now);
            cur->isWord = false;
        }
        if (x > 0 && flag[x-1][y] == false && cur->next.find(board[x-1][y]) != cur->next.end()) {
            now.push_back(board[x-1][y]);
            flag[x-1][y] = true;
            dfs(ans, board, x-1, y, flag, cur->next[board[x-1][y]], now);
            now.pop_back();
            flag[x-1][y] = false;
        }
        if (y > 0 && flag[x][y-1] == false && cur->next.find(board[x][y-1]) != cur->next.end()) {
            now.push_back(board[x][y-1]);
            flag[x][y-1] = true;
            dfs(ans, board, x, y-1, flag, cur->next[board[x][y-1]], now);
            now.pop_back();
            flag[x][y-1] = false;
        }
        if (x < board.size()-1 && flag[x+1][y] == false && cur->next.find(board[x+1][y]) != cur->next.end()) {
            now.push_back(board[x+1][y]);
            flag[x+1][y] = true;
            dfs(ans, board, x+1, y, flag, cur->next[board[x+1][y]], now);
            now.pop_back();
            flag[x+1][y] = false;
        }
        if (y < board[0].size()-1 && flag[x][y+1] == false && cur->next.find(board[x][y+1]) != cur->next.end()) {
            now.push_back(board[x][y+1]);
            flag[x][y+1] = true;
            dfs(ans, board, x, y+1, flag, cur->next[board[x][y+1]], now);
            now.pop_back();
            flag[x][y+1] = false;
        }
    }
    
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        head = new node();
        for (auto w : words) {
            insert(w);
        }
        vector<string> ans;
        vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (head->next.find(board[i][j]) != head->next.end()) {
                    flag[i][j] = true;
                    string now;
                    now.push_back(board[i][j]);
                    dfs(ans, board, i, j, flag, head->next[board[i][j]], now);
                    flag[i][j] = false;
                }
            }
        }
        return ans;
    }
};
