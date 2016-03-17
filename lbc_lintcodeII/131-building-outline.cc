/*
题目大意：
给定一些大楼的地理位置和高度，求出所有大楼的轮廓。

解题思路：
将大楼的左右边界作为line进行排序，然后从左往右处理各个边界。

遇到的问题：
一开始漏掉了一个条件。就是if (heights.size() == 0 || *heights.rbegin() < l.second)的第一个条件。
*/
class Solution {
    typedef pair<int, int> Edge;
    
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        vector<Edge> lines;
        for (auto b : buildings) {
            lines.push_back(make_pair(b[0], -b[2]));
            lines.push_back(make_pair(b[1], b[2]));
        }
        
        sort(lines.begin(), lines.end());
        
        vector<vector<int>> ans; 
        multiset<int> heights;
        int last = -1;
        for (auto l : lines) {
            if (l.second < 0) {
                if (heights.size() > 0 && *heights.rbegin() < -l.second) {
                    vector<int> tmp(3);
                    tmp[0] = last;
                    tmp[1] = l.first;
                    tmp[2] = *heights.rbegin();
                    ans.push_back(tmp);
                    
                    last = l.first;
                } else {
                    if (heights.size() == 0) last = l.first;
                }
                heights.insert(-l.second);
            } else {
                heights.erase(heights.find(l.second));
                if (heights.size() == 0 || *heights.rbegin() < l.second) {
                    vector<int> tmp(3);
                    tmp[0] = last;
                    tmp[1] = l.first;
                    tmp[2] = l.second;
                    ans.push_back(tmp);
                    
                    last = l.first;
                }
            }
        }
        
        return ans;
    }
};