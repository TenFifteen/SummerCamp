/*
题目大意：
拓扑排序。

解题思路：
见代码。

遇到的问题：
长时间不刷题，果然是开始手生了。
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
        // write your code here
        unordered_map<int, int> degree;
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i]->neighbors.size(); ++j) {
                degree[graph[i]->neighbors[j]->label]++;
            }
        }
        
        queue<DirectedGraphNode *> q;
        for (int i = 0; i < graph.size(); ++i) {
            if (degree[graph[i]->label] == 0) q.push(graph[i]);
        }
        
        vector<DirectedGraphNode *> ans;
        while (q.size() > 0) {
            DirectedGraphNode *cur = q.front();
            q.pop();
            
            ans.push_back(cur);
            
            for (int i = 0; i < cur->neighbors.size(); ++i) {
                int next = cur->neighbors[i]->label;
                degree[next]--;
                if (degree[next] == 0) {
                    q.push(cur->neighbors[i]);
                }
            }
        }
        
        return ans;
    }
};
