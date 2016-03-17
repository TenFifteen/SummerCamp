/*
题目大意：
给定一个无向图，克隆一个该图。

解题思路：
BFS

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
        if (node == NULL) return NULL;
        
        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
        
        unordered_map<int, UndirectedGraphNode*> hash;
        hash[node->label] = ret;
        
        queue<UndirectedGraphNode *> q;
        q.push(node);
        
        unordered_set<int> visited;
        visited.insert(node->label);
        
        while (q.size() > 0) {
            auto cur = q.front(); q.pop();
            for (auto x : cur->neighbors) {
                
                if (hash.find(x->label) == hash.end()) {
                    hash[x->label] = new UndirectedGraphNode(x->label);
                }
                
                hash[cur->label]->neighbors.push_back(hash[x->label]);
                
                if (visited.find(x->label) == visited.end()) {
                    visited.insert(x->label);
                    q.push(x);
                }
            }
        }
        
        return ret;
    }
};