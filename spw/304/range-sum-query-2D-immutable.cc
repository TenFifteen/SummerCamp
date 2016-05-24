/**
 * Problem: Given a 2D matrix matrix, find the sum of the elements inside the rectangle
 *          defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
 * Solve: dp + partial sum
 * Tips: resize
 */
class NumMatrix {
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        if (m <= 0) return;

        int n = matrix[0].size();

        sum.resize(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // in parentheses, should be row2+1 and col2+1
        return sum[row2+1][col2+1] - (sum[row1][col2+1] + sum[row2+1][col1] - sum[row1][col1]);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
