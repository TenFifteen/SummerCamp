/**
 * Problem: Given a m x n matrix, if an element is 0, set
 *          its entire row and column to 0. Do it in place.
 * Solve: use the first row who has 0 as the flag row, then
 *        traversal the whole matrix and set the row if that
 *        column position has zero.
 * Tips: if flagRow has not been set should return.
 *       More details see comments below.
 */
class Solution {
    public:
        /**
         ** @param matrix: A list of lists of integers
         ** @return: Void
         **/
        void setZeroes(vector<vector<int> > &matrix) {
            int m = matrix.size();
            if (m == 0) return;
            int n = matrix[0].size();

            int flagRow = -1;
            for (int i = 0; i < m; ++i) {
                bool flag = false;
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == 0) {
                        flag = true;
                        if (flagRow == -1) {
                            flagRow = i;
                            break;

                        } else {
                            matrix[flagRow][j] = 0;
                        }
                    }
                }

                if (flag && i != flagRow) {
                    for (int j = 0; j < n; ++j) {
                        matrix[i][j] = 0;
                    }
                }
            }

            if (flagRow == -1) return;

            for (int j = 0; j < n; ++j) {
                if (matrix[flagRow][j] == 0) {
                    for (int i = 0; i < m; ++i)
                        matrix[i][j] = 0;

                }

            }

            for (int j = 0; j < n; ++j) matrix[flagRow][j] = 0;

        }

};
