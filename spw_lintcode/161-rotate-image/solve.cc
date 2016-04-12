/**
 * Problem: You are given an n x n 2D matrix representing an image.
 *          Rotate the image by 90 degrees (clockwise).
 * Solve: swap up and down, swap by main diagonal
 * Tips: see comments below
 */
class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();

        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }

        // the i from 0 and the j from i + 1
        // the corresponding element is swap i/j
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
