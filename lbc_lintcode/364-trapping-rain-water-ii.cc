/*
题目：19 % 接雨水 II 困难

题目大意：
给定一个二维的矩阵，问如果要用来接雨水。该矩阵可以接多少？

解题思路：
用最小堆+BFS的思路。逐渐的缩小边界

遇到的问题：
重载<需要在将函数声明为const才行。
*/
class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        // write your code here
        if (heights.size() < 2 || heights[0].size() < 2) return 0;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        multiset<cell> ms;
        for (int i = 0; i < n; ++i) {
            ms.emplace(i, 0, heights[i][0]);
            visit[i][0] = true;
            ms.emplace(i, m-1, heights[i][m-1]);
            visit[i][m-1] = true;
        }
        for (int i = 1; i < m-1; ++i) {
            ms.emplace(0, i, heights[0][i]);
            visit[0][i] = true;
            ms.emplace(n-1, i, heights[n-1][i]);
            visit[n-1][i] = true;
        }
        int ret = 0;
        while (ms.size() > 0) {
            auto cur = *ms.begin();
            ms.erase(ms.find(cur));
            if (cur.x > 0 && visit[cur.x-1][cur.y] == false) {
                ms.emplace(cur.x-1, cur.y, max(cur.h, heights[cur.x-1][cur.y]));
                visit[cur.x-1][cur.y] = true;
                ret += max(0, cur.h-heights[cur.x-1][cur.y]);
            }
            if (cur.x < n-1 && visit[cur.x+1][cur.y] == false) {
                ms.emplace(cur.x+1, cur.y, max(cur.h, heights[cur.x+1][cur.y]));
                visit[cur.x+1][cur.y] = true;
                ret += max(0, cur.h-heights[cur.x+1][cur.y]);
            }
            if (cur.y > 0 && visit[cur.x][cur.y-1] == false) {
                ms.emplace(cur.x, cur.y-1, max(cur.h, heights[cur.x][cur.y-1]));
                visit[cur.x][cur.y-1] = true;
                ret += max(0, cur.h-heights[cur.x][cur.y-1]);
            }
            if (cur.y < m-1 && visit[cur.x][cur.y+1] == false) {
                ms.emplace(cur.x, cur.y+1, max(cur.h, heights[cur.x][cur.y+1]));
                visit[cur.x][cur.y+1] = true;
                ret += max(0, cur.h-heights[cur.x][cur.y+1]);
            }
        }
        return ret;
    }
    
private:
    struct cell {
        int x, y, h;
        cell(int xx, int yy, int hh) {
            x = xx;
            y = yy;
            h = hh;
        }
        bool operator< (cell a) const{
            return h < a.h;
        }
    };
};
