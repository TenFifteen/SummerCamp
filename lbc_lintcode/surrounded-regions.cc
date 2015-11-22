/*
题目：32 % Surrounded Regions 新添加 中等

题目大意：
给定一个二维的矩阵。将其中所有被X包围的O变成X

解题思路：
dfs

遇到的问题：
没有问题，一次通过了。
*/
class Solution {
public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        if (board.size() < 2 || board[0].size() < 2) {
            return;
        }
        
        for (int i = 0; i < board.size(); ++i) {
            dfs(board, i, 0);
            dfs(board, i, board[0].size()-1);
        }
        for (int i = 1; i+1 < board[0].size(); ++i) {
            dfs(board, 0, i);
            dfs(board, board.size()-1, i);
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    void dfs(vector<vector<char> > &board, int x, int y) {
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || 
                board[x][y] != 'O') {
            return;
        }
        
        board[x][y] = '1';
        
        static const int ix[] = {-1, 0, 1, 0};
        static const int iy[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; ++i) {
            dfs(board, x+ix[i], y+iy[i]);
        }
    }
};
