/**
 * Problem: Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.
 *           This matrix has the following properties:
 *           Integers in each row are sorted from left to right.
 *           Integers in each column are sorted from up to bottom.
 *           No duplicate integers in each row or column.
 * Solve: delete one row or column each time. When encounter a equal one, --col or ++row all OK
 * Tips: no
 */
class Solution {
    public:
        /**
         * @param matrix: A list of lists of integers
         * @param target: An integer you want to search in matrix
         * @return: An integer indicate the total occurrence of target in the given matrix
         */
        int searchMatrix(vector<vector<int> > &matrix, int target) {
            int m = matrix.size();
            if (m == 0) return 0;
            int n = matrix[0].size();

            int col = n - 1, row = 0;

            int cnt = 0;
            while (col >= 0 && row < m) {
                if (matrix[row][col] == target) {
                    ++cnt;
                    --col;
                } else if (matrix[row][col] < target) {
                    ++row;
                } else {
                    --col;
                }
            }

            return cnt;
        }
};
