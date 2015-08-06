/*
题目大意：
给定一个二维平面上的点，问在同一条直线上的点的数量最多是多少

解题思路：
以一个点为中心，计算与之在同一条直线上的点的数量。用斜率来表示。
注意斜率不可计算和重复点两种情况。

遇到的问题：
一开始将重复的点忘了加到其他的数量里了。

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