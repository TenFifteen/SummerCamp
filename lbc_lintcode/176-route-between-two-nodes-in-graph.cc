/*
题目：36 % 图中两个点之间的路线 中等

题目大意：
给定一个有向图，给定两个节点，问是否存在a到b的路径。

解题思路：
深搜

遇到的问题：
没有问题。
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
        unordered_set<int> flag;
        queue<DirectedGraphNode *> q;
        q.push(s);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur == t) return true;
            if (flag.find(cur->label) != flag.end()) continue;
            flag.insert(cur->label);
            for (auto n : cur->neighbors) {
                if (flag.find(n->label) != flag.end()) continue;
                q.push(n);
            }
        }
        return false;
    }
};


