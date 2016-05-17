/**
 * Problem: Write an efficient algorithm that searches for a value in an m x n matrix.
 *          This matrix has the following properties:
 *          Integers in each row are sorted from left to right.
 *          The first integer of each row is greater than the last integer of the previous row.
 * Solve: binary search treated it as a vector instead of a matrix.
 * Tips: no
 */
class Solution {
    public:
        /**
         *      * @param matrix, a list of lists of integers
         *           * @param target, an integer
         *                * @return a boolean, indicate whether matrix contains target
         *                     */
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            int m = matrix.size();
            if (m == 0) return false;

            int n = matrix[0].size();
            int left = 0, right = m*n - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;

                int i = mid / n, j = mid % n;
                if (matrix[i][j] == target) {
                    return true;

                } else if (matrix[i][j] < target) {
                    left = mid + 1;

                } else {
                    right = mid - 1;

                }

            }

            return false;

        }

};

