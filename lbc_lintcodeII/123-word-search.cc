/*
题目大意：
给定一个二维字母表，一个单词。问是否可以在表中找到该单词。

解题思路：
dfs

遇到的问题：
一开始忘记了将当前单词标记为不可用了。
*/
class Solution {
    bool existWord(vector<vector<char>> &board, string &word, int index, int x, int y) {
        if (index == word.size()) return true;
        
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[index]) return false;
        
        char old = board[x][y];
        board[x][y] = 0;
        
        const int ix[] = {-1, 0, 1, 0};
        const int iy[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; ++i) {
            if (existWord(board, word, index+1, x+ix[i], y+iy[i])) return true;
        }
        
        board[x][y] = old;
        return false;
    }
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (existWord(board, word, 0, i, j)) return true;
            }
        }
        
        return false;
    }
};