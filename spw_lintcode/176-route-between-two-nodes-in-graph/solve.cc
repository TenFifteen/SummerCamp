/**
 * Problem: Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
 * Solve: bfs, used vector
 * Tips: no
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
         * @param s: the starting Directed graph node
         * @param t: the terminal Directed graph node
         * @return: a boolean value
         */
        bool hasRoute(vector<DirectedGraphNode*> graph,
                DirectedGraphNode* s, DirectedGraphNode* t) {
            if (s == t) return true;

            int n = graph.size();

            unordered_map<DirectedGraphNode*, bool> used;
            for (DirectedGraphNode* it : graph) {
                used[it] = false;
            }

            queue<DirectedGraphNode*> q;
            q.push(s);
            while (!q.empty()) {
                DirectedGraphNode* now = q.front();
                q.pop();
                used[now] = true;

                for (DirectedGraphNode* it : now->neighbors) {
                    if (!used[it]) {
                        if (it == t) return true;
                        q.push(it);
                    }

                }
            }

            return false;
        }
};


