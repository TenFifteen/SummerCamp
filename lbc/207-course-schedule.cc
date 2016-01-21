/*
题目大意：
给定一组课程，和一些先修限制，问是否可以完成所有课程。

解题思路：
拓扑排序

遇到的问题：
没有问题
但是会不会有比这种方式更简单的方式呢

再次阅读：
首先，看一个比较正规的BFS拓扑排序的方式：
bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<unordered_set<int>> matrix(numCourses); // save this directed graph
    for(int i = 0; i < prerequisites.size(); ++ i)
        matrix[prerequisites[i][1]].insert(prerequisites[i][0]);

    vector<int> d(numCourses, 0); // in-degree
    for(int i = 0; i < numCourses; ++ i)
        for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
            ++ d[*it];

    for(int j = 0, i; j < numCourses; ++ j)
    {
        for(i = 0; i < numCourses && d[i] != 0; ++ i); // find a node whose in-degree is 0

        if(i == numCourses) // if not find
            return false;

        d[i] = -1;
        for(auto it = matrix[i].begin(); it != matrix[i].end(); ++ it)
            -- d[*it];
    }

    return true;
}
然后，还有一种思路是，利用BFS找环：
bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<unordered_set<int>> matrix(numCourses); // save this directed graph
    for(int i = 0; i < prerequisites.size(); ++ i)
        matrix[prerequisites[i][1]].insert(prerequisites[i][0]);

    unordered_set<int> visited;
    vector<bool> flag(numCourses, false);
    for(int i = 0; i < numCourses; ++ i)
        if(!flag[i])
            if(DFS(matrix, visited, i, flag))
                return false;
    return true;
}
bool DFS(vector<unordered_set<int>> &matrix, unordered_set<int> &visited, int b, vector<bool> &flag)
{
    flag[b] = true;
    visited.insert(b);
    for(auto it = matrix[b].begin(); it != matrix[b].end(); ++ it)
        if(visited.find(*it) != visited.end() || DFS(matrix, visited, *it, flag))
            return true;
    visited.erase(b);
    return false;
}
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, int> cons;
        for(int i = 0; i < numCourses; ++i){
            cons[i] = 0;
        }
        vector<vector<int>> edges(numCourses);
        for(auto p:prerequisites){
            cons[p.first]++;
            edges[p.second].push_back(p.first);
        }
        for(int i = 0; i < numCourses; ++i){
            bool ok = false;
            for(auto c:cons){
                if(c.second == 0){
                    ok = true;
                    for(auto e:edges[c.first]){
                        cons[e]--;
                    }
                    cons.erase(c.first);
                    break;
                }
            }
            if(!ok)return false;
        }
        return true;
    }
};