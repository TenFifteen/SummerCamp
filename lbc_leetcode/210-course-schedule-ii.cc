/*
题目大意：
跟207一样，如果满足条件，返回一个拓扑排序

解题思路：
跟207一样，拓扑排序

遇到的问题：
我越发的觉得207有简单一点的方法了。

再次阅读：
这次必须是拓扑排序了。
这次贴一个复杂度稍微低一点点的拓扑排序，主要是zeros数组的利用。
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        queue<int> zeros;
        for (int i = 0; i < numCourses; i++)
            if (!degrees[i]) zeros.push(i);
        vector<int> toposort;
        for (int i = 0; i < numCourses; i++) {
            if (zeros.empty()) return {};
            int zero = zeros.front();
            zeros.pop();
            toposort.push_back(zero);
            for (int neigh : graph[zero]) {
                if (!--degrees[neigh])
                    zeros.push(neigh);
            }
        }
        return toposort;
    }
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, int> cons;
        vector<int> ret;
        for(int i = 0; i < numCourses; ++i){
            cons[i] = 0;
        }
        vector<vector<int>> edges(numCourses);
        for(auto p:prerequisites){
            cons[p.first]++;
            edges[p.second].push_back(p.first);
        }
        for(int i = 0; i < numCourses; ++i){
            bool ok = false;
            for(auto c:cons){
                if(c.second == 0){
                    ok = true;
                    for(auto e:edges[c.first]){
                        cons[e]--;
                    }
                    ret.push_back(c.first);
                    cons.erase(c.first);
                    break;
                }
            }
            if(!ok)return vector<int>();
        }
        return ret;
    }
};
/*
第二次做：
拓扑排序，没有太大问题。
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        vector<int> ans;
        vector<int> pres(numCourses, 0);

        for (auto p : prerequisites) {
            m[p.second].push_back(p.first);
            pres[p.first]++;
        }
        for (int i = 0; i < numCourses; ++i) {
            if (pres[i] == 0) {
                ans.push_back(i);
            }
        }

        int index = 0;
        while (index < ans.size()) {
            for (auto p : m[ans[index]]) {
                pres[p]--;
                if (pres[p] == 0) ans.push_back(p);
            }
            index++;
        }

        if (ans.size() == numCourses) return ans;
        return vector<int>();
    }
};
/*
 * ok
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> edges(numCourses);
        vector<int> degree(numCourses);
        for (auto p : prerequisites) {
            edges[p.second].push_back(p.first);
            degree[p.first]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (degree[i] == 0) q.push(i);
        }

        while (q.size() > 0) {
            int cur = q.front(); q.pop();
            ans.push_back(cur);
            for (auto e : edges[cur]) {
                degree[e]--;
                if (degree[e] == 0) q.push(e);
            }
        }

        if (ans.size() == numCourses) return ans;
        return vector<int>();
    }
};
