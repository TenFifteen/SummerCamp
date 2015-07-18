#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Problems: spiral matrix
 * Solve: use two variable to label the direction
 *        then walk step by step in the specified
 *        direction
 * Tips: must use the standard lib method 'memset' carefully
 *       
 */
int** generateMatrix(int n) 
{
	int **result = malloc(sizeof(int *) * n);	    
	int i, j;
	for (i = 0; i < n; ++i) {
		result[i] = malloc(sizeof(int) * n);
		for (j = 0; j < n; ++j) result[i][j] = 0;
		// if I use memset(result[i], 0, sizeof(result[i]));
		// I will get an incorrect initialization the second time
		// that is to say, some space haven't been set to 0
		// then the loop will go in wrong direction
	}

	int row_flag = 0, col_flag = 1;
	int count = 1;
	j = -1;
	i = 0;
	while (1) {
		if (col_flag == 1) {
			++j;
			while (j < n && !result[i][j]) {
				result[i][j++] = count++;
			}
			--j;
			col_flag = 0;
			row_flag = 1;
		} 

		if (row_flag == 1) {
			++i;
			while (i < n && !result[i][j]) {
				result[i++][j] = count++;
			}
			--i;
			col_flag = -1;
			row_flag = 0;
		} 

		if (col_flag == -1) {
			--j;
			while (j >= 0 && !result[i][j]) {
				result[i][j--] = count++;
			}
			++j;
			col_flag = 0;
			row_flag = -1;
		} 

		if (row_flag == -1) {
			--i;
			while (i >= 0 && !result[i][j]) {
				result[i--][j] = count++;
			}
			++i;
			col_flag = 1;
			row_flag = 0;
		} 

		if (count > n*n) break;
	}

	return result;
}

void print_matrix(int **m, int n) 
{
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

void free_matrix(int **m, int n)
{
	int i;
	for (i = 0; i < n; ++i) {
		free(m[i]);
	}
	free(m);
}
int main()
{
	int n;
	while (~scanf("%d", &n)) {
		int **m = generateMatrix(n);
		printf("The spiral matrix of size %d is:\n", n);
		print_matrix(m, n);
		free_matrix(m, n);
	}
}
