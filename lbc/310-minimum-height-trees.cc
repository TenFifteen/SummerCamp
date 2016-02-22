/*
题目大意：
给定一棵生成树，如果指定其中一个节点为root的话，会形成一棵树。
其中树的深度最小的树叫做MHT，问有哪些节点为root时可以使得树为MHT。

解题思路：
一开始的思路非常简单，就是对每个节点都做一次BFS，然后看一下深度。结果就是超时，怎么优化都是超时。
然后看了一下别人的思路，意思是说，一棵树，如果把所有的叶节点去掉之后，不影响找root。
然后一层一层去掉叶节点之后，最后剩下的一个或者两个节点就是这样一个root。

遇到的问题：
还是没想出来算法，最后是借鉴的别人的。

再次阅读：
看了下DISCUSS，既然我的思路都是借鉴的别人的，其实本来没啥好看的。但是就是想看看代码，
不过感觉我写的下面这段代码已经算是可以的了。
*/
class Solution {
private:
    int getHeight(int n, int root, vector<vector<int>> &edges, int maxH) {
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(root);
        visited[root] = true;
        int height = 0;
        
        while (q.size() > 0) {
            height++;
            if (height > maxH) return maxH + 1;
            int cur = q.size();
            for (int i = 0; i < cur; ++i) {
                int now = q.front();
                q.pop();
                
                for (auto neighbor : edges[now]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
        return height;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ans;
        if (n < 1) return ans;
        if (n < 3) {
            for (int i = 0; i < n; ++i) {
                ans.push_back(i);
            }
            return ans;
        }
        
        vector<int> degree(n, 0);
        vector<vector<int> > matrix(n);
        for (auto e : edges) {
            degree[e.first]++;
            degree[e.second]++;
            matrix[e.first].push_back(e.second);
            matrix[e.second].push_back(e.first);
        }
        
        int total = 0;
        queue<int> ones;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                ones.push(i);
                degree[i] = 0;
                total++;
            }
        }
        
        while (n - total > 2) {
            int now = ones.size();
            for (int i = 0; i < now; ++i) {
                int z = ones.front();
                ones.pop();
                
                for (auto e : matrix[z]) {
                    degree[e]--;
                    if (degree[e] == 1) {
                        ones.push(e);
                        degree[e] = 0;
                        total++;
                    }
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (degree[i] > 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    vector<int> findMinHeightTrees2(int n, vector<pair<int, int>>& edges) {
        vector<vector<int> > e(n);
        for (auto p : edges) {
            e[p.first].push_back(p.second);
            e[p.second].push_back(p.first);
        }
        
        int h = n;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int now = getHeight(n, i, e, h);
            if (now < h) {
                h = now;
                ans.clear();
            } else if (now == h) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};