/*
题目：20 % N皇后问题 中等

题目大意：
用非递归的方式实现n皇后

解题思路：
用循环的方式模拟递归。

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<vector<string>> ans;
        int col = 0;
        vector<bool> flag_row(n, false), flag_col(n, false);
        vector<bool> flag_left(n*2-1, false), flag_right(n*2-1, false);
        vector<int> row(n, 0);
        while (col >= 0) {
            if (col == n) {
                vector<string> board;
                for (int i = 0; i < n; ++i) {
                    string line(n, '.');
                    line[row[i]] = 'Q';
                    board.push_back(line);
                }
                ans.push_back(board);
                col--;
                flag_row[row[col]] = false;
                flag_col[col] = false;
                flag_left[n-1-col+row[col]] = false;
                flag_right[col+row[col]] = false;
                row[col]++;
            }
            if (row[col] < n) {
                if (!flag_row[row[col]] && !flag_col[col]
                    && !flag_left[n-1-col+row[col]]
                    && !flag_right[col+row[col]]) {
                    flag_row[row[col]] = true;
                    flag_col[col] = true;
                    flag_left[n-1-col+row[col]] = true;
                    flag_right[col+row[col]] = true;
                    col++;
                    if (col < n) {
                        row[col] = 0;
                    }
                } else {
                    row[col]++;
                }
            } else {
                col--;
                if (col >= 0) {
                    flag_row[row[col]] = false;
                    flag_col[col] = false;
                    flag_left[n-1-col+row[col]] = false;
                    flag_right[col+row[col]] = false;
                    row[col]++;
                }
            }
        }
        return ans;
    }
};

