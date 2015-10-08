/*
题目：25 % 单词搜索 中等

题目大意：
给定一个单词和一个二维的字母表，问是否可以在字母表中找到该单词。

解题思路：
搜索。

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (sub(board, flag, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    
    bool sub(vector<vector<char>> &board, vector<vector<bool>> &flag, string &word, int index, int x, int y) {
        if (board[x][y] != word[index]) return false;
        if (index + 1 == word.size()) return true;
        flag[x][y] = true;
        bool ok = false;
        if (x > 0 && flag[x-1][y] == false) {
            ok = sub(board, flag, word, index+1, x-1, y);
        }
        if (ok == false && x < board.size()-1 && flag[x+1][y] == false) {
            ok = sub(board, flag, word, index+1, x+1, y);
        }
        if (ok == false && y > 0 && flag[x][y-1] == false) {
            ok = sub(board, flag, word, index+1, x, y-1);
        }
        if (ok == false && y < board[0].size()-1 && flag[x][y+1] == false) {
            ok = sub(board, flag, word, index+1, x, y+1);
        }
        
        flag[x][y] = false;
        return ok;
    }
};
