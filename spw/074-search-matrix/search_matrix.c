#include <stdio.h>
#include <stdlib.h>

/**
 * Problem: given an matrix, whose elements are stored ordered from left to right.
 * Solve: bianry search
 * Tips: no
 */
int searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
	int left = 0, right = matrixRowSize * matrixColSize - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		int row = mid / matrixColSize;
		int col = mid % matrixColSize;

		int now = matrix[row][col];
		if (now == target) {
			return 1;
		} else if (now < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return 0;
}

int main()
{
}
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();

        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) ++i;
            else --j;
        }

        return false;
    }
};
