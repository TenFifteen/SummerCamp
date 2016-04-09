#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Given a matrix of m x n elements (m rows, n columns), return
 *          all elements of the matrix in ZigZag-order.
 * Solve: find the total level, and the boundary of every level, and
 *        use the times to determine the iterator direction.
 * Tips: the boundary.
 */
vector<int> printZMatrix(vector<vector<int> > &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    int sum = 0, total = m+n-2, cnt = 0;
    vector<int> ans(m*n);

    while (sum <= total) {
        // carefully calculate the edge
        int end = min(sum, m-1);
        int begin = max(sum-n+1, 0);

        if (sum % 2 == 1) {
            for (int i = begin; i <= end; ++i)
                ans[cnt++] = matrix[i][sum-i];

        } else {
            for (int i = end; i >= begin; --i)
                ans[cnt++] = matrix[i][sum-i];
        }

        ++sum;
    }
    return ans;
}

int main()
{
    vector<int> tmp(3, 1);
    vector<vector<int> > in(2, tmp);
    printZMatrix(in);

    return 0;
}
