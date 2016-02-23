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
