/*
题目大意：
给定一个节点总数n，一些边，问这个图是否是树？

解题思路：
BFS

遇到的问题：
一开始还以为直接判断是不是所有点都有边连接到就行呢。忘记了可以形成多个子图的情形了。
*/
class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        if (edges.size() != n-1) return false;
        
        unordered_map<int, vector<int>> hash;
        for (auto e : edges) {
            hash[e[0]].push_back(e[1]);
            hash[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        
        while (q.size() > 0) {
            int cur = q.front(); q.pop();
            for (auto x : hash[cur]) {
                if (visited[x] == false) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        
        for (int i = 0; i < n; ++i) if (visited[i] == false) return false;
        return true;
    }
};