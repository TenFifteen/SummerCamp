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