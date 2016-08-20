/*
题目大意：
给定一个二维平面上的点，问在同一条直线上的点的数量最多是多少

解题思路：
以一个点为中心，计算与之在同一条直线上的点的数量。用斜率来表示。
注意斜率不可计算和重复点两种情况。

遇到的问题：
一开始将重复的点忘了加到其他的数量里了。

再次阅读：
以为这道题会有什么不一样的解法呢。结果看了DISCUSS发现，其实也是一个类似的方法，都是
N*N的时间复杂度。
不过这道题还是要注意一下，就是有各种特殊情况的处理。

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
    int maxPoints(vector<Point>& points) {
        if(points.size() == 0)return 0;
        int ret = 1;
        for(int i = 0; i < points.size(); ++i){
            int now = 1;
            map<double, int> buf;
            int vline = 0;
            int dup = 0;
            for(int j = 0; j < points.size(); ++j){
                if(j == i)continue;
                if(points[j].y == points[i].y && points[j].x == points[i].x){
                    dup++;
                    if(dup+1 > now){
                        now = dup+1;
                    }
                }else if(points[i].x == points[j].x){
                    vline++;
                    if(vline+1+dup > now){
                        now = vline+1+dup;
                    }
                }else{
                    double slope = ((double)(points[i].y-points[j].y))/(points[i].x-points[j].x);
                    buf[slope]++;
                    if(buf[slope]+1+dup > now){
                        now = buf[slope]+1+dup;
                    }
                }
            }
            if(now > ret){
                ret = now;
            }
        }
        return ret;
    }
};
/*
第二次做：
竟然忘记了所有的点都是重复的情况了。
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
    int maxPoints(vector<Point>& points) {
        if (points.size() < 3) return points.size();

        int n = points.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<double, int> um;
            int dup = 0, line = 0;
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                if (points[j].y == points[i].y && points[j].x == points[i].x) dup++;
                else if (points[j].x == points[i].x) line++;
                else {
                    double slope = (double)(points[j].y-points[i].y)/(points[j].x-points[i].x);
                    um[slope]++;
                }
            }

            ans = max(ans, line+1);
            ans = max(ans, dup+1);
            for (auto u : um) {
                ans = max(u.second+1+dup, ans);
            }
        }

        return ans;
    }
};
/*
 * it's ok
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
    int maxPoints(vector<Point>& points) {
        if (points.size() < 2) return points.size();
        int ans = 1, n = points.size();

        for (int i = 0; i < n; ++i) {
            int y = 0, self = 0;
            unordered_map<double, int> um;
            for (int j = 0; j < n; ++j) {
                if (points[j].x == points[i].x) {
                    if (points[j].y == points[i].y) {
                        self++;
                    } else {
                        y++;
                    }
                } else {
                    double slope = points[i].x - points[j].x;
                    slope = (points[i].y - points[j].y) / slope;
                    um[slope]++;

                    ans = max(ans, um[slope]+self);
                }
            }

            ans = max(ans, y+self);
        }

        return ans;
    }
};
