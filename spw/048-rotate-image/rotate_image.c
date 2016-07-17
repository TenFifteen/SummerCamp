#include <stdio.h>
#include <stdlib.h>

#define N 100

void swap(int **v, int a, int b, int i, int j)
{
	if (v[a][b] == v[i][j]) return;
	v[a][b] =  v[a][b] ^ v[i][j];
	v[i][j] =  v[a][b] ^ v[i][j];
	v[a][b] =  v[a][b] ^ v[i][j];
}
/**
 * Problem: Rotate the matrix by 90 degrees (clockwise).
 * Solve: first reversal up and down, then fold along the diagonal.
 */
void rotate(int** matrix, int matrixRowSize, int matrixColSize)
{
	int i, j;
	for (i = 0; i < matrixRowSize/2; ++i) {
		for (j = 0; j < matrixColSize; ++j)	{
			swap(matrix, i, j, matrixRowSize-1-i, j);
		}
	}

	for (i = 0; i < matrixRowSize-1; ++i) {
		for (j = i+1; j < matrixColSize; ++j)	{
			swap(matrix, i, j, j, i);
		}
	}
}

void print_matrix(int **m, int n)
{
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j)	{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n;
	int **matrix;
	while (~scanf("%d", &n)) {
		int i, j;
		matrix = malloc(sizeof(int*) * n);
		for (i = 0; i < n; ++i) {
			matrix[i] = malloc(sizeof(int) * n);
			for (j = 0; j < n; ++j)	{
				scanf("%d", &matrix[i][j]);
			}
		}

		printf("The origin matrix is:\n");
		print_matrix(matrix, n);

		rotate(matrix, n, n);

		printf("The rotated matrix is:\n");
		print_matrix(matrix, n);
	}

	return 0;
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        updown(matrix);
        diagonal(matrix);
    }

    void updown(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }
    }

    void diagonal(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = i+1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
