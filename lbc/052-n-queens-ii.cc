/*
题目大意：
n皇后，但是返回的是个数。

解题思路：
与51相同，而且不需要记录当前的棋盘，反而更加简单了。

遇到的问题：
一次通过。

再次阅读：
同上一题。
*/
class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<bool> left(n*2-1, false);
        vector<bool> right(n*2-1, false);
        vector<bool> col(n, false);
        sub(ans, n, 0, col, left, right);
        return ans;
    }
    
    void sub(int &ans, int n, int row, vector<bool> &col, vector<bool> &left, vector<bool> &right){
        if(row == n){
            ans++;
            return;
        }
        for(int i = 0; i < n; ++i){
            if(col[i])continue;
            if(left[n-1-i+row])continue;
            if(right[i+row])continue;
            col[i] = true;
            left[n-1-i+row] = true;
            right[i+row] = true;
            sub(ans, n, row+1, col, left, right);
            col[i] = false;
            left[n-1-i+row] = false;
            right[i+row] = false;
        }
    }
};