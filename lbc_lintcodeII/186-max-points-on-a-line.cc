/*
题目大意：
给定二维平面上的一些点，问一共最多有多少个点在同一条直线上？

解题思路：
以每个点作为基准点，判断所有的点与之的斜率，找到当前最多的在同一直线上的点。

遇到的问题：
两个，第一个是最后计算hash里面的值的时候忘记了加dup了。
第二个是计算slope的时候忘记了先加强转了，所以变成了int除法了。
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
        if (points.size() < 3) return points.size();
        
        int ans = 1;
        for (int i = 0; i < points.size(); ++i) {
            
            int dup = 0, line = 0;
            unordered_map<double, int> hash;
            for (int j = 0; j < points.size(); ++j) {
                if (points[j].x == points[i].x) {
                    if (points[j].y == points[i].y) dup++;
                    else line++;
                } else {
                    double slope = (double)(points[j].y-points[i].y) / (points[j].x-points[i].x);
                    hash[slope]++;
                }
            }
            
            ans = max(dup+line, ans);
            for (auto p : hash) {
                ans = max(ans, p.second+dup);
            }
        }
        
        return ans;
    }
};