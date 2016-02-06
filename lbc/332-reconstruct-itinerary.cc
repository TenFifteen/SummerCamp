/*
题目大意：
给定一些机票，表示从一个城市到另一个城市。
找到一个合理的顺序，使得所有的机票正好可以全部用完。这个人每次都从“JFK”开始旅行，
而且题目所给的条件肯定有解；如果有多种可能的解，则给出字典序最小的那个解。

解题思路：
DFS

遇到的问题：
一开始没有理解题意，以为就是字典序最小就行呢，结果发现不是这样子的，首先是要满足
可以用完所有的机票才行。不过后来调试这个程序也是费了一点劲。。。就是
if (um[cur].size() == 0 || (last != "" && um[cur].upper_bound(last) == um[cur].end()))
这句条件中的第二个条件一开始没有想到，所以总是RE

再次阅读：
感觉这样子写基本已经听好了。还有一种写法就是递归的写法，不过迭代肯定是比递归好的。
*/
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string> > um;
        for (auto p : tickets) {
            um[p.first].insert(p.second);
        }
        
        vector<string> ans;
        ans.push_back("JFK");
        string last = "";
        while (ans.size() < tickets.size()+1) {
            string cur = ans.back();
            
            if (um[cur].size() == 0 || (last != "" && um[cur].upper_bound(last) == um[cur].end())) {
                last = cur;
                ans.pop_back();
                um[ans.back()].insert(last);
                continue;
            }
            
            string next = (last == "" ? *um[cur].begin() : *um[cur].upper_bound(last));
            um[cur].erase(um[cur].find(next));
            ans.push_back(next);
            last = "";
        }
        
        return ans;
    }
};