/*
题目大意：
求n皇后问题，用迭代的方式

解题思路：
没有太大问题。

遇到的问题：
第一次写迭代式，感觉的确是没有递归的代码好看。
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
        vector<string> now(n, string(n, '.'));
        vector<bool> col(n, false), left2right(n*2-1, false),
                     right2left(n*2-1, false);
        
        int cur = 0;
        bool back = false;
        vector<int> row(n, 0);
        
        while (cur >= 0) {
            if (cur == n) {
                ans.push_back(now);
                cur--;
                back = true;
                continue;
            }
            
            if (back == false) {
                bool found = false;
                for (int i = 0; i < n; ++i) {
                    if (col[i] == false && left2right[cur+i] == false 
                        && right2left[cur+n-1-i] == false) {
                        row[cur] = i;
                        now[cur][i] = 'Q';
                        col[i] = true;
                        left2right[cur+i] = true;
                        right2left[cur+n-1-i] = true;
                        cur++;
                        found = true;
                        break;
                    }
                }
                if (found) continue;
                
                cur--;
                back = true;
                continue;
            } else {
                now[cur][row[cur]] = '.';
                col[row[cur]] = false;
                left2right[cur+row[cur]] = false;
                right2left[cur+n-1-row[cur]] = false;
                
                bool found = false;
                for (int i = row[cur]+1; i < n; ++i) {
                    if (col[i] == false && left2right[cur+i] == false
                        && right2left[cur+n-1-i] == false) {
                        row[cur] = i;
                        now[cur][i] = 'Q';
                        col[i] = true;
                        left2right[cur+i] = true;
                        right2left[cur+n-1-i] = true;
                        back = false;
                        cur++;
                        found = true;
                        break;;
                    }
                }
                if (found) continue;
                
                cur--;
                continue;
            }
        }
        
        return ans;
    }
};
