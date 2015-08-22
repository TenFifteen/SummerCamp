/*
题目：38 % N皇后问题 II 中等

题目大意：
求解n皇后的个数，而不是所有的解。

解题思路：
与33题相同，只不过这次的ans的类型需要变一下。

遇到的问题：
没有问题。
*/
class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        int ans = 0;
        int col = 0;
        vector<bool> flag_row(n, false), flag_col(n, false);
        vector<bool> flag_left(n*2-1, false), flag_right(n*2-1, false);
        vector<int> row(n, 0);
        while (col >= 0) {
            if (col == n) {
                ans++;
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

