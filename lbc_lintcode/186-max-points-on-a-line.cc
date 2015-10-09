/*
题目：13 % 最多有多少个点在一条直线上 中等

题目大意：
给定一组二维的数组点，问最多有多少个点在一条直线上

解题思路：
遍历所有的点，找跟该点的斜率相同的点进行计算。

遇到的问题：
没有问题。
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
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        // Write your code here
        int ret = 0;
        for (int i = 0; i < points.size(); ++i) {
            int same = 1;
            int zero = 0;
            unordered_map<float, int> um;
            for (int j = 0; j < points.size(); ++j) {
                if (j == i) continue;
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    same++;
                } else if (points[j].x == points[i].x) {
                    zero++;
                    if (zero + same > ret) {
                        ret = zero + same;
                    }
                } else {
                    float slope = (float)(points[j].y-points[i].y)/(points[j].x-points[i].x);
                    um[slope]++;
                    if (um[slope] + same > ret) {
                        ret = um[slope] + same;
                    }
                }
            }
            if (same > ret) {
                ret = same;
            }
        }
        return ret;
    }
};
