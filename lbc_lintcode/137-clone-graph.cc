/*
题目：25 % 克隆图 中等

题目大意：
给定一个无向图，克隆一份出来

解题思路：
宽搜

遇到的问题：
没有问题。
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
        // write your code here
        if (node == NULL) {
            return NULL;
        }
        queue<UndirectedGraphNode *> q;
        auto ret = new UndirectedGraphNode(node->label);
        unordered_map<int, UndirectedGraphNode *> um;
        um[ret->label] = ret;
        unordered_set<int> visited;
        visited.insert(node->label);
        q.push(node);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (auto n : cur->neighbors) {
                if (visited.find(n->label) == visited.end()) {
                    visited.insert(n->label);
                    q.push(n);
                }
                if (um.find(n->label) == um.end()) {
                    um[n->label] = new UndirectedGraphNode(n->label);
                }
                um[cur->label]->neighbors.push_back(um[n->label]);
            }
        }
        return ret;
    }
};
