/*
题目大意：
有向图的搜索。

解题思路：
见代码。BFS

遇到的问题：
没有。
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
        // write your code here
        if (s == NULL || t == NULL) return false;
        
        unordered_set<int> visited;
        queue<DirectedGraphNode *> q;
        q.push(s);
        visited.insert(s->label);
        
        while (q.size() > 0) {
            DirectedGraphNode *cur = q.front();
            q.pop();
            if (cur->label == t->label) return true;
            
            for (auto b : cur->neighbors) {
                if (visited.find(b->label) == visited.end()) {
                    visited.insert(b->label);
                    q.push(b);
                }
            }
        }
        
        return false;
    }
};

