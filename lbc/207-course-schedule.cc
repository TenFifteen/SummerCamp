/*
题目大意：
给定一组课程，和一些先修限制，问是否可以完成所有课程。

解题思路：
拓扑排序

遇到的问题：
没有问题
但是会不会有比这种方式更简单的方式呢
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