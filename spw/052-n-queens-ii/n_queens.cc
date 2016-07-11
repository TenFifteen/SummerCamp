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

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> pos(n);
        int ans = 0;

        dfs(ans, pos, 0, n);

        return ans;
    }

    void dfs(int &ans, vector<int> &pos, int row, int n) {
        if (row == n) {
            ++ans;
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (canPlace(pos, row, i)) {
                pos[row] = i;
                dfs(ans, pos, row+1, n);
            }
        }
    }

    bool canPlace(vector<int> &pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (pos[i] == col || abs(row-i) == abs(col-pos[i]))
                return false;
        }

        return true;
    }
};
