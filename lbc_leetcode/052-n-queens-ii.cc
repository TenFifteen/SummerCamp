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
/*
第二次做：
跟上次一样，拿上一个题目的代码过来简化一下就行了。
*/
class Solution {
private:
    int dfs(vector<bool> &col, vector<bool> &left, vector<bool> &right, int row, int n) {
        if (row == n) {
            return 1;
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (col[i] && left[row+i] && right[n-1-i+row]) {
                col[i] = false;
                left[row+i] = false;
                right[n-1-i+row] = false;

                ans += dfs(col, left, right, row+1, n);

                col[i] = true;
                left[row+i] = true;
                right[n-1-i+row] = true;
            }
        }
        return ans;
    }

public:
    int totalNQueens(int n) {
        vector<bool> col(n, true), left(n*2-1, true), right(n*2-1, true);

        return dfs(col, left, right, 0, n);
    }
};
/*
 * 很好
 */
class Solution {
private:
    int solve(int x, vector<bool> &col, vector<bool> &left, vector<bool> &right) {
        if (x == col.size()) return 1;

        int ans = 0;
        for (int i = 0; i < col.size(); ++i) {
            if (col[i] || left[i+x] || right[col.size()-1+x-i]) continue;
            col[i] = true;
            left[i+x] = true;
            right[col.size()-1+x-i] = true;
            ans += solve(x+1, col, left, right);
            col[i] = false;
            left[i+x] = false;
            right[col.size()-1-i+x] = false;
        }
        return ans;
    }

public:
    int totalNQueens(int n) {
        vector<bool> col(n, false), left(n*2-1, false), right(n*2-1, false);
        return solve(0, col, left, right);
    }
};
