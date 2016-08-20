/*
题目大意：
给定一个无向图，复制一个一样的无向图。

解题思路：
递归。不过要对已经创建的node和已经访问的node进行缓存。

遇到的问题：
代码比较绕。一开始忘了将root加入到buf了。

再次阅读：
感觉之前的做法思路没啥问题，但是需要保存一个visited和一个buf稍微有点多。
看到DISCUSS中有一个只需要保存一个的方法，感觉还是挺厉害的：这样就简洁多了。
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
       if (!node) return node;
       if(hash.find(node) == hash.end()) {
           hash[node] = new UndirectedGraphNode(node -> label);
           for (auto x : node -> neighbors) {
                (hash[node] -> neighbors).push_back( cloneGraph(x) );
           }
       }
       return hash[node];
    }
};
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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int, UndirectedGraphNode*> buf;
        map<int, bool> visited;
        if(node == NULL)return NULL;
        UndirectedGraphNode *cur = new UndirectedGraphNode(node->label);
        buf[cur->label] = cur;
        sub(node, buf, visited, cur);
        return cur;
    }

    void sub(UndirectedGraphNode *root, map<int, UndirectedGraphNode *> &buf, map<int, bool> &visited, UndirectedGraphNode *cur){
        visited[root->label] = true;
        for(int i = 0; i < root->neighbors.size(); ++i){
            if(buf.count(root->neighbors[i]->label) == 0){
                cur->neighbors.push_back(new UndirectedGraphNode(root->neighbors[i]->label));
                buf[root->neighbors[i]->label] = cur->neighbors[cur->neighbors.size()-1];
            }else{
                cur->neighbors.push_back(buf[root->neighbors[i]->label]);
            }
        }
        for(int i = 0; i < root->neighbors.size(); ++i){
            if(visited.count(root->neighbors[i]->label) == 0){
                sub(root->neighbors[i], buf, visited, cur->neighbors[i]);
            }
        }
    }
};
/*
第二次做：
就是一个搜索，不过代码写起来比较费劲而已。
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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;

        UndirectedGraphNode *root = new UndirectedGraphNode(node->label);

        unordered_map<int, UndirectedGraphNode *> buf;
        buf[root->label] = root;

        queue<UndirectedGraphNode *> q;
        q.push(node);

        while (q.size()) {
            auto cur = q.front(); q.pop();
            auto now = buf[cur->label];
            for (auto n : cur->neighbors) {
                if (buf.find(n->label) == buf.end()) {
                    buf[n->label] = new UndirectedGraphNode(n->label);
                    q.push(n);
                }
                now->neighbors.push_back(buf[n->label]);
            }
        }

        return root;
    }
};
/*
 * it's ok
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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return node;

        unordered_map<int, UndirectedGraphNode *> um;
        queue<UndirectedGraphNode *> q;
        unordered_set<int> visited;

        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);

        q.push(node);
        um[ret->label] = ret;
        visited.insert(ret->label);

        while (q.size() > 0) {
            UndirectedGraphNode *cur = q.front(); q.pop();
            for (auto n : cur->neighbors) {
                if (visited.find(n->label) == visited.end()) {
                    q.push(n);
                    visited.insert(n->label);
                }
                if (um.find(n->label) == um.end()) um[n->label] = new UndirectedGraphNode(n->label);
                um[cur->label]->neighbors.push_back(um[n->label]);
            }
        }

        return ret;
    }
};
