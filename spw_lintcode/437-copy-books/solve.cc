#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * @param pages: a vector of integers
 * @param k: an integer
 * @return: an integer
 */
int copyBooks(vector<int> &pages, int k) {
    int n = pages.size();
    if (n == 1) return pages[0];
    vector<vector<int> > dp(k, vector<int>(n, INT_MAX));

    // more person than books
    int ans = 0;
    if (k >= n) {
        for (int i = 0; i < n; ++i) ans = max(ans, pages[i]);
        return ans;
    }

    // only one person
    dp[0][0] = pages[0];
    for (int i = 1; i < n; ++i) {
        dp[0][i] = pages[i] + dp[0][i-1];
    }

    for (int i = 1; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = pages[j];
            int l = j - 1;

            // init
            if (j == 0) dp[i][j] = pages[0];
            else dp[i][j] =  max(sum, dp[i-1][l]);

            // else
            while (l >= 0 && dp[i-1][l] > sum) {
                dp[i][j] = min(dp[i][j], max(sum, dp[i-1][l]));
                sum += pages[l];
                --l;
            }
        }
    }

    return dp[k-1][n-1];
}

int main()
{
    int a[] = {13,999,1,2,3,9,11};
    vector<int> pages(a, a+7);
    cout << copyBooks(pages, 2) << endl;

    return 0;
}
