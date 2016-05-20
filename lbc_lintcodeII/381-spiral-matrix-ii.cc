/*
题目大意：
给定一个矩阵，把1-n*n按照顺时针方向写进去。

解题思路：
见代码。

遇到的问题：
没有。
*/
class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        //assert(n >= 0);
        vector<vector<int>> ans(n, vector<int>(n));
        
        int now = 1, left = 0, right = n-1, top = 0, bot = n-1;
        while (now <= n*n) {
            for (int i = left; i <= right; ++i) ans[top][i] = now++;
            top++;
            
            if (now <= n*n) for (int i = top; i <= bot; ++i) ans[i][right] = now++;
            right--;
            
            if (now <= n*n) for (int i = right; i >= left; --i) ans[bot][i] = now++;
            bot--;
            
            if (now <= n*n) for (int i = bot; i >= top; --i) ans[i][left] = now++;
            left++;
        }
        
        return ans;
    }
};
