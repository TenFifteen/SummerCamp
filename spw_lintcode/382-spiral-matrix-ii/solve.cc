/**
 * Problem: Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.
 * Solve: use a vector and less boundary tests.
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param n an integer
         * @return a square matrix
         */
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> ans(n, vector<int>(n, 0));

            int l = 0, r = n-1, t = 0, b = n-1;

            int cnt = 1;
            while (l <= r && t <= b) {
                for (int i = l; i <= r; ++i) ans[t][i] = cnt++;
                ++t;

                for (int i = t; i <= b; ++i) ans[i][r] = cnt++;
                --r;

                for (int i = r; i >= l; --i) ans[b][i] = cnt++;
                --b;

                for (int i = b; i >= t; --i) ans[i][l] = cnt++;
                ++l;
            }

            return ans;
        }
};
