#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>

using namespace std;

/**
 * Problem: Find the kth smallest number in at row and column sorted matrix.
 * Solve: Treat the matrix as a head.
 * Tips: 1. Label the used space as INT_MAX.
 *       2. Traversal the matrix level by level with diagonal line from the
 *       top right corner to the left bottom corner.
 *
 */
void printMatrix(vector<vector<int> > &matrix) {
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[0].size(); ++j){
            printf("%11d", matrix[i][j]);
        }
        cout << endl;
    }
}
void minHeapify(vector<vector<int> > &matrix, int i, int j) {
    if (i + 1 >= matrix.size()) { // child below is invalid
        if (j + 1 >= matrix[0].size()) return; // child right is invalid
        if (matrix[i][j+1] < matrix[i][j]) {
            // swap
            int tmp = matrix[i][j+1];
            matrix[i][j+1] = matrix[i][j];
            matrix[i][j] = tmp;
            // recursive
            minHeapify(matrix, i, j+1);
        }
    } else {// child below is valid
        int x = i + 1, y = j;
        // compare with the child right.
        if (j + 1 < matrix[0].size() && matrix[i][j+1] < matrix[x][y]) {
            --x, ++y;
        }
        // warning!!! Condition
        if (matrix[x][y] < matrix[i][j]) {
            // swap
            int tmp = matrix[x][y];
            matrix[x][y] = matrix[i][j];
            matrix[i][j] = tmp;
            // recursive
            minHeapify(matrix, x, y);
        }
    }
}

/**
 * @param matrix: a matrix of integers
 * @param k: an integer
 * @return: the kth smallest number in the matrix
 */
int kthSmallest(vector<vector<int> > &matrix, int k) {
    // write your code here
    int m = matrix.size();
    if (m == 0) return INT_MIN;
    int n = matrix[0].size();
    if (k > m * n) return INT_MIN;

    int x = m - 1, y = n - 1;
    int total = x + y;
    for (int times = 1; times < k; ++times) {
        matrix[0][0] = matrix[x][y];
        matrix[x][y] = INT_MAX;

        minHeapify(matrix, 0, 0);

        if (x == m - 1 || y == 0) {
            total--;
            if (total > n - 1) {
                y = n - 1;
                x = total - y;
            } else {
                x = 0;
                y = total;
            }
        } else {
            ++x;
            --y;
        }
    }
    printMatrix(matrix);

    return matrix[0][0];
}

int main() {
    int test[4][5] = {{1,2,3,4,5}, {2,3,4,5,6}, {3,4,5,6,7},{4,5,6,7,8}};
    vector<vector<int> > input(4, vector<int>(5, 0));
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 5; ++j){
            input[i][j] = test[i][j];
        }
    }

    kthSmallest(input, 19);
}
