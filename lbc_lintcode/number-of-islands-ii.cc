/*
题目：12 % 岛屿的个数II 困难

题目大意：
给定一个二维的大海，然后每次变化一个点为岛屿。问每次变化完之后当前有多少个岛屿。

解题思路：
并查集。

遇到的问题：
一开始将题目看错了。以为一个点可以从海洋变成陆地，陆地也可以编程海洋呢！
要不然一开始就可以直接用并查集写了。
*/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        // Write your code here
        unordered_map<int, int> fa;
        vector<pair<int,int>> index;
        index.push_back(make_pair(-1, 0));
        index.push_back(make_pair(1, 0));
        index.push_back(make_pair(0, -1));
        index.push_back(make_pair(0, 1));
        vector<int> ans(operators.size());
        int total = 0;
        for (int i = 0; i < operators.size(); ++i) {
            int p = operators[i].x * m + operators[i].y;
            int fp = findParent(fa, p);
            total++;
            for (auto d : index) {
                int xx = operators[i].x + d.first;
                int yy = operators[i].y + d.second;
                if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
                int np = xx * m + yy;
                if (fa.find(np) != fa.end()) {
                    int nfp = findParent(fa, np);
                    if (nfp != fp) {
                        total--;
                        fa[nfp] = fp;
                    }
                }
            }
            ans[i] = total;
        }
        return ans;
    }
    
    int findParent(unordered_map<int, int> &fa, int key) {
        if (fa.find(key) == fa.end()) {
            fa[key] = key;
            return key;
        }
        if (fa[key] != key) {
            fa[key] = findParent(fa, fa[key]);
        }
        return fa[key];
    }
};
