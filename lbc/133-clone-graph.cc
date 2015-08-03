/*
题目大意：
给定一个无向图，复制一个一样的无向图。

解题思路：
递归。不过要对已经创建的node和已经访问的node进行缓存。

遇到的问题：
代码比较绕。一开始忘了将root加入到buf了。
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