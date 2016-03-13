/*
题目大意：
求n皇后的解的个数

解题思路：
用的回溯

遇到的问题：
没有。
*/
class Solution {
    int dfs(vector<bool> &col, vector<bool> &left2right, vector<bool> &right2left, int cur) {
        if (cur == col.size()) return 1;
        
        int ans = 0;
        for (int i = 0; i < col.size(); ++i) {
            if (col[i] == false && left2right[i+cur] == false 
                && right2left[col.size()-1-i+cur] == false) {
                
                col[i] = true;
                left2right[i+cur] = true;
                right2left[col.size()-1-i+cur] = true;
                
                ans += dfs(col, left2right, right2left, cur+1);
                
                col[i] = false;
                left2right[i+cur] = false;
                right2left[col.size()-1-i+cur] = false;
            }
        }
        
        return ans;
    }
    
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        vector<bool> col(n, false), left2right(n*2-1, false), right2left(n*2-1, false);
        return dfs(col, left2right, right2left, 0);
    }
};
