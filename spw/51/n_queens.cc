#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool can_place(int loc[], int row, int col)
{
	for (int i = 0; i < row; ++i) {
		if (loc[i] == col || fabs(loc[i]-col) == fabs(i-row)) {
			return false;
		}
	}
	return true;
}

void dfs(vector<vector<string> > &ans, vector<string> now, int row, int n, int loc[])
{
	if (row == n) {
		ans.push_back(now);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (can_place(loc, row, i)) {
			loc[row] = i;
			string line(n, '.');
			line[i] = 'Q';
			now.push_back(line);
			dfs(ans, now, row+1, n, loc);
			// !! must pop, but the loc needn't be cleared
			now.pop_back();
		}	
	}
}

/**
 * Problem: n queens
 * Solve: backtrace
 * Tips: see above
 */
vector<vector<string> > solveNQueens(int n) 
{
	int *loc = new int[n];
	vector<vector<string> > ans;
	if (n == 0) return ans;

	vector<string> now;
	dfs(ans, now, 0, n, loc);

	return ans;
}

int main()
{
	int n;
	while (~scanf("%d", &n)) {
		vector<vector<string> > ans = solveNQueens(n);
		cout << "The " << n << " Queens is:" << endl;
		for (int i = 0; i < ans.size(); ++i) {
			for (int j = 0; j < ans[i].size(); ++j) {
				cout << ans[i][j] << endl;
			}
			cout << endl;
		}
	}

	return 0;
}	
