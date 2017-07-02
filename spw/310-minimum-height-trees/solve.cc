/**
 * Problem: For a undirected graph with tree characteristics, we can
 *          choose any node as the root. The result graph is then a rooted tree.
 *          Among all possible rooted trees, those with minimum height are called
 *          minimum height trees (MHTs). Given such a graph, write a function to
 *          find all the MHTs and return a list of their root labels.
 * Solve: strip the onion
 * Tips: points <= 2
 */
class Solution {
	public:
		vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
			vector<int> res;
			if (edges.size() != n-1) return res;
			if (n <= 2) {
				for (int i = 0; i < n; ++i) {
					res.push_back(i);
				}
				return res;
			}

			map<int, int> degree;
			vector<vector<int> > adj(n, vector<int>());
			for (auto &e : edges) {
				++degree[e.first];
				++degree[e.second];

				adj[e.first].push_back(e.second);
				adj[e.second].push_back(e.first);
			}

			queue<int> level;
			for (int i = 0; i < n; ++i)
				if (degree[i] == 1)
					level.push(i);

			while (true) {
				queue<int> nextlevel;

				while (!level.empty()) {
					int now = level.front();
					level.pop();
					degree.erase(now);

					for (int v : adj[now])
						if (degree.count(v) && --degree[v] == 1)
							nextlevel.push(v);
				}

				if (degree.size() <= 2) {
					for (auto &kv : degree)
						res.push_back(kv.first);
					break;
				}

				level = nextlevel;
			}

			return res;
		}
};
