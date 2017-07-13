/**
 * Problem: In MATLAB, there is a very useful function called 'reshape', which
 *          can reshape a matrix into a new one with different size but keep
 *          its original data.
 *          You're given a matrix represented by a two-dimensional array, and
 *          two positive integers r and c representing the row number and column
 *          number of the wanted reshaped matrix, respectively.
 *          The reshaped matrix need to be filled with all the elements of the
 *          original matrix in the same row-traversing order as they were.
 *          If the 'reshape' operation with given parameters is possible and
 *          legal, output the new reshaped matrix; Otherwise, output the original matrix.
 * Solve: just lay row by row
 * Tips: calculate the position in the origin matrix
 */
class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
            if (nums.size() == 0) return nums;

            int m = nums.size(), n = nums[0].size();
            if (r * c > m * n) return nums;

            int pos = 0;
            vector<vector<int>> res(r, vector<int>(c));
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    int a = pos / n, b = pos % n;
                    res[i][j] = nums[a][b];

                    ++pos;
                }
            }

            return res;
        }
};
