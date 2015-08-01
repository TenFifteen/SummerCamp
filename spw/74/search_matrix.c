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
