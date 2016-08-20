#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int x, int y) {
	grid[x][y] = '0';

	if (x+1 < grid.size() && grid[x+1][y] == '1') dfs(grid, x+1, y);
	if (x-1 >= 0 && grid[x-1][y] == '1') dfs(grid, x-1, y);
	if (y+1 < grid[0].size() && grid[x][y+1] == '1') dfs(grid, x, y+1);
	if (y-1 >= 0 && grid[x][y-1] == '1') dfs(grid, x, y-1);
}

/**
 * Problem: given a 2d grid map of 0(water) and 1(island), count the island which is formed by 1s which
 *          can only adjacent horizontally or vertically.
 * Solve: dfs
 * Tips: use grid as the used map.
 */
int numIslands(vector<vector<char>>& grid) {
	if (grid.size() == 0) return 0;

	int m = grid.size(), n = grid[0].size();
	int count = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (grid[i][j] == '1') {
				++count;
				dfs(grid, i, j);
			}
		}
	}

	return count;
}

int main()
{
	int m, n;
	while (~scanf("%d %d", &m, &n)) {
		getchar();
		vector<vector<char> > grid(m, vector<char>(n, '0'));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int temp;
				temp = getchar();
				grid[i][j] = temp;
				printf("%c ", temp);
			}
			getchar();
			printf("\n");
		}

		printf("The islands is %d\n", numIslands(grid));
	}

	return 0;
}


class Solution {
    void clear(vector<vector<char>> &grid, int m, int n, int y, int x) {
        if (y < 0 || y >= m || x < 0 || x >= n || grid[y][x] == '0') return;

        static int dx[] = {1, 0, -1, 0};
        static int dy[] = {0, -1, 0, 1};

        grid[y][x] = '0';
        for (int i = 0; i < 4; ++i) {
            clear(grid, m, n, y+dy[i], x+dx[i]);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;

        int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    cnt++;
                    clear(grid, m, n, i, j);
                }
            }
        }

        return cnt;
    }
};
