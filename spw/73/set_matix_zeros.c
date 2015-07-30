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
