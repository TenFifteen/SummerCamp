#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Write an efficient algorithm that searches for a value
 *          in an m x n matrix. This matrix has the following properties:
 *          **Integers in each row are sorted in ascending from left to right.
 *          **Integers in each column are sorted in ascending from top to bottom.
 * Solve: delete a row or a column every time.
 * Tips: no
 */
bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    int row = 0, col = n - 1;
    while (row < m && col >= 0) {
        int now = matrix[row][col];
        if (now == target) {
            return true;
        } else if (now > target) {
            --col;
        } else {
            ++row;
        }
    }

    return false;

}

int main()
{
    vector<vector<int> > matrix(2, vector<int>(1, 0));
    matrix [0][0] = 5;
    matrix [1][0] = 6;
    searchMatrix(matrix, 6);

}
