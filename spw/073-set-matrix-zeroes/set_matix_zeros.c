/**
 * Problem: Given a m x n matrix, if an element is 0,
 *          set its entire row and column to 0. Do it in place.
 * Solve: use one row which should be zero as flag vector
 * Tips: see comments
 */
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int i, j, k;
    int flag_row = -1;
    for (i = 0; i < matrixRowSize; ++i) {
        for (j = 0; j < matrixColSize; ++j) {
            if (matrix[i][j] == 0) {
                if (flag_row == -1) {
                    flag_row = i;
                    for (k = 0; k < matrixColSize; ++k) {
                        // set 1 as flag
                        // and the other will 0 at last, then we set it here in advance
                        matrix[flag_row][k] = matrix[flag_row][k] == 0 ? 1 : 0;
                    }
                    break;
                } else {
                    for (k = 0; k < matrixColSize; ++k) {
                        // warn!!
                        matrix[flag_row][k] = matrix[i][k] == 0 ? 1 : matrix[flag_row][k];
                        matrix[i][k] = 0;
                    }
                    break;
                }
            }
        }
    }

    // if there is none zero in the matrix
    if (flag_row == -1) return;

    for (j = 0; j < matrixColSize; ++j) {
        if (matrix[flag_row][j]) {
            for (i = 0; i < matrixRowSize; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();
            if (m == 0) return;
            int n = matrix[0].size();

            int flagRow = -1;
            for (int i = 0; i < m; ++i) {
                bool row = false;
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == 0) {
                        if (flagRow == -1)
                            flagRow = i;
                        matrix[flagRow][j] = 0;
                        row = true;
                    }
                }

                if (i != flagRow && row) {
                    for (int j = 0; j < n; ++j)
                        matrix[i][j] = 0;
                }
            }

            if (flagRow == -1) return;

            for (int j = 0; j < n; ++j) {
                if (matrix[flagRow][j] == 0) {
                    for (int i = 0; i < m; ++i)
                        matrix[i][j] = 0;
                }
            }
            for (int j = 0; j < n; ++j)
                matrix[flagRow][j] = 0;

        }
};
