/*
题目：18 % 找出无向图汇总的相连要素 容易

题目大意：
在一个无向图中寻找所有的连通分量 

解题思路：
搜索

遇到的问题：
没有问题。
*/
/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        unordered_set<int> flag;
        vector<vector<int>> ans;
        for (auto n : nodes) {
            if (flag.find(n->label) == flag.end()) {
                vector<int> cur;
                sub(cur, n, flag);
                sort(cur.begin(), cur.end());
                ans.push_back(cur);
            }
        }
        return ans;
    }
    
    void sub(vector<int> &cur, UndirectedGraphNode *head, unordered_set<int> &flag) {
        flag.insert(head->label);
        cur.push_back(head->label);
        for (auto n : head->neighbors) {
            if (flag.find(n->label) == flag.end()) {
                sub(cur, n, flag);
            }
        }
    }
};
