#include <stdio.h>
#include <stdlib.h>

/**
 * Problem: Given a matrix of m x n elements (m rows, n columns),
 *          return all elements of the matrix in spiral order.
 * Solve: use four variable to label fontier.
 * Tips: see below: when the matrix is not square matrix, the next
 *       two loop may be out of the range
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize)
{
    if (matrixColSize * matrixRowSize == 0) return NULL;

    int *ans = malloc(sizeof(int) * (matrixRowSize * matrixColSize));

    int left = 0, right = matrixColSize-1, up = 0, down = matrixRowSize-1;
    int i, j;
    int count = 0;

    while (left <= right && up <= down) {
        i = up;
        for (j = left; j <= right; ++j)	{
            ans[count++] = matrix[i][j];
        }
        up++;

        j = right;
        for (i = up; i <= down; ++i) {
            ans[count++] = matrix[i][j];
        }
        right--;

        // because the up++, when the matrix is not square
        // 1 2 3 4
        if (up <= down) {
            i = down;
            for (j = right; j >= left; --j) {
                ans[count++] = matrix[i][j];
            }
        }
        down--;

        // because the up++, when the matrix is not square
        // 1
        // 2
        // 3
        // 4
        if (left <= right) {
            j = left;
            for (i = down; i >= up; --i) {
                ans[count++] = matrix[i][j];
            }
        }
        left++;
    }

    return ans;
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
    int i, j, n;
    int **m;
    while (~scanf("%d", &n)) {
        m = malloc(sizeof(int*) * (n));
        for (i = 0; i < n; ++i) {
            m[i] = malloc(sizeof(int) * (n));
            for (j = 0; j < n; ++j) {
                scanf("%d", &m[i][j]);
            }
        }

        print_matrix(m, n);
        int *ans = spiralOrder(m, n, n);
        for (i = 0; i < n*n; ++i) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        free(ans);
        free_matrix(m, n);
    }

    return 0;
}

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans;
            int m = matrix.size();
            if (m <= 0) return ans;
            int n = matrix[0].size();

            vector<int> res(m*n);

            int left = 0, right = n - 1, up = 0, down = m - 1;
            int pos = 0;

            while (left <= right && up <= down) {
                for (int i = left; i <= right; ++i)
                    res[pos++] = matrix[up][i];
                ++up;

                for (int i = up; i <= down; ++i)
                    res[pos++] = matrix[i][right];
                --right;

                // the for condition control left <= right
                // then after ++up, we must determine if
                // up <= down.
                if (up <= down) {
                    for (int i = right; i >= left; --i)
                        res[pos++] = matrix[down][i];
                    --down;
                }

                if (left <= right) {
                    for (int i = down; i >= up; --i)
                        res[pos++] = matrix[i][left];
                    ++left;
                }
            }

            return res;
        }
};
