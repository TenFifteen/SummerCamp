class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>());

        set<pair<int, int>> edges;
        for (auto edge : prerequisites) {
            if (edges.find(edge) != edges.end()) continue;
            edges.insert(edge);

            adj[edge.second].push_back(edge.first) ;
            inDegree[edge.first]++;
        }

        queue<int> srcs;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0)
                srcs.push(i);
        }

        int cnt = 0;
        while (!srcs.empty()) {
            int now = srcs.front();
            srcs.pop();
            ++cnt;

            for (int next : adj[now]) {
                if (--inDegree[next] == 0)
                    srcs.push(next);
            }
        }

        return cnt == numCourses;
    }
};
