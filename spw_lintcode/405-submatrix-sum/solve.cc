/**
 * Problem: Given an integer matrix, find a submatrix where the sum of numbers is zero.
 *          Your code should return the coordinate of the left-up and right-down number.
 * Solve: 1. The same idea with the map O(n)  for the vector corresponding problem.
 *        2. Use a sum matrix as the bridge. Use the partial sum, we can convert the sum = 0
 *           to the equality of two matrix.
 * Tips: see comments below.
 */
class Solution {
    public:
        /**
         * @param matrix an integer matrix
         * @return the coordinate of the left-up and right-down number
         */
        vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
            vector<vector<int>> ans(2, vector<int>());

            int m = matrix.size();
            if (m == 0) return ans;
            int n = matrix[0].size();

            vector<vector<int>> sum(m+1, vector<int>(n+1, 0));
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    sum[i][j] = sum[i-1][j] + sum[i][j-1] + matrix[i-1][j-1] - sum[i-1][j-1];
                }
            }

            // partial sum require sum[i]-sum[j] = sum{arr[i+1 ... j]}
            // Then the index should go from 0
            for (int up = 0; up <= m; ++up) {
                for (int down = up+1; down <= m; ++down) {
                    unordered_map<int, int> index;
                    for (int i = 0; i <= n; ++i) {
                        int m = sum[down][i] - sum[up][i];
                        if (index.find(m) != index.end()) {
                            // partial sum require sum[i]-sum[j] = sum{arr[i+1 ... j]}
                            ans[0].push_back(up);
                            ans[0].push_back(index[m]);

                            ans[1].push_back(down-1);
                            ans[1].push_back(i-1);
                            return ans;
                        } else {
                            index[m] = i;
                        }
                    }
                }
            }

            return ans;
        }
};
