/*
题目大意：
解n皇后问题

解题思路：
回溯。

遇到的问题：
一开始竟然忘记了斜线也可以攻击。
哎呀，这脑子。
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