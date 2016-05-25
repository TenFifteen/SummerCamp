/*
题目大意：
解n皇后问题

解题思路：
回溯。

遇到的问题：
一开始竟然忘记了斜线也可以攻击。
哎呀，这脑子。

再次阅读：
这个题目以前是大一就做过的。就是一个用递归回溯的经典题目。
然后其实还是有一点可以优化的，就是可以用一个bit来表示某行某列是否被占用。
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string tmp(n, '.');
        vector<string> cur(n, tmp);
        vector<bool> left(n*2-1, false);
        vector<bool> right(n*2-1, false);
        vector<bool> col(n, false);
        sub(ans, cur, n, 0, col, left, right);
        return ans;
    }
    
    void sub(vector<vector<string>> &ans, vector<string> &cur, int n, int row, vector<bool> &col, vector<bool> &left, vector<bool> &right){
        if(row == n){
            ans.push_back(cur);
            return;
        }
        for(int i = 0; i < n; ++i){
            if(col[i])continue;
            if(left[n-1-i+row])continue;
            if(right[i+row])continue;
            col[i] = true;
            cur[row][i] = 'Q';
            left[n-1-i+row] = true;
            right[i+row] = true;
            sub(ans, cur, n, row+1, col, left, right);
            cur[row][i] = '.';
            col[i] = false;
            left[n-1-i+row] = false;
            right[i+row] = false;
        }
    }
};
/*
第二次做：
这次跟上次是一个思路的。
*/
class Solution {
private:
    void dfs(vector<vector<string> > &ans, vector<string> &board, vector<bool> &col, 
    vector<bool> &left, vector<bool> &right, int row) {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }
        
        for (int i = 0; i < board.size(); ++i) {
            if (col[i] && left[row+i] && right[board.size()-1-i+row]) {
                col[i] = false;
                left[row+i] = false;
                right[board.size()-1-i+row] = false;
                
                board[row][i] = 'Q';
                dfs(ans, board, col, left, right, row+1);
                board[row][i] = '.';
                
                col[i] = true;
                left[row+i] = true;
                right[board.size()-1-i+row] = true;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string> > ans;
        vector<bool> col(n, true), left(n*2-1, true), right(n*2-1, true);
        
        dfs(ans, board, col, left, right, 0);
        return ans;
    }
};