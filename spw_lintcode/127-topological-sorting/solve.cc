/**
 * Problem: Given an directed graph, a topological order of the graph nodes is defined as follow:
 *          For each directed edge A -> B in graph, A must before B in the order list.
 *          The first node in the order can be any node in the graph with no nodes direct to it.
 *          Find any topological order for the given graph.
 * Solve: use a in degree vector.
 * Tips: the label is the index of graph vector
 */
/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    public:
        /**
         * @param graph: A list of Directed graph node
         * @return: Any topological order for the given graph.
         */
        vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
            int n = graph.size();

            vector<int> indegree(n, 0);

            for (int i = 0; i < n; ++i) {
                for (DirectedGraphNode* it : graph[i]->neighbors) {
                    indegree[it->label]++;
                }
            }

            queue<int> q;
            for (int i = 0; i < n; ++i)
                if (indegree[i] == 0)
                    q.push(i);

            vector<DirectedGraphNode*> ans;
            while (!q.empty()) {
                int now = q.front();
                ans.push_back(graph[now]);
                q.pop();

                for (DirectedGraphNode* it : graph[now]->neighbors) {
                    if (--indegree[it->label] == 0) {
                        q.push(it->label);
                    }
                }
            }

            return ans;
        }
};
