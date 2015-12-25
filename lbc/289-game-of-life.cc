/*
题目大意：
给定一个二维的01矩阵，1表示live，0表示dead
在下一轮中：
如果当前格子为live，并且周围live的数量小于2或者大于3，那么当前格子就死了。
如果当前格子为dead，并且周围live的数量正好是3，则当前格子就复活了。
让我们实现一个原地的变换。

解题思路：
见代码，就是将各种状态用数字表示出来。
但是这种解法如果是在bool表示的表格中，就不是很适用了。

遇到的问题：
哎，其中一个地方把i写成了j。
让我检查错误检查了老半天。
*/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 0 dead
        // 1 live
        // 2 dead to live
        // 3 live to dead
        const static int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        const static int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = dx[k] + i;
                    int y = dy[k] + j;
                    if (x < 0 || y < 0 || x >= board.size() || y >= board[i].size()) continue;
                    if (board[x][y] == 1 || board[x][y] == 3) cnt++;
                }
                if (board[i][j] == 0) {
                    if (cnt == 3) {
                        board[i][j] = 2;
                    }
                } else {
                    if (cnt < 2 || cnt > 3) {
                        board[i][j] = 3;
                    }
                }
            }
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                } else if (board[i][j] == 3) {
                    board[i][j] = 0;
                }
            }
        }
    }
};