#include <iostream>
#include <climits>
#include <vector>

using namespace std;

/**
 * Problem: longest increasing continuous subsequence
 * Solve: dfs + dp
 * Tips: we need not use the vector:use to label the path in every traversal, becasue
 *       for every point, we need and only need visit once
 */
int dfs(vector<vector<int> > &A, vector<vector<int> > &max_len, int i, int j, int last) {
    if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size() ||  A[i][j] <= last) return 0;
    if (max_len[i][j] != 1) return max_len[i][j];

    int ans = 0;
    ans = max(ans, dfs(A, max_len, i+1, j, A[i][j]));
    ans = max(ans, dfs(A, max_len, i-1, j, A[i][j]));
    ans = max(ans, dfs(A, max_len, i, j+1, A[i][j]));
    ans = max(ans, dfs(A, max_len, i, j-1, A[i][j]));

    return max_len[i][j] = ans+1;
}

/**
 ** @param A an integer matrix
 ** @return  an integer
 **/
int longestIncreasingContinuousSubsequenceII(vector<vector<int> >& A) {
    if (A.size() == 0) return 0;

    vector<vector<int> > max_len(A.size(), vector<int>(A[0].size(), 1));
    int ans = 0;
    for (int i = 0; i < A.size(); ++i) {
        for (int j =0; j < A[0].size(); ++j) {
            ans = max(ans, dfs(A, max_len, i, j, INT_MIN));
        }
    }
    return ans;
}

int main()
{

}
