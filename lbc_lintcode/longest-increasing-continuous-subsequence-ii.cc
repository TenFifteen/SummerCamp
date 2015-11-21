/*
题目：22 % 最长上升连续子序列 II 困难

题目大意：
给定一个二维数组，问其中最长的连续上升子序列是多长？
连续的意思是可以上下左右相连

解题思路：
用dp+dfs的方法。

遇到的问题：
一开始有一点想到这上面，但是从来没有这么写过，都不知道对不对。
然后看了别人的思路，想了半天才想明白这是对的。
这个思路还是挺开阔的，以后可以多用用。
*/
class Solution {
private:
    int dfs(vector<vector<int> > &ans, vector<vector<int> > &A, int i, int j) {
        if (ans[i][j] != 0) {
            return ans[i][j];
        }
        
        int ix[] = {1, 0, -1, 0};
        int iy[] = {0, 1, 0, -1};
        
        for (int a = 0; a < 4; ++a) {
            int x = ix[a] + i;
            int y = iy[a] + j;
            if (x >= 0 && x < A.size() && y >= 0 && y < A[0].size() && A[x][y] > A[i][j]) {
                ans[i][j] = max(ans[i][j], dfs(ans, A, x, y));
            }
        }
        
        ++ans[i][j];
        
        return ans[i][j];
    }
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        // Write your code here
        if (A.size() == 0 || A[0].size() == 0) return 0;
        
        vector<vector<int> > ans(A.size(), vector<int>(A[0].size(), 0));
        int ret = 0;
        
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                ret = max(ret, dfs(ans, A, i, j));
            }
        }
        
        return ret;
    }
};
