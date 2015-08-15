/*
题目大意：
跟207一样，如果满足条件，返回一个拓扑排序

解题思路：
跟207一样，拓扑排序

遇到的问题：
我越发的觉得207有简单一点的方法了。
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, int> cons;
        vector<int> ret;
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
                    ret.push_back(c.first);
                    cons.erase(c.first);
                    break;
                }
            }
            if(!ok)return vector<int>();
        }
        return ret;
    }
};