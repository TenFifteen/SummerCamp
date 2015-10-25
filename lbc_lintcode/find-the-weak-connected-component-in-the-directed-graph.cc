/*
题目：19 % 找出有向图中的弱联通分量 中等

题目大意：
给定一个有向图，问其中有哪些弱连通分量

解题思路：
先将其转化成无向图，然后进行搜索

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
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
        toUndirected(nodes);
        vector<vector<int>> ans;
        unordered_set<int> flag;
        for (auto n : nodes) {
            if (flag.find(n->label) == flag.end()) {
                vector<int> cur;
                sub(flag, n, cur);
                sort(cur.begin(), cur.end());
                ans.push_back(cur);
            }
        }
        return ans;
    }
    
    void sub(unordered_set<int> &flag, DirectedGraphNode *node, vector<int> &cur) {
        cur.push_back(node->label);
        flag.insert(node->label);
        for (auto n : node->neighbors) {
            if (flag.find(n->label) == flag.end()) {
                sub(flag, n, cur);
            }
        }
    }
    
    void toUndirected(vector<DirectedGraphNode *> &nodes) {
        for (auto n : nodes) {
            for (auto m : n->neighbors) {
                bool find = false;
                for (auto x : m->neighbors) {
                    if (x == n) {
                        find = true;
                        break;
                    }
                }
                if (find == false) {
                    m->neighbors.push_back(n);
                }
            }
        }
    }
};
