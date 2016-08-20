/**
 * Problem: Give out an topology sort.
 * Solve: Use an array of in degree and edges.
 *        BFS
 * Tips: 1. Key word 'auto' is really useful.
 *       2. Note the dependency.
 *       3. Return empty vector when the topology does not exist.
 */
class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
            vector<set<int>> edges(numCourses, set<int>());
            vector<int> indegree(numCourses, 0);

            for (auto e : prerequisites) {
                if(edges[e.second].find(e.first) == edges[e.second].end())
                    indegree[e.first]++;
                edges[e.second].insert(e.first);
            }

            queue<int> pre;
            vector<int> ans;
            for (int i = 0; i < numCourses; ++i) {
                if (indegree[i] == 0) {
                    pre.push(i);
                    ans.push_back(i);
                }
            }

            while (!pre.empty()) {
                int i = pre.front();
                pre.pop();

                for (auto c : edges[i]) {
                    if (--indegree[c] == 0) {
                        pre.push(c);
                        ans.push_back(c);
                    }
                }
            }

            if (ans.size() != numCourses) ans.clear();
            return ans;
        }
};


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;

        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);

        set<pair<int, int>> dict;
        for (auto edge : prerequisites) {
            if (dict.find(edge) != dict.end()) continue;

            adj[edge.second].push_back(edge.first);
            indegree[edge.first]++;
        }

        queue<int> q;
        for (int i = 0; i < indegree.size(); ++i)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty()) {
            int now = q.front();
            q.pop();
            ans.push_back(now);

            for (int next : adj[now])
                if (--indegree[next] == 0)
                    q.push(next);
        }

        if (ans.size() != numCourses)
            ans.clear();

        return ans;
    }
};
