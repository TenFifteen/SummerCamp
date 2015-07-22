#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int count = 0;
bool can_place(int loc[], int row, int col)
{
	for (int i = 0; i < row; ++i) {
		if (loc[i] == col || fabs(loc[i]-col) == fabs(i-row)) {
			return false;
		}
	}
	return true;
}

void dfs(int row, int n, int loc[])
{
	if (row == n) {
		count++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (can_place(loc, row, i)) {
			loc[row] = i;
			dfs(row+1, n, loc);
		}	
	}
}

/**
 * Problem: n queens
 * Solve: backtrace
 * Tips: see above
 */
int totalNQueens(int n) 
{
	int *loc = new int[n];
	if (n == 0) return 0;
	count = 0;
	dfs(0, n, loc);
	return count; 
}

int main()
{
	int n;
	while (~scanf("%d", &n)) {
		cout << "The count of " << n << " Queens is:" << endl;
		cout << totalNQueens(n) << endl;
	}

	return 0;
}	
