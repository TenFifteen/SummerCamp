/**
 * Problem: Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * Solve: use four pointer
 * Tips: see comments below
 */
class Solution {
    public:
        /**
         * @param matrix a matrix of m x n elements
         * @return an integer array
         */
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int m = matrix.size();
            if (m == 0) {
                vector<int> ans;
                return ans;
            }
            int n = matrix[0].size();

            vector<int> ans(m*n, 0);
            int l = 0, r = n-1, t = 0, b = m-1;

            int index = 0;
            while (l <= r && t <= b) {
                for (int i = l; i <= r; ++i) ans[index++] = matrix[t][i];
                ++t;

                for (int i = t; i <= b; ++i) ans[index++] = matrix[i][r];
                --r;

                // when ++t, t will probably larger than b
                if (t <= b) {
                    for (int i = r; i >= l; --i) ans[index++] = matrix[b][i];
                    --b;
                }

                // when --r, r will probably smaller than l
                if (l <= r) {
                    for (int i = b; i >= t; --i) ans[index++] = matrix[i][l];
                    ++l;
                }

            }

            return ans;
        }
};
