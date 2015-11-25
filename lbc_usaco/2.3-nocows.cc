/*
ID: libench1
PROG: nocows
LANG: C++11
*/
/*
这道题目我感觉题意描述有问题。
一开始当做了可以有多条树了。感觉好难。
不过看了别人的饿解法之后，感觉的确是挺厉害的。
用dp[i][j]表示在i个牛，最高位j的树的时候的情况。
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");

    int n, k;
    fin >> n >> k;
    vector<vector<int> > dp(n+1, vector<int>(k+1, 0));
    for (int i = 1; i <= k; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 3; i <= n; i+=2) {
        for (int j = 2; j <= k; ++j) {
            for (int k = 1; k+2 <= i; k+=2) {
                dp[i][j] += dp[k][j-1]*dp[i-k-1][j-1];
                dp[i][j] %= 9901;
            }
        }
    }

    fout << (dp[n][k]-dp[n][k-1]+9901)%9901 << endl;
    return 0;
}
