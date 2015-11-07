/*
题目：33 % 找峰值 II 困难

题目大意：
给定一个二维的数组，找到其中一个峰值

解题思路：
二分。每次找到当前矩阵的中间元素，判断是否是峰值，如果是就返回，
不是的话，就将该行以及该列中的最大值找到，如果是峰值就返回，如果不是，
向四个小矩阵中进行寻找。

遇到的问题：
这个题目原来是他们面试google的面试题来着，终于有机会做一下了。
这么难看的复杂的逻辑，竟然一次通过了。我自己都不敢相信了。
*/
class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > A) {
        // write your code here
        return sub(A, 0, 0, A.size()-1, A[0].size()-1);
    }
    
    vector<int> sub(vector<vector<int>> &A, int top_x, 
                    int top_y, int bot_x, int bot_y) {
        int mid_x = top_x + (bot_x - top_x)/2;
        int mid_y = top_y + (bot_y - top_y)/2;
        if (mid_x == 0) {
            mid_x++;
        } else if (mid_x = A.size()-1) {
            mid_x--;
        }
        if (mid_y == 0) {
            mid_y++;
        } else if (mid_y == A[0].size()-1) {
            mid_y--;
        }
        
        if (    A[mid_x][mid_y] > A[mid_x+1][mid_y] &&
                A[mid_x][mid_y] > A[mid_x-1][mid_y] &&
                A[mid_x][mid_y] > A[mid_x][mid_y+1] &&
                A[mid_x][mid_y] > A[mid_x][mid_y-1]) {
            vector<int> ans(2);
            ans[0] = mid_x;
            ans[1] = mid_y;
            return ans;
        }
        
        int next_x = mid_x;
        int next_y = mid_y;
        for (int i = 1; i+1 < A.size(); ++i) {
            if (A[i][mid_y] > A[next_x][next_y]) {
                next_x = i;
                next_y = mid_y;
            }
        }
        for (int i = 1; i+1 < A[0].size(); ++i) {
            if (A[mid_x][i] > A[next_x][next_y]) {
                next_x = mid_x;
                next_y = i;
            }
        }
        
        if (    A[next_x][next_y] > A[next_x][next_y+1] &&
                A[next_x][next_y] > A[next_x][next_y-1] &&
                A[next_x][next_y] > A[next_x-1][next_y] &&
                A[next_x][next_y] > A[next_x+1][next_y]) {
            vector<int> ans(2);
            ans[0] = next_x;
            ans[1] = next_y;
            return ans;
        }
        
        if (next_x > mid_x) {
            if (A[next_x][next_y] < A[next_x][next_y-1]) {
                return sub(A, mid_x+1, top_y, bot_x, mid_y-1); // top_right
            } else {
                return sub(A, mid_x+1, mid_y+1, bot_x, bot_y); // bot_right
            }
        } else if (next_x < mid_x) {
            if (A[next_x][next_y] < A[next_x][next_y-1]) {
                return sub(A, top_x, top_y, mid_x-1, mid_y-1); //top_left
            } else {
                return sub(A, top_x, mid_y, mid_x+1, bot_y); //bot_left
            }
        } else if (next_y < mid_y) {
            if (A[next_x][next_y] < A[next_x-1][next_y]) {
                return sub(A, top_x, top_y, mid_x-1, mid_y-1); //top_left
            } else {
                return sub(A, mid_x+1, top_y, bot_x, mid_y-1); // top_right
            }
        } else {
            if (A[next_x][next_y] < A[next_x-1][next_y]) {
                return sub(A, top_x, mid_y, mid_x+1, bot_y); //bot_left
            } else {
                return sub(A, mid_x+1, mid_y+1, bot_x, bot_y); // bot_right
            }
        }
    }
};

