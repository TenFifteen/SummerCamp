/*
题目大意：
给定一个二维的board，将所有被X包围起来的O都替换成X

解题思路：
dfs

遇到的问题：
没有。
*/
class Solution {
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() ||
            board[x][y] != 'O') return;
        
        board[x][y] = 'A';
        
        const int ix[] = {-1, 0, 1, 0};
        const int iy[] = {0, -1, 0, 1};
        for (int i = 0;i < 4; ++i) {
            dfs(board, x+ix[i], y+iy[i]);
        }
    }
    
    void flip(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'A') board[i][j]  = 'O';
            }
        }
    }
    
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        if (board.size() < 3 || board[0].size() < 3) return;
        
        for (int i = 0; i < board.size(); ++i) {
            dfs(board, i, 0);
            dfs(board, i, board[0].size()-1);
        }
        
        for (int i = 1; i < board[0].size()-1; ++i) {
            dfs(board, 0, i);
            dfs(board, board.size()-1, i);
        }
        
        flip(board);
    }
};