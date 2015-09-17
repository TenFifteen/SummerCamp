/*
题目：25 % 拓扑排序 中等

题目大意：
给定一个有向图，进行拓扑排序。

解题思路：
直接做

遇到的问题：
感觉自己做的好像有点啰嗦，不知道最简洁的做法是啥？
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
        unordered_map<DirectedGraphNode *, int> cnt;
        for (auto g : graph) {
            for (auto n : g->neighbors) {
                cnt[n]++;
            }
            if (cnt.find(g) == cnt.end()) {
                cnt[g] = 0;
            }
        }
        vector<DirectedGraphNode *> ret;
        for (int i = 0; i < graph.size(); ++i) {
            for (auto c : cnt) {
                if (c.second == 0) {
                    ret.push_back(c.first);
                    for (auto f : c.first->neighbors) {
                        cnt[f]--;
                    }
                    cnt.erase(c.first);
                    break;
                }
            }
        }
        return ret;
    }
};
