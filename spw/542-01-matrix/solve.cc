/**
 * Problem: Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
 *          The distance between two adjacent cells is 1.
 * Solve: bfs
 * Tips: no
 */
class Solution {
	public:
		vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
			vector<vector<int>> tmp;
			int m = matrix.size();
			if (m == 0) return tmp;

			int n = matrix[0].size();
			vector<vector<int>> dis(m, vector<int>(n));
			queue<pair<int, int>> points;

			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if (matrix[i][j] == 0) {
						points.push(make_pair(i, j));
						dis[i][j] = 0;
					} else {
						dis[i][j] = -1;
					}
				}
			}

			static int dx[] = {0, 1, 0, -1};
			static int dy[] = {1, 0, -1, 0};

			while (!points.empty()) {
				auto now = points.front();
				int d = dis[now.first][now.second];

				for (int k = 0; k < 4; ++k) {
					int ti = now.first + dy[k];
					int tj = now.second + dx[k];

					if (ti >= 0 && ti < m && tj >= 0 && tj < n && dis[ti][tj] == -1) {
						points.push(make_pair(ti, tj));
						dis[ti][tj] = d + 1;
					}
				}

				points.pop();
			}

			return dis;
		}
};
