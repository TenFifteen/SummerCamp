/**
 * Problem: Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 * Solve: dfs+map
 * Tips: no
 */
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    public:
        /**
         * @param node: A undirected graph node
         * @return: A undirected graph node
         */
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            unordered_map<int, UndirectedGraphNode *> nodes;

            return dfs(node, nodes);
        }

        UndirectedGraphNode * dfs(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *> &nodes) {
            if (node == NULL) return NULL;

            UndirectedGraphNode *now = new UndirectedGraphNode(node->label);
            nodes[node->label] = now;

            for (UndirectedGraphNode *tn : node->neighbors) {
                if (nodes.find(tn->label) == nodes.end()) {
                    now->neighbors.push_back(dfs(tn, nodes));
                } else {
                    now->neighbors.push_back(nodes[tn->label]);
                }
            }

            return now;
        }
};
