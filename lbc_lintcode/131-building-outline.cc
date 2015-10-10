/*
题目：11 % 大楼轮廓 困难

题目大意：
给定一堆大楼的坐标和高度，将其转化为肉眼看到的轮廓

解题思路：
将大楼的左右边拆开进行排序。
然后依次从左往右处理各条边。
最后记得要将相邻的相连的高度相同的结果合并。。。。

遇到的问题：
这题还是有点难度的。
*/
class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        vector<line> vl;
        for (auto b : buildings) {
            vl.emplace_back(b[0], -b[2]);
            vl.emplace_back(b[1], b[2]);
            vl[vl.size()-1].y = b[0];
        }
        sort(vl.begin(), vl.end());
        vector<vector<int>> ans;
        
        multiset<node> ms;
        int last = -1;
        for (auto l : vl) {
            if (l.h < 0) {
                if (!ms.empty() && ms.rbegin()->height < -l.h) {
                    vector<int> tmp(3);
                    tmp[0] = ms.rbegin()->x > last ? ms.rbegin()->x : last;
                    tmp[1] = l.x;
                    tmp[2] = ms.rbegin()->height;
                    ans.push_back(tmp);
                    last = tmp[1];
                }
                ms.emplace(-l.h, l.x);
            } else {
                if (ms.rbegin()->height == l.h) {
                    vector<int> tmp(3);
                    tmp[0] = ms.rbegin()->x > last ? ms.rbegin()->x : last;
                    tmp[1] = l.x;
                    tmp[2] = l.h;
                    ans.push_back(tmp);
                    last = tmp[1];
                }
                node tmp(l.h, l.y);
                ms.erase(ms.find(tmp));
            }
        }
        vector<vector<int>> ret;
        for (auto a : ans) {
            if (ret.empty() || ret[ret.size()-1][2] != a[2] ||
                ret[ret.size()-1][1] < a[0]) {
                ret.push_back(a);
            } else {
                ret[ret.size()-1][1] = a[1];
            }
        }
        return ret;
    }
    
private:
    struct line {
        int x, y, h;
        line(int x, int h) {
            this->x = x;
            this->h = h;
        }
        bool operator< (const line &l) const {
            if (x < l.x) return true;
            if (x > l.x) return false;
            return h < l.h;
        }
    };
    
    struct node {
        int height, x;
        bool operator< (const node & n) const {
            if (height < n.height) return true;
            if (height > n.height) return false;
            return x > n.x;
        }
        node(int h, int x) {
            this->height = h;
            this->x = x;
        }
    };
};
